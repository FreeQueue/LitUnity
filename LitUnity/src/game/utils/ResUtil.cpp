#include "game/utils/ResUtil.h"

#include <iostream>
#include <ostream>
#include <image/stb_image.h>
#include "game/graphics/gl/GlHelper.h"
#include "glad/glad.h"
#include "game/SourceHeader.h"

unsigned ResUtil::LoadTexture(const string& filename, bool gamma, int& width,
							int& height, int& bitPerPixel)
{
	stbi_set_flip_vertically_on_load(true);
	unsigned int textureID;
	GLCall(glGenTextures(1, &textureID));

	unsigned char* data = stbi_load(filename.c_str(), &width, &height,
									&bitPerPixel, 0);
	if (data)
	{
		GLenum format = 0;
		if (bitPerPixel == 1)
			format = GL_RED;
		else if (bitPerPixel == 3)
			format = GL_RGB;
		else if (bitPerPixel == 4)
			format = GL_RGBA;

		GLCall(glBindTexture(GL_TEXTURE_2D, textureID));
		GLCall(glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
			GL_UNSIGNED_BYTE, data));
		GLCall(glGenerateMipmap(GL_TEXTURE_2D));

		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT));
		GLCall(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
			GL_LINEAR_MIPMAP_LINEAR));
		GLCall(
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR));

		stbi_image_free(data);
	}
	else
	{
		cout << "Texture failed to load at filename: " << filename << endl;
		stbi_image_free(data);
	}

	return textureID;
}

unique_ptr<XMLDocument> ResUtil::LoadXml(const string& filename)
{
	XMLDocument* document = nullptr;
	const auto error =document->LoadFile(filename.c_str());
	if (error != XML_SUCCESS)
	{
		cout << "Xml failed to load with error code:" << error << endl;
	}
	return unique_ptr<XMLDocument>(document);
}

bool ResUtil::SaveXml(XMLDocument* document,
					const string& filename)
{
	const auto error = document->SaveFile(filename.c_str());
	if (error != XML_SUCCESS)
	{
		cout << "Xml failed to save with error code:" << error << endl;
		return false;
	}
	return true;
}
