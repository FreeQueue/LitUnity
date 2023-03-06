#include "game/graphics/gl/VertexBufferLayout.h"

#include "glad/glad.h"
#include "game/SourceHeader.h"

VertexBufferElement::VertexBufferElement(const unsigned type,
										const unsigned count,
										const unsigned char normalized):
	type(type), count(count), normalized(normalized)
{
}

template <>
void VertexBufferLayout::Push<float>(const char* name, unsigned count)
{
	m_Elements.emplace(name, VertexBufferElement(GL_FLOAT, count,GL_FALSE));
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
}

template <>
void VertexBufferLayout::Push<unsigned>(const char* name, unsigned count)
{
	m_Elements.emplace(
		name, VertexBufferElement(GL_UNSIGNED_INT, count, GL_FALSE));
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
}

template <>
void VertexBufferLayout::Push<unsigned char>(const char* name, unsigned count)
{
	m_Elements.emplace(
		name, VertexBufferElement(GL_UNSIGNED_BYTE, count, GL_TRUE));
	m_Stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
}
unsigned VertexBufferElement::GetSizeOfType(unsigned type)
{
	switch (type)
	{
	case GL_FLOAT: return 4;
	case GL_UNSIGNED_INT: return 4;
	case GL_UNSIGNED_BYTE: return 1;
	default:
		break;
	}
	assert(false);
	return 0;
}

VertexBufferLayout::VertexBufferLayout(XMLElement* reader)
{
	XmlUtil::Foreach(reader, [this](XMLElement* element)
	{
		this->PushByType(element->Attribute("name"),
						StringUtil::GlTypeMacro(element->Attribute("type")),
						element->IntAttribute("count"));
	});
}

void VertexBufferLayout::PushByType(const char* name, unsigned type,
									unsigned count)
{
	switch (type)
	{
	case GL_FLOAT: Push<float>(name, count);
		break;
	case GL_UNSIGNED_BYTE: Push<unsigned char>(name, count);
		break;
	case GL_UNSIGNED_INT: Push<unsigned>(name, count);
		break;
	default: return;
	}
}



const std::map<std::string, VertexBufferElement>&
VertexBufferLayout::GetElements() const
{
	return m_Elements;
}

unsigned VertexBufferLayout::GetStride() const
{
	return m_Stride;
}
