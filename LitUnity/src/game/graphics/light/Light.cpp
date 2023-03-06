#include "game/graphics/light/Light.h"

#include "game/SourceHeader.h"


void Light::Serialize(XMLElement* writer)
{
	auto light = writer->InsertNewChildElement("light");
	light->SetAttribute("color", StringUtil::WriteVec4(color).c_str());
	switch (type)
	{
	case LightType::POINT: light->SetAttribute("type", "point");
		break;
	case LightType::SPOT: light->SetAttribute("type", "spot");
		break;
	default: light->SetAttribute("type", "direction");
		break;
	}
	light->SetAttribute("radius", radius);
}

void Light::Deserialize(XMLElement* reader)
{
	color = StringUtil::ParseVec4(reader->Attribute("color"));
	const string typeStr=reader->Attribute("type");
	if(typeStr=="point")type = LightType::POINT;
	else if(typeStr=="spot")type = LightType::SPOT;
	else type = LightType::DIRECTION;
	if (reader->FindAttribute("radius"))
	{
		radius = reader->FloatAttribute("radius");
	}
	else
	{
		radius = 1.0f;
	}
}
