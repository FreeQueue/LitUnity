#pragma once
#include <map>
#include <memory>
#include <string>
#include "game/base/ManagerBase.h"

namespace Game
{
	class Scene;

	class SceneManager final : public ManagerBase
	{
	public:
		std::shared_ptr<Scene> current=nullptr;

	public:
		void LoadScene(const std::string& xmlPath);
		void LoadSceneAsync(const std::string& xmlPath);
		bool Init() override;
		bool Update() override;
		bool ShutDown() override;
	};
}
