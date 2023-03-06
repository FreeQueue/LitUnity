#pragma once
#include "xml/tinyxml2.h"

class ISerializable
{
public:
	virtual ~ISerializable() = default;
	virtual void Serialize(tinyxml2::XMLElement* writer) =0;
	virtual void Deserialize(tinyxml2::XMLElement* reader) =0;
};
