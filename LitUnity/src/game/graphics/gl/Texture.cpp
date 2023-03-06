#include "game/graphics/gl/Texture.h"

#include "glad/glad.h"
#include "game/SourceHeader.h"
#include "game/graphics/gl/GlHelper.h"
shared_ptr<Texture> Texture::defaultTexture;
Texture::Texture(const std::string& path, const std::string& type, bool gamma)
	: type(type), m_RendererId(0), m_FilePath(path),
	m_Width(0), m_Height(0), m_Bpp(0)
{
	m_RendererId = ResUtil::LoadTexture(path, gamma, m_Width, m_Height, m_Bpp);
}

Texture::~Texture()
{
	GLCall(glDeleteTextures(1, &m_RendererId));
}

void Texture::Bind(unsigned int slot) const
{
	GLCall(glActiveTexture(GL_TEXTURE0 + slot));
	GLCall(glBindTexture(GL_TEXTURE_2D, m_RendererId));
}

void Texture::Unbind() const
{
	GLCall(glBindTexture(GL_TEXTURE_2D, 0));
}
