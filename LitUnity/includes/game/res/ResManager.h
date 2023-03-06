#pragma once
#include <map>
#include <memory>
#include <string>

#include "game/base/ManagerBase.h"


namespace Game
{
	class Model;
	class Shader;
	class Texture;
	class Scene;

	class ResManager : public ManagerBase
	{
	public:
		size_t defaultShader=0,defaultScene=0;
		std::map<std::string,size_t> defaultModels{};
#ifdef _DEBUG
		size_t debugShader=0;
#endif // _DEBUG

	private:
		std::map<size_t, std::shared_ptr<Texture>> m_Textures;
		std::map<size_t, std::shared_ptr<Shader>> m_Shaders;
		std::map<size_t, std::shared_ptr<Model>> m_Models;
		std::map<size_t, std::shared_ptr<Scene>> m_Scenes;
		std::hash<std::string> h;
		
		std::string shaderPath;
		std::string modelPath;
		std::string scenePath;
	public:
		size_t LoadTexture(const std::string& path, const std::string& type,
							bool gamma = false);
		size_t LoadShader(const std::string& xmlPath);
		size_t LoadModel(const std::string& xmlPath);
		size_t LoadScene(const std::string& xmlPath);
		std::shared_ptr<Texture> GetTexture(size_t id);
		std::shared_ptr<Shader> GetShader(size_t id);
		std::shared_ptr<Model> GetModel(size_t id);
		std::shared_ptr<Scene> GetScene(size_t id);
		bool DelTexture(size_t id);
		bool DelShader(size_t id);
		bool DelModel(size_t id);
		bool DelScene(size_t id);
		bool Init() override;
		bool Update() override;
		bool ShutDown() override;
	};
}
