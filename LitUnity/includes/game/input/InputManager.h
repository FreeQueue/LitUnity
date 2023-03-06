#pragma once
#include "game/base/ManagerBase.h"

namespace Game
{
	// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
	enum class Camera_Movement
	{
		FORWARD,
		BACKWARD,
		LEFT,
		RIGHT
	};

	class InputManager final : public ManagerBase
	{
	public:
		float movementSpeed = 2.5f;
		float mouseSensitivity = 0.1f;

	public:
		// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
		void ProcessKeyboard(Camera_Movement direction, float deltaTime);

		// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
		void ProcessMouseMovement(float xOffset, float yOffset,
								unsigned char constrainPitch = true);

		// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
		void ProcessMouseScroll(float yOffset);
		bool Init() override;
		bool Update() override;
	};
}
