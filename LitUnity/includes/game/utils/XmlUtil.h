#pragma once
#include "xml/tinyxml2.h"
#include "functional"

class XmlUtil
{
public:
	static void Foreach(tinyxml2::XMLElement* element,
						std::function<void(tinyxml2::XMLElement*)> function);
};
