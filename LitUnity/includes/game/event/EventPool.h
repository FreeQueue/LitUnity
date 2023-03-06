#pragma once
#include <deque>
#include <memory>
#include "EventHandler.h"
#include <list>
#include <map>

namespace Game
{
	enum class EventPoolMode
	{
		// 默认事件池模式，即必须存在有且只有一个事件处理函数。
		DEFAULT,

		//允许存在重复的事件处理函数。
		ALLOW_DUPLICATE_HANDLER,
	};


	template <typename... T>
	class EventPool
	{
	public:
		static EventPool<T...> pool;
		using Event = Event<T...>;
		using EventHandler = EventHandler<T...>;
		using EventHandlerPtr = std::weak_ptr<EventHandler>;
		EventPoolMode mode = EventPoolMode::DEFAULT;

		void Fire(const char* name, T... eventArgs);

		void FireNow(const char* name, T... eventArgs);

		void Fire(const Event& event);

		void FireNow(const Event& event);

		void Update();

		void HandleEvent(const Event& event);

		void HandleEvent(size_t id, T... eventArgs);

		bool Subscribe(const char* name, EventHandlerPtr handler);

		bool Unsubscribe(const char* name, EventHandlerPtr handler);

		void UnsubscribeAll(const char* name);

	private:
		std::hash<std::string> h;
		std::map<size_t, std::deque<Event>> m_EventQueueMap;
		std::map<size_t, std::list<EventHandlerPtr>> m_EventHandleListMap;
	};

	template <typename... T>
	void EventPool<T...>::Fire(const char* name, T... eventArgs)
	{
		Fire(Event::Create(name, eventArgs));
	}

	template <typename... T>
	void EventPool<T...>::FireNow(const char* name, T... eventArgs)
	{
		HandleEvent(h(name), Event::Create(name, eventArgs));
	}

	template <typename... T>
	void EventPool<T...>::Fire(const Event& event)
	{
		if (!m_EventQueueMap.contains(event.id))
			m_EventQueueMap.emplace(event.id);
		m_EventQueueMap[event.id].push_back(event);
	}

	template <typename... T>
	void EventPool<T...>::FireNow(const Event& event)
	{
		HandleEvent(event);
	}

	template <typename... T>
	void EventPool<T...>::Update()
	{
		for (auto eventQueue : m_EventQueueMap)
		{
			for (Event event : eventQueue)
			{
				HandleEvent(event);
			}
			eventQueue.clear();
		}
	}

	template <typename... T>
	void EventPool<T...>::HandleEvent(const Event& event)
	{
		if (!m_EventHandleListMap.contains(event.id))return;
		auto iter = m_EventHandleListMap[event.id].begin();

		for (EventHandlerPtr handler : m_EventHandleListMap[event.id])
		{
			if (handler.get() != nullptr && handler->function != nullptr)
				handler->Handle(event);
		}
	}

	template <typename... T>
	void EventPool<T...>::HandleEvent(size_t id, T... eventArgs)
	{
	}

	template <typename... T>
	bool EventPool<T...>::Subscribe(const char* name, EventHandlerPtr handler)
	{
		size_t id = h(name);
		if (!m_EventHandleListMap.contains(id))
			m_EventHandleListMap.emplace(id, std::list<EventHandlerPtr>{});
		if (auto& list = m_EventHandleListMap[id]; mode !=
			EventPoolMode::ALLOW_DUPLICATE_HANDLER &&
			std::find(list.begin(), list.end(), handler) != list.end())
		{
			return false;
		}
		m_EventHandleListMap[id].push_back(handler);
		return true;
	}

	template <typename... T>
	bool EventPool<T...>::Unsubscribe(const char* name, EventHandlerPtr handler)
	{
		size_t id = h(name);
		if (!m_EventQueueMap.contains(id))return false;
		auto iter = m_EventHandleListMap.find(handler);
		if (iter == m_EventHandleListMap.end())return false;
		m_EventHandleListMap[id].erase(iter);
		return true;
	}

	template <typename... T>
	void EventPool<T...>::UnsubscribeAll(const char* name)
	{
		size_t id = h(name);
		m_EventHandleListMap[id].clear();
	}
}
