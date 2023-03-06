#include "game/res/ResManager.h"
#include "game/graphics/gl/Texture.h"
#include "game/scene/Scene.h"
#include "game/scene/Skybox.h"
#include <iostream>

#include "game/SourceHeader.h"
size_t ResManager::LoadTexture(const string& path, const string& type,
								bool gamma)
{
	size_t id = h(path);
	if (m_Textures.find(id) == m_Textures.end())
		m_Textures.emplace(id, new Texture(path, type, gamma));
	return id;
}

size_t ResManager::LoadShader(const string& xmlPath)
{
	if(xmlPath=="default")return defaultShader;
	size_t id = h(xmlPath);
	auto xml = ResUtil::LoadXml(shaderPath+xmlPath);
	if (xml.get() == nullptr)
	{
		cout << "Shader load failed with invalid xml:" << xmlPath << "\n";
		return 0;
	}
	if (m_Shaders.find(id) == m_Shaders.end())
		m_Shaders.emplace(id, new Shader(xml->RootElement()));
	return id;
}

size_t ResManager::LoadModel(const string& xmlPath)
{
	if(xmlPath=="cube"||xmlPath=="sphere")return defaultModels[xmlPath];
	size_t id = h(xmlPath);
	const auto xml = ResUtil::LoadXml(modelPath+xmlPath);
	if (xml.get() == nullptr)
	{
		cout << "Model load failed with invalid xml:" << xmlPath << "\n";
		return 0;
	}
	if (m_Models.find(id) == m_Models.end())
	{
		m_Models.emplace(id, new Model(xml->RootElement()));
	}
	GetModel(id)->xmlPath = xmlPath;
	return id;
}

size_t ResManager::LoadScene(const string& xmlPath)
{
	if(xmlPath=="default")return defaultScene;
	size_t id = h(xmlPath);
	const auto xml = ResUtil::LoadXml(scenePath+xmlPath);
	if (xml.get() == nullptr)
	{
		cout << "Scene load failed with invalid xml:" << xmlPath << "\n";
		return 0;
	}
	if (m_Scenes.find(id)!=m_Scenes.end())
	{
		m_Scenes.emplace(id, new Scene());
	}
	const auto scene = GetScene(id);
	scene->xmlPath = xmlPath;
	scene->Deserialize(xml->RootElement());
	return id;
}


shared_ptr<Texture> ResManager::GetTexture(const size_t id)
{
	auto iter = m_Textures.find(id);
	if (iter != m_Textures.end())
	{
		return iter->second;
	}
	return Texture::defaultTexture;
}

shared_ptr<Shader> ResManager::GetShader(const size_t id)
{
	auto iter = m_Shaders.find(id);
	if (iter != m_Shaders.end())
	{
		return iter->second;
	}
#ifdef _DEBUG
	return Shader::debugShader;
#else
	return Shader::defaultShader;
#endif
}

shared_ptr<Model> ResManager::GetModel(const size_t id)
{
	auto iter = m_Models.find(id);
	if (iter != m_Models.end())
	{
		return iter->second;
	}
#ifdef _DEBUG
	return Model::defaults["debug"];
#else
	return nullptr;
#endif
}

shared_ptr<Scene> ResManager::GetScene(const size_t id)
{
	auto iter = m_Scenes.find(id);
	if (iter != m_Scenes.end())
	{
		return iter->second;
	}
	return nullptr;
}

bool ResManager::DelScene(const size_t id)
{
	if (m_Scenes.find(id)!=m_Scenes.end())
	{
		m_Scenes.erase(id);
		return true;
	}
	return false;
}

bool ResManager::DelTexture(const size_t id)
{
	if (m_Textures.find(id) != m_Textures.end())
	{
		m_Textures.erase(id);
		return true;
	}
	return false;
}

bool ResManager::DelShader(const size_t id)
{
	if (m_Shaders.find(id) != m_Shaders.end())
	{
		m_Shaders.erase(id);
		return true;
	}
	return false;
}

bool ResManager::DelModel(const size_t id)
{
	if (m_Models.find(id) != m_Models.end())
	{
		m_Models.erase(id);
		return true;
	}
	return false;
}


bool ResManager::Init()
{
	bool flag = true;
	static const string DefaultRes = "res/default/", 
		TextureRes = DefaultRes + "textures/";
	shaderPath=DefaultRes + "materials/";
	modelPath=DefaultRes + "models/";
	scenePath=DefaultRes + "scenes/";
	
	auto loadDefaultModel = [this](const string& name)-> bool
	{
		const auto model = LoadModel(name + ".xml");
		if (model == 0)return false;
		defaultModels.emplace(name,model);
		Model::defaults[name] = GetModel(model);
		return true;
	};
	flag = loadDefaultModel("skybox") && flag;
	flag = loadDefaultModel("cube") && flag;
	flag = loadDefaultModel("sphere") && flag;
	defaultShader = LoadShader("defaultShader.xml");
	if (defaultShader == 0)flag = false;
	else Shader::defaultShader = GetShader(defaultShader);
	defaultScene = LoadScene("defaultScene.xml");
	if (defaultScene == 0)flag = false;
	else Scene::defaultScene = GetScene(defaultScene);
#ifdef _DEBUG
	flag = loadDefaultModel("debug") && flag;
	debugShader = LoadShader("debugShader.xml");
	if (debugShader == 0)flag = false;
	else Shader::debugShader = GetShader(debugShader);
#endif

	shaderPath="res/meta/materials/";
	modelPath="res/meta/models/";
	scenePath="res/meta/scenes/";
	return flag;
}

bool ResManager::Update()
{
	return true;
}

bool ResManager::ShutDown()
{
	m_Scenes.clear();
	defaultScene=0;
	Scene::defaultScene=nullptr;
	m_Models.clear();
	defaultModels.clear();
	Model::defaults.clear();
	m_Shaders.clear();
	defaultShader=0;
	Shader::defaultShader=nullptr;
	m_Textures.clear();
#ifdef _DEBUG
	debugShader=0;
	Shader::debugShader=nullptr;
#endif
	return true;
}
