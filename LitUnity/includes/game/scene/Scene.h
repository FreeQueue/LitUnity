#pragma once
#include <memory>

#include "game/base/ISerializable.h"
#include "game/base/Object.h"

namespace Game
{
	class Skybox;
	class Light;
	class Camera;

	class Scene final : ISerializable
	{
	public:
		friend class SceneManager;
		static std::shared_ptr<Scene> defaultScene;
		Object root = Object("root");
		std::string xmlPath;

		Camera* mainCamera = nullptr;
		Light* mainLight = nullptr;
		std::unique_ptr<Skybox> skybox;

	private:
		size_t m_IdMaker = 0;

	public:
		Scene() = default;
		size_t GetId();
		void Update();
		void Save();
		void SetCurrent();
		Object& GetRoot();
		void Serialize(tinyxml2::XMLElement* writer) override;
		void Deserialize(tinyxml2::XMLElement* reader) override;
	};
}
