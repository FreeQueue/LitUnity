#include <memory>

#include "game/graphics/model/mesh.h"
#include <utility>
#include "game/graphics/gl/Texture.h"
#include "game/SourceHeader.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned> indices,
			vector<size_t> textures, VertexBufferLayout* layout)
{
	this->vertices = std::move(vertices);
	this->indices = std::move(indices);
	this->textures = std::move(textures);
	// now that we have all the required data, set the vertex buffers and its attribute pointers.
	SetupMesh(*layout);
}

Mesh::Mesh(Mesh&& other) noexcept:
	vertices(move(other.vertices)),
	indices(move(other.indices)),
	textures(move(other.textures)),
	m_Vao(move(other.m_Vao)),
	m_Vbo(move(other.m_Vbo)),
	m_Ebo(move(other.m_Ebo))
{
}

void Mesh::Draw(Renderer& renderer)
{
	// bind appropriate textures
	unsigned int diffuseNr = 1;
	unsigned int specularNr = 1;
	unsigned int normalNr = 1;
	unsigned int heightNr = 1;
	for (unsigned int i = 0; i < textures.size(); i++)
	{
		shared_ptr<Texture> texture = Entry::res.GetTexture(textures[i]);
		texture->Bind(i); // active proper texture unit before binding
		// retrieve texture number (the N in diffuse_textureN)
		string number;
		string name = texture->type;
		if (name == "texture_diffuse")
			number = std::to_string(diffuseNr++);
		else if (name == "texture_specular")
			number = std::to_string(specularNr++);
			// transfer unsigned int to string
		else if (name == "texture_normal")
			number = std::to_string(normalNr++);
			// transfer unsigned int to string
		else if (name == "texture_height")
			number = std::to_string(heightNr++);
		// transfer unsigned int to string

		// now set the sampler to the correct texture unit
		renderer.currentShader->SetInt(name + number, i);
	}
	renderer.Draw(*m_Vao, *m_Ebo);
}

void Mesh::SetupMesh(VertexBufferLayout& layout)
{
	m_Vao = make_unique<VertexArray>();
	m_Vbo = make_unique<VertexBuffer>(vertices.data(),
									vertices.size() * sizeof(Vertex));
	m_Vao->AddBuffer(*m_Vbo, layout);
	m_Ebo = make_unique<IndexBuffer>(indices.data(),
									indices.size() * sizeof(unsigned int));
	m_Vao->Unbind();
}
