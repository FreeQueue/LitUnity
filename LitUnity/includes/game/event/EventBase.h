#pragma once
namespace Game
{
	class EventBase
	{
	public:
		const int id;
		explicit EventBase(int id);
	};

	inline EventBase::EventBase(const int id): id(id)
	{
	}
}
