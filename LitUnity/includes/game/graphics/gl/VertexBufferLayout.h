#pragma once

#include <map>
#include <string>
#include "xml/tinyxml2.h"
#include "Renderer.h"
#include "glad/glad.h"

namespace Game
{
	struct VertexBufferElement
	{
		unsigned int type;
		unsigned int count;
		unsigned char normalized;
		// 用 unsigned char 而非 bool 主要是想直接给 glVertexAttribPointer 当作第四个参数
		VertexBufferElement(
			unsigned int type,
			unsigned int count,
			unsigned char normalized);
		static unsigned int GetSizeOfType(unsigned int type);
		// 因为这里的 type 是实际 type 的一个标志，也就是 GL_FLOAT 表示实际的是 float（GLfloat），但是实际上 type 是 unsigned int 类型的
	};

	class VertexBufferLayout
	{
	public:
		static VertexBufferLayout Default;

	private:
		std::map<std::string, VertexBufferElement> m_Elements{};
		unsigned int m_Stride = 0;

	public:
		VertexBufferLayout() = default;
		explicit VertexBufferLayout(tinyxml2::XMLElement* reader);
		void PushByType(const char* name, unsigned type, unsigned count);
		template <typename T>
		void Push(const char* name, unsigned int count);

		template <>
		void Push<float>(const char* name, unsigned int count);

		template <>
		void Push<unsigned int>(const char* name, unsigned int count);

		template <>
		void Push<unsigned char>(const char* name, unsigned int count);

		const std::map<std::string,VertexBufferElement>& GetElements() const;
		unsigned int GetStride() const;
	};

	template <typename T>
	void VertexBufferLayout::Push(const char* name, unsigned count)
	{
	}
}
