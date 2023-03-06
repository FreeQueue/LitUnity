#include "game/graphics/gl/Shader.h"

#include "glm/glm.hpp"
#include <glad/glad.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <tuple>

#include "game/graphics/gl/GlHelper.h"
#include "game/SourceHeader.h"
shared_ptr<Shader> Shader::defaultShader, Shader::debugShader;
Shader::Shader(XMLElement* element)
{
	ShaderProgramSource source = ParseShader(element);
	unsigned int vertex = CompileShader(GL_VERTEX_SHADER, source.VertexSource);
	unsigned int fragment = CompileShader(
		GL_FRAGMENT_SHADER, source.VertexSource);
	unsigned int geometry = CompileShader(
		GL_GEOMETRY_SHADER, source.VertexSource);
	// shader Program
	ID = glCreateProgram();
	glAttachShader(ID, vertex);
	glAttachShader(ID, fragment);
	if (source.GeometrySource != "NULL")
		glAttachShader(ID, geometry);
	glLinkProgram(ID);

#ifdef _DEBUG
	GLint success;
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		GLchar infoLog[1024];
		glGetProgramInfoLog(ID, 1024, nullptr, infoLog);
		cout << "ERROR::PROGRAM_LINKING_ERROR:" << "\n" << infoLog <<
			"\n -- --------------------------------------------------- -- " <<
			endl;
	}
#endif

	// delete the shaders as they're linked into our program now and no longer necessary

	glDetachShader(ID, vertex);
	glDeleteShader(vertex);
	glDetachShader(ID, fragment);
	glDeleteShader(fragment);
	if (source.GeometrySource != "NULL")
	{
		glDetachShader(ID, geometry);
		glDeleteShader(geometry);
	}
	SetData(source.datas);
}

Shader::~Shader()
{
	glDeleteProgram(ID);
}

void Shader::SetData(const vector<tuple<string, string, string>>& datas)
{
	for (auto& data : datas)
	{
		auto type=get<0>(data);
		if( type=="bool"){ SetBool(get<1>(data),
			StringUtil::ParseBool(get<2>(data).c_str()));
		}
		else if( type=="int"){ SetInt(get<1>(data),
			StringUtil::ParseInt(get<2>(data).c_str()));
		}
		else if( type=="float"){ SetFloat(get<1>(data),
			StringUtil::ParseFloat(get<2>(data).c_str()));
		}
		else if( type=="vec2"){ SetVec2(get<1>(data),
			StringUtil::ParseVec2(get<2>(data).c_str()));
		}
		else if( type=="vec3"){ SetVec3(get<1>(data),
			StringUtil::ParseVec3(get<2>(data).c_str()));
		}
		else if( type=="vec4"){ SetVec4(get<1>(data),
			StringUtil::ParseVec4(get<2>(data).c_str()));
		}
	}
}

void Shader::Bind() const
{
	GLCall(glUseProgram(ID));
}

void Shader::Unbind() const
{
	GLCall(glUseProgram(0));
}

void Shader::SetBool(const string& name, bool value) const
{
	GLCall(
		glUniform1i(glGetUniformLocation(ID, name.c_str()), static_cast<int>(
			value)));
}

void Shader::SetInt(const string& name, int value) const
{
	GLCall(glUniform1i(glGetUniformLocation(ID, name.c_str()), value));
}

void Shader::SetFloat(const string& name, float value) const
{
	GLCall(glUniform1f(glGetUniformLocation(ID, name.c_str()), value));
}

void Shader::SetVec2(const string& name, const vec2& value) const
{
	GLCall(glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]));
}

void Shader::SetVec2(const string& name, float x, float y) const
{
	GLCall(glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y));
}

void Shader::SetVec3(const string& name, const vec3& value) const
{
	GLCall(glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]));
}

void Shader::SetVec3(const string& name, float x, float y, float z) const
{
	GLCall(glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z));
}

void Shader::SetVec4(const string& name, const vec4& value) const
{
	GLCall(glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]));
}

void Shader::SetVec4(const string& name, float x, float y, float z,
					float w) const
{
	GLCall(glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w));
}

void Shader::SetMat2(const string& name, const mat2& mat) const
{
	GLCall(
		glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,
			&mat[0][0]));
}

void Shader::SetMat3(const string& name, const mat3& mat) const
{
	GLCall(
		glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,
			&mat[0][0]));
}

void Shader::SetMat4(const string& name, const mat4& mat) const
{
	GLCall(
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE,
			&mat[0][0]));
}

ShaderProgramSource Shader::ParseShader(XMLElement* element)
{
	const static string shaderPath="res/shaders/";
	const string vertexPath = shaderPath+element->Attribute("vs");
	const string fragmentPath = shaderPath+element->Attribute("fs");
	auto gs= element->Attribute("gs");
	const string geometryPath = shaderPath+gs;

	ShaderProgramSource source;
	auto data = element->FirstChildElement();
	while (data != nullptr)
	{
		auto attr = data->FirstAttribute();
		source.datas.emplace_back(attr->Name(), data->GetText(), attr->Value());
		data = data->NextSiblingElement();
	}
	// 1. retrieve the vertex/fragment source code from filePath
	ifstream vShaderFile;
	ifstream fShaderFile;
	ifstream gShaderFile;
	// ensure ifstream objects can throw exceptions:
	vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	gShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
	try
	{
		// open files
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);
		stringstream vShaderStream, fShaderStream;
		// read file's buffer contents into streams
		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();
		// close file handlers
		vShaderFile.close();
		fShaderFile.close();
		// convert stream into string
		source.VertexSource = vShaderStream.str();
		source.FragmentSource = fShaderStream.str();
		// if geometry shader path is present, also load a geometry shader
		if (gs != nullptr)
		{
			gShaderFile.open(geometryPath);
			stringstream gShaderStream;
			gShaderStream << gShaderFile.rdbuf();
			gShaderFile.close();
			source.GeometrySource = gShaderStream.str();
		}
		else
		{
			source.GeometrySource = "NULL";
		}
	}
	catch (ifstream::failure& e)
	{
		cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() <<
			endl;
	}

	return source;
}

unsigned Shader::CompileShader(unsigned type, const string& source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	// 返回的是一个指向 string 内部的指针，因此这个 string 必须存在才有效
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);
	// Error handling
	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result); // iv: integer, vector
	if (result == GL_FALSE)
	{
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		auto message = static_cast<char*>(alloca(length * sizeof(char)));
		glGetShaderInfoLog(id, length, &length, message);
		cout << "Failed to compile " <<
			(type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" <<
			endl;
		cout << message << endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}
