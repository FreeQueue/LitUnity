#pragma once
#include "game/base/ComponentManager.h"
#include "game/event/EventManager.h"
#include "game/graphics/RenderManager.h"
#include "game/input/InputManager.h"
#include "game/res/ResManager.h"
#include "game/scene/SceneManager.h"

namespace Game
{
	class Entry
	{
	public:
		static EventManager event;
		static ResManager res;
		static ComponentManager component;
		static SceneManager scene;
		static RenderManager render;
		static InputManager input;

	private:
		static std::list<ManagerBase*> m_Managers;
		static float m_DeltaTime;

	public:
		static float DeltaTime();
		static void Init();
		static void Update(float deltaTime);
		static void ShutDown();
	private:
		static void Register(ManagerBase* manager);
	};
}
