#pragma once
#include <string>

#include "EventBase.h"

namespace Game
{
	template <typename... T>
	class Event : public EventBase
	{
	public:
		std::string name;
		std::tuple<T...> eventArgs;

		static Event Create(const char* name, T... eventArgs);

		Event() = delete;

	protected:
		explicit Event(const char* name, T... eventArgs);
	};

	template <typename... T>
	Event<T...> Event<T...>::Create(const char* name, T... eventArgs)
	{
		return Event<T...>(name, eventArgs...);
	}

	template <typename... T>
	Event<T...>::Event(const char* name, T... eventArgs):
		EventBase(std::hash<std::string>{}(name)),
		name(name),
		eventArgs(eventArgs)
	{
	}
}
