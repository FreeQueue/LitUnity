#pragma once
#include "EventPool.h"
#include "game/base/ManagerBase.h"

namespace Game
{
	class EventManager final : public ManagerBase
	{
	public:
		template <typename... T>
		void Fire(const char* name, T... eventArgs);

		template <typename... T>
		void FireNow(const char* name, T... eventArgs);

		template <typename... T>
		void Fire(const Event<T...>& event);

		template <typename... T>
		void FireNow(const Event<T...>& event);

		template <typename... T>
		bool Subscribe(const char* name, EventHandler<T...>* handler);

		template <typename... T>
		bool Unsubscribe(const char* name, EventHandler<T...>* handler);

		template <typename... T>
		void UnsubscribeAll(const char* name);
	};

	template <typename... T>
	void EventManager::Fire(const char* name, T... eventArgs)
	{
		EventPool<T...>::pool.Fire(name, eventArgs...);
	}

	template <typename... T>
	void EventManager::FireNow(const char* name, T... eventArgs)
	{
		EventPool<T...>::pool.FireNow(name, eventArgs...);
	}

	template <typename... T>
	void EventManager::Fire(const Event<T...>& event)
	{
		EventPool<T...>::pool.Fire(event);
	}

	template <typename... T>
	void EventManager::FireNow(const Event<T...>& event)
	{
		EventPool<T...>::pool.FireNow(event);
	}

	template <typename... T>
	bool EventManager::Subscribe(const char* name, EventHandler<T...>* handler)
	{
		return EventPool<T...>::pool.Subscribe(name, handler);
	}

	template <typename... T>
	bool EventManager::Unsubscribe(const char* name,
									EventHandler<T...>* handler)
	{
		return EventPool<T...>::pool.Unsubscribe(handler);
	}

	template <typename... T>
	void EventManager::UnsubscribeAll(const char* name)
	{
		EventPool<T...>::pool.UnsubscribeAll(name);
	}
}
