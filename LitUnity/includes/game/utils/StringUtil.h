#pragma once
#include <string>
#include <vector>

#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
#include "glm/vec4.hpp"

class StringUtil
{
public:
	static std::vector<std::string> Split(const char* data, const char* pattern);
	static std::string Trim(const char* data);
	static std::string TrimAll(const char* data);
	static std::string& Trim(std::string& str);
	static std::string& TrimAll(std::string& str);
	static bool ParseBool(const char* data);
	static std::string WriteBool(bool data);
	static int ParseInt(const char* data);
	static std::string WriteInt(int data);
	static float ParseFloat(const char* data);
	static std::string WriteFloat(float data);
	static glm::vec2 ParseVec2(const char* data);
	static std::string WriteVec2(glm::vec2 data);
	static glm::vec3 ParseVec3(const char* data);
	static std::string WriteVec3(glm::vec3 data);
	static glm::vec4 ParseVec4(const char* data);
	static std::string WriteVec4(glm::vec4 data);
	static unsigned int GlTypeMacro(const std::string& type);
};
