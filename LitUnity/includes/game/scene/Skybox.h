#pragma once
#include "game/base/ISerializable.h"
#include "game/base/Object.h"

namespace Game
{
	class Renderer;
	class ModelRenderer;

	class Skybox final : public ISerializable
	{
	public:
		Object object;
		ModelRenderer* modelRenderer = nullptr;

	public:
		Skybox();
		void Update();
		void Draw(Renderer& renderer) const;
		void Serialize(tinyxml2::XMLElement* writer) override;
		void Deserialize(tinyxml2::XMLElement* reader) override;
	};
}
