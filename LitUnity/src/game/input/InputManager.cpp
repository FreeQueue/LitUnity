#include "game/input/InputManager.h"
#include "game/scene/Scene.h"
#include "game/scene/Camera.h"
#include "game/SourceHeader.h"

void InputManager::ProcessKeyboard(const Camera_Movement direction,
									const float deltaTime)
{
	float velocity = movementSpeed * deltaTime;
	Transform* transform = Entry::scene.current->mainCamera->GetTransform();
	if (direction == Camera_Movement::FORWARD)
		transform->AddLocalPosition(transform->GetForward() * velocity);
	if (direction == Camera_Movement::BACKWARD)
		transform->AddLocalPosition(- transform->GetForward() * velocity);
	if (direction == Camera_Movement::LEFT)
		transform->AddLocalPosition(- transform->GetRight() * velocity);
	if (direction == Camera_Movement::RIGHT)
		transform->AddLocalPosition(transform->GetRight() * velocity);
}

void InputManager::ProcessMouseMovement(float xOffset, float yOffset,
										const unsigned char constrainPitch)
{
	xOffset *= mouseSensitivity;
	yOffset *= mouseSensitivity;

	//Yaw += xOffset;
	//Pitch += yOffset;

	//// make sure that when pitch is out of bounds, screen doesn't get flipped
	//if (constrainPitch)
	//{
	//	if (Pitch > 89.0f)
	//		Pitch = 89.0f;
	//	if (Pitch < -89.0f)
	//		Pitch = -89.0f;
	//}

	//// update Front, Right and Up Vectors using the updated Euler angles
	//UpdateCameraVectors();
}

void InputManager::ProcessMouseScroll(const float yOffset)
{
	auto& zoom = Entry::scene.current->mainCamera->zoom;
	zoom -= yOffset;
	if (zoom < 1.0f)
		zoom = 1.0f;
	if (zoom > 45.0f)
		zoom = 45.0f;
}

bool InputManager::Init()
{
	return false;
}

bool InputManager::Update()
{
	return ManagerBase::Update();
}
