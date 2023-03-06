#pragma once
#include <memory>

#include "Model.h"
#include "game/base/Component.h"
#include "game/graphics/gl/Shader.h"

namespace Game
{
	class ModelRenderer : public Component
	{
	public:
		std::shared_ptr<Shader> shader;
		std::shared_ptr<Model> model;

		void OnEnable() override;
		void OnDisable() override;

		void Serialize(tinyxml2::XMLElement* writer) override;
		void Deserialize(tinyxml2::XMLElement* reader) override;
	};
}
