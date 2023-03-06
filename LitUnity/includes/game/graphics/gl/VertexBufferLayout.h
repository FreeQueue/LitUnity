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
		// �� unsigned char ���� bool ��Ҫ����ֱ�Ӹ� glVertexAttribPointer �������ĸ�����
		VertexBufferElement(
			unsigned int type,
			unsigned int count,
			unsigned char normalized);
		static unsigned int GetSizeOfType(unsigned int type);
		// ��Ϊ����� type ��ʵ�� type ��һ����־��Ҳ���� GL_FLOAT ��ʾʵ�ʵ��� float��GLfloat��������ʵ���� type �� unsigned int ���͵�
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
