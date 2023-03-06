#include "game/base/Entry.h"
#include "game/scene/Scene.h"
#include "game/scene/Skybox.h"
#include "game/SourceHeader.h"
EventManager Entry::event;
ResManager Entry::res;
ComponentManager Entry::component;
SceneManager Entry::scene;
RenderManager Entry::render;
InputManager Entry::input;
list<ManagerBase*> Entry::m_Managers;
float Entry::m_DeltaTime=0.f;
float Entry::DeltaTime()
{
	return m_DeltaTime;
}

void Entry::Register(ManagerBase* manager)
{
	m_Managers.emplace_back(manager);
	manager->Init();
}

void Entry::Init()
{
	Register(&event);
	Register(&res);
	Register(&component);
	Register(&scene);
	Register(&render);
	Register(&input);
}

void Entry::Update(float deltaTime)
{
	m_DeltaTime = deltaTime;
	for (auto manager : m_Managers)
	{
		manager->Update();
	}
}

void Entry::ShutDown()
{
	for (auto manager : m_Managers)
	{
		manager->ShutDown();
	}
}
