#pragma once
#include <glm/gtc/matrix_transform.hpp>
#include"game/graphics/model/Boundings.h"

namespace Game
{
	class Shader;
	class ModelRenderer;
	class VertexArray;
	class IndexBuffer;

	class Renderer
	{
	public:
		glm::mat4 projection, view;
		glm::vec4 background{0.5f};
		Shader* currentShader = nullptr;
		Frustum frustum;

	public:
		void Clear() const;
		void Draw(ModelRenderer* modelRenderer);
		void Draw(const VertexArray& va, const IndexBuffer& ib);
	};
}
