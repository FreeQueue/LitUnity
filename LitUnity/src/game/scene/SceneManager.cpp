#include "game/scene/SceneManager.h"
#include "game/scene/Skybox.h"
#include "game/scene/Scene.h"
#include <thread>
#include "game/SourceHeader.h"
void SceneManager::LoadScene(const string& xmlPath)
{
	auto id= Entry::res.LoadScene(xmlPath);
	current=Entry::res.GetScene(id);
}
void SceneManager::LoadSceneAsync(const string& xmlPath)
{
	//TODO
}

bool SceneManager::Init()
{
	current=Scene::defaultScene;
	return true;
}

bool SceneManager::Update()
{
	return true;
}

bool SceneManager::ShutDown()
{
	current=nullptr;
	return true;
}
