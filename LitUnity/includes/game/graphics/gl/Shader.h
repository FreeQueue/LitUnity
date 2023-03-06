#pragma once

#include <string>
#include <memory>
#include <vector>
#include <xml/tinyxml2.h>
#include <glm/gtc/matrix_transform.hpp>

namespace Game
{
	struct ShaderProgramSource
	{
		std::string VertexSource;
		std::string FragmentSource;
		std::string GeometrySource;
		std::vector<std::tuple<std::string, std::string, std::string>> datas;
	};

	class Shader
	{
	public:
		unsigned int ID = 0;
		std::string xmlPath;
		static std::shared_ptr<Shader> defaultShader, debugShader;
		// constructor generates the shader on the fly
		explicit Shader(tinyxml2::XMLElement* element);
		~Shader();
		void SetData(
			const std::vector<std::tuple<std::string, std::string, std::string>>
			& datas);
		// activate the shader
		// ------------------------------------------------------------------------
		void Bind() const;
		void Unbind() const;
		// utility uniform functions
		// ------------------------------------------------------------------------
		void SetBool(const std::string& name, bool value) const;
		void SetInt(const std::string& name, int value) const;
		void SetFloat(const std::string& name, float value) const;
		void SetVec2(const std::string& name, const glm::vec2& value) const;
		void SetVec2(const std::string& name, float x, float y) const;
		void SetVec3(const std::string& name, const glm::vec3& value) const;
		void SetVec3(const std::string& name, float x, float y, float z) const;
		void SetVec4(const std::string& name, const glm::vec4& value) const;
		void SetVec4(const std::string& name, float x, float y, float z,
					float w) const;
		void SetMat2(const std::string& name, const glm::mat2& mat) const;
		void SetMat3(const std::string& name, const glm::mat3& mat) const;
		void SetMat4(const std::string& name, const glm::mat4& mat) const;

	private:
		ShaderProgramSource ParseShader(tinyxml2::XMLElement* element);
		unsigned int CompileShader(unsigned int type,
									const std::string& source);
	};
}
