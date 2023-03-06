#pragma once
namespace Game
{
	class ManagerBase
	{
	public:
		virtual ~ManagerBase() = default;
		virtual bool Init();
		virtual bool Update();
		virtual bool ShutDown();
	};
}
