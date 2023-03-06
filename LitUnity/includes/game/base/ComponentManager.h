#pragma once
#include <map>

#include "ManagerBase.h"

namespace Game
{
	class Component;

	class ComponentManager : public ManagerBase
	{
	private:
		std::map<size_t, Component*> m_ComponentMap;

	public:
	};
}
