#pragma once
#include <vector>
#include <memory>
#include "glm/vec2.hpp"
#include "game/graphics/gl/VertexBuffer.h"
#include "game/graphics/gl/IndexBuffer.h"
#include "game/graphics/gl/VertexArray.h"
#define MAX_BONE_INFLUENCE 4

namespace Game
{
	struct Vertex
	{
		// position
		glm::vec3 position;
		// normal
		glm::vec3 normal;
		// texCoords
		glm::vec2 texCoords;
		// tangent
		glm::vec3 tangent;
		// bitangent
		glm::vec3 bitangent;
		//bone indexes which will influence this vertex
		int boneIDs[MAX_BONE_INFLUENCE]{};
		//weights from each bone
		float weights[MAX_BONE_INFLUENCE]{};
	};

	class Mesh
	{
	public:
		// mesh Data
		std::vector<Vertex> vertices{};
		std::vector<unsigned int> indices{};
		std::vector<size_t> textures{};
		// constructor
		Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices,
			std::vector<size_t> textures, VertexBufferLayout* layout);
		Mesh(Mesh&& other) noexcept;
		~Mesh() = default;
		// render the mesh
		void Draw(Renderer& renderer);

	private:
		std::unique_ptr<VertexArray> m_Vao;
		std::unique_ptr<VertexBuffer> m_Vbo;
		std::unique_ptr<IndexBuffer> m_Ebo;
		// initializes all the buffer objects/arrays
		void SetupMesh(VertexBufferLayout& layout);
	};
}
