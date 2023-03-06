#pragma once

#include <memory>
#include <string>

namespace Game
{
	class Texture
	{
	public:
		std::string type;
		static std::shared_ptr<Texture> defaultTexture;

	private:
		unsigned int m_RendererId;
		std::string m_FilePath;
		int m_Width, m_Height, m_Bpp; // Bit Per Pixel of the actual texture
	public:
		explicit Texture(const std::string& path, const std::string& type,
						bool gamma = false);
		~Texture();

		void Bind(unsigned int slot = 0) const;
		void Unbind() const;

		int GetWidth() const { return m_Width; }
		int GetHeight() const { return m_Height; }
	};
}
