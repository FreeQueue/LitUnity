#pragma once
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"
#include "xml/tinyxml2.h"
#include "game/base/Component.h"

namespace Game
{
	enum class LightType
	{
		DIRECTION,
		POINT,
		SPOT,
	};

	class Light : public Component
	{
	public:
		LightType type = LightType::DIRECTION;
		glm::vec4 color = glm::vec4(1);
		float radius = 1;
		void Serialize(tinyxml2::XMLElement* writer) override;
		void Deserialize(tinyxml2::XMLElement* reader) override;
	};
}
