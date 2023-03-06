#include "game/utils/StringUtil.h"
#include "sstream"
#include "game/SourceHeader.h"

vector<string> StringUtil::Split(const char* data, const char* pattern)
{
	vector<string> result;
	const size_t patlen=strlen(pattern) - 1;
	string str = data;
	str += pattern; //扩展字符串以方便操作
	const size_t size = str.size();
	for (size_t i = 0; i < size; i++)
	{
		const string::size_type pos = str.find(pattern, i);
		if (pos < size)
		{
			string s = str.substr(i, pos - i);
			result.push_back(s);
			i = pos + patlen;
		}
	}
	return result;
}
string StringUtil::Trim(const char* data)
{
	string str(data);
	return Trim(str);
}
string StringUtil::TrimAll(const char* data)
{
	string str(data);
	return TrimAll(str);
}
string& StringUtil::Trim(string& str)
{
	if (!str.empty())
	{
		str.erase(0, str.find_first_not_of(" "));
		str.erase(str.find_last_not_of(" ") + 1);
	}
	return str;
}
string& StringUtil::TrimAll(string& str)
{
	int index = 0;
	if (!str.empty())
	{
		while ((index = str.find(' ', index)) != string::npos)
		{
			str.erase(index, 1);
		}
	}
	return str;
}
bool StringUtil::ParseBool(const char* data)
{
	if (strcmp(data, "true") != 0 || strcmp(data, "1") != 0)return true;
	return false;
}

string StringUtil::WriteBool(bool data)
{
	if (data)return "true";
	return "false";
}

int StringUtil::ParseInt(const char* data)
{
	return stoi(data);
}

string StringUtil::WriteInt(int data)
{
	return to_string(data);
}

string StringUtil::WriteFloat(float data)
{
	return to_string(data);
}

string StringUtil::WriteVec2(vec2 data)
{
	stringstream ss;
	ss << data.x << "," << data.y;
	return ss.str();
}

string StringUtil::WriteVec3(vec3 data)
{
	stringstream ss;
	ss << data.x << "," << data.y << "," << data.z;
	return ss.str();
}

string StringUtil::WriteVec4(vec4 data)
{
	stringstream ss;
	ss << data.x << "," << data.y << "," << data.z << "," << data.w;
	return ss.str();
}

unsigned int StringUtil::GlTypeMacro(const string& type)
{
	if (type == "float")return GL_FLOAT;
	else if ("ubyte")return GL_UNSIGNED_BYTE;
	else if ("uint")return GL_UNSIGNED_INT;
	return 0;
}

float StringUtil::ParseFloat(const char* data)
{
	return stof(data);
}

vec2 StringUtil::ParseVec2(const char* data)
{
	if(data==nullptr)return vec2(0.0f);
	string str=TrimAll(data);
	if(str.empty())return vec2(0.0f);
	auto datas = Split(str.c_str(), ",");
	if (datas.size() == 1) {
		float value = stof(datas[0]);
		return vec2(value);
	}
	return {
		stof(datas[0]),
		stof(datas[1]),
	};
}

vec3 StringUtil::ParseVec3(const char* data)
{
	if(data==nullptr)return vec3(0.0f);
	string str=TrimAll(data);
	if(str.empty())return vec3(0.0f);
	auto datas = Split(str.c_str(), ",");
	if (datas.size() == 1) {
		float value = stof(datas[0]);
		return vec3(value);
	}
	return {
		stof(datas[0]),
		stof(datas[1]),
		datas.size() >= 3 ? stof(datas[2]) : 1.0f
	};
}

vec4 StringUtil::ParseVec4(const char* data)
{
	if(data==nullptr)return vec4(0.0f);
	string str=TrimAll(data);
	if(str.empty())return vec4(0.0f);
	auto datas = Split(str.c_str(), ",");
	if (datas.size() == 1) {
		float value = stof(datas[0]);
		return vec4(value);
	}
	return {
		stof(datas[0]),
		stof(datas[1]),
		stof(datas[2]),
		datas.size() >= 4 ? stof(datas[3]) : 1.0f
	};
}
