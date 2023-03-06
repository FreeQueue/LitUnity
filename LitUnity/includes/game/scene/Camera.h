#pragma once
#include "game/event/EventHandler.h"
#include "game/base/Component.h"
#include "glm/fwd.hpp"
#include "glm/vec4.hpp"

namespace Game
{
	// An abstract camera class that processes input and calculates the corresponding Euler Angles, Vectors and Matrices for use in OpenGL
	class Camera final : public Component
	{
	public:
		float zNear = 0.1f, zFar = 100.f, zoom = 90.f;
		glm::vec4 background = glm::vec4(1);
		// constructor with vectors
	private:
		unsigned m_Width = 800, m_Height = 600;
		float m_Aspect;
		const char* m_MainCameraDisableEvent="main camera disable";
		std::shared_ptr<EventHandler<>> m_SetMainCameraHandler;
	public:
		bool IsMainCamera();
		static void SetMainCamera(Camera* camera);
		unsigned Width();
		unsigned Height();
		void SetScreen(unsigned width, unsigned height);
		float Aspect();
		void SetMainCamera();
		void InitRenderer();
		void UpdateRenderer();
		// returns the view matrix calculated using Euler Angles and the LookAt Matrix
		glm::mat4 GetViewMatrix() const;
		glm::vec3 GetForward() const;
		glm::vec3 GetUp() const;
		glm::vec3 GetRight() const;
		void Serialize(tinyxml2::XMLElement* writer) override;
		void Deserialize(tinyxml2::XMLElement* reader) override;
		ComponentType GetType() const override;
		void Awake() override;
		void OnEnable() override;
		void Update() override;
		void OnDisable() override;
		void OnDestroy() override;
	};
}
