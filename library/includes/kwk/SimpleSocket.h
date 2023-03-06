#pragma once
#include <WinSock2.h>
#include <functional>
#include <sstream>
#include <map>
#include <mutex>
#include <deque>
#include <vector>

#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

class DLL_API SimpleSocketTool
{
public:
	static WORD Version;
	static int BackLog;
	static int WaitTime;
	static int Init_BufferLen;
public:
	static SOCKET GetSocketTcp();
	static void SetAddr(SOCKADDR_IN& addr, u_long ip, u_short port);
};


enum struct DLL_API LogLevel
{
	None = 0,
	Info = 1,
	Warning = 2,
	Error = 3,
	Fatal = 4,
};

enum struct DLL_API IoType
{
	None = 0,
	Receive = 1,
	Send = 2,
};



//一个Session代表本地和一个外地socket的会话
class DLL_API SocketSession : public std::enable_shared_from_this<SocketSession>
{
public:
	using Buffer = std::vector<char>;
	using SharePtr = std::shared_ptr<SocketSession>;
	using WeakPtr = std::weak_ptr<SocketSession>;
	//using Ptr = WeakPtr; //SocketSession*const;
	using Action = std::function<void(const SharePtr)>;
	using IoAction = std::function<void(const SharePtr, const char* data, int transfered)>;
	using LogAction = std::function<void(const SharePtr, const char* message, LogLevel level)>;

	struct IoContext : WSAOVERLAPPED
	{
		WSABUF buffer;
		DWORD numberOfBytesRecvd;
		DWORD flag = 0;
		IoType type;
		WeakPtr sessionPtr;

		void Clear();
	};
private:
	int m_id;
	SOCKET m_socket;

	Buffer m_currentReceive;
	std::deque<Buffer> m_sendBuffers;

	IoContext m_receiveContext;
	IoContext m_sendContext;

	std::mutex m_mutex;

	Action CloseHandle;
	IoAction ReceiveHandle, SendHandle;
	LogAction LogHandle;
public:
	SocketSession();
	~SocketSession();
	void Init(int id, SOCKET socket);
	inline int GetId() const { return m_id; }
	inline SOCKET GetSocket() const { return m_socket; }

	void SetCloseHandle(Action& closeHandle);
	void SetReceiveHandle(IoAction& receiveHandle);
	void SetSendHandle(IoAction& sendHandle);
	void SetLogHandle(LogAction& errorHandle);

	bool Send(Buffer&& buffer);
	bool Send(const char* str);
	bool Send(const char* str, int len);
	bool TrySendMore();
	bool OnSend(int transfered);
	bool StartReceive();
	bool OnReceive(int transfered);
	void OnClose();
	void Log(const char* message, LogLevel logLevel = LogLevel::Info);
private:
	bool SendFrontBuffer();
};


class DLL_API SimpleSocket
{
public:
	using Action= std::function<void(SimpleSocket&)>;
	using SessionAction = std::function<void(SimpleSocket&, const SocketSession::SharePtr)>;
	using LogAction = std::function<void(SimpleSocket&, const char*, LogLevel)>;
	LogAction LogHandle =
		[](SimpleSocket& server, const char* message, LogLevel level) {
		const auto threadId = std::this_thread::get_id();
		std::stringstream ss;
		ss << "Thread Id[" << threadId << "]:" << message;
		printf("%s\n", ss.str().c_str());
	};
	Action TimeOutHandle = [](SimpleSocket& server) {
		server.Log("TimeOut");
	};
	SessionAction SessionConnectHandle =
		[](SimpleSocket& server, const  SocketSession::SharePtr sessionPtr) {
		sessionPtr->StartReceive();
		server.Log("Session connect");
	};
	SessionAction SessionDisconnectHandle =
		[](SimpleSocket& server, const  SocketSession::SharePtr sessionPtr) {
		server.Log("Session disconnect");
	};
	SocketSession::Action SessionCloseHandle =
		[](const SocketSession::SharePtr sessionPtr) {
		auto threadId = std::this_thread::get_id();
		sessionPtr->Log("Session close");
	};
	SocketSession::IoAction SessionReceiveHandle =
		[](const SocketSession::SharePtr sessionPtr, const char* data, int transfered) {
		sessionPtr->Log(data);
		sessionPtr->Send(data, transfered);
	};
	SocketSession::IoAction SessionSendHandle =
		[](const SocketSession::SharePtr sessionPtr, const char* data, int transfered) {
		std::stringstream ss;
		sessionPtr->Log(data);
	};
	SocketSession::LogAction SessionLogHandle =
		[](const SocketSession::SharePtr sessionPtr, const char* message, LogLevel level) {
		const auto threadId = std::this_thread::get_id();
		std::stringstream ss;
		ss << "Thread Id[" << threadId << "]:" << message;
		printf("%s\n", ss.str().c_str());
	};
private:
	bool m_running;

	sockaddr_in m_addr;
	SOCKET m_socket;
	HANDLE m_completePort;
	int m_workThreadNum;
	std::map<int, SocketSession::SharePtr> m_sessions;
	std::vector<std::shared_ptr<std::thread>> m_threads;
public:
	SimpleSocket();
	~SimpleSocket();
	bool StartAsServer(u_short port, int workThreadNum = 0);
	bool StartAsClient(u_long addr, u_short port, int workThreadNum = 1);
	bool IsRunning() const;
	void Stop();
	void Log(const char* message, LogLevel logLevel = LogLevel::Info);
	std::vector<SocketSession::WeakPtr> GetSessions() const;
private:
	void WaitingForAccept();
	void WaitingForIo();
	void OnConnect(SOCKET acceptSocket);
	void OnDisconnect(const SocketSession::SharePtr& sessionPtr);
	void OnTimeOut();
};

