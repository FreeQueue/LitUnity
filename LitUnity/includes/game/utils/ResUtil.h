#pragma once
#include <memory>
#include <string>
#include "xml/tinyxml2.h"

namespace Game
{
	class ResUtil
	{
	public:
		static unsigned int LoadTexture(const std::string& filename, bool gamma,
										int& width, int& height,
										int& bitPerPixel);
		static std::unique_ptr<tinyxml2::XMLDocument> LoadXml(
			const std::string& filename);
		static bool SaveXml(tinyxml2::XMLDocument* document,
							const std::string& filename);
	};
}
