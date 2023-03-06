#pragma once
#include "xml/tinyxml2.h"

namespace Game
{
	class Component;

	class ObjectUtil
	{
	public:
		static Component* ParseComponent(tinyxml2::XMLElement* element);
	};
}
