#pragma once
#include <functional>
#include "Event.h"
#include "game/utils/TemplateUtil.h"

namespace Game
{
	template <typename... T>
	class EventHandler
	{
	public:
		EventHandler(const std::function<void(T...)>& function);
		void operator()(Event<T...> event);
		void operator()(T... eventArgs);

	private:
		std::function<void(T...)> m_Function;
	};

	template <typename... T>
	EventHandler<T...>::EventHandler(
		const std::function<void(T...)>& function): m_Function(function)
	{
	}

	template <typename... T>
	void EventHandler<T...>::operator()(Event<T...> event)
	{
		TemplateUtil::Apply(m_Function, event.eventArgs);
	}

	template <typename... T>
	void EventHandler<T...>::operator()(T... eventArgs)
	{
		m_Function(eventArgs...);
	}
}
