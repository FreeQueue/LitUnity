#include "game/utils/XmlUtil.h"
#include "game/SourceHeader.h"

void XmlUtil::Foreach(XMLElement* element,
					const std::function<void(XMLElement*)> function)
{
	for (auto child = element->FirstChildElement(); child != nullptr; child =
		child->NextSiblingElement())
	{
		function(child);
	}
}
