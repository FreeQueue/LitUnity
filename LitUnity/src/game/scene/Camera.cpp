#include "game/scene/Camera.h"
#include "game/scene/Scene.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/quaternion.hpp"
#include "game/SourceHeader.h"


bool Camera::IsMainCamera()
{
	return Entry::scene.current->mainCamera == this;
}

void Camera::SetMainCamera(Camera* camera)
{
	Entry::scene.current->mainCamera = camera;
}

unsigned Camera::Width()
{
	return m_Width;
}

unsigned Camera::Height()
{
	return m_Height;
}

void Camera::SetScreen(const unsigned width, const unsigned height)
{
	m_Width = width;
	m_Height = height;
	m_Aspect = static_cast<float>(m_Width) / static_cast<float>(m_Height);
	InitRenderer();
}

float Camera::Aspect()
{
	return m_Aspect;
}

void Game::Camera::SetMainCamera()
{
	if (Entry::scene.current->mainCamera == nullptr)
	{
		Entry::scene.current->mainCamera = this;
		InitRenderer();
	}
}

void Camera::InitRenderer()
{
	auto& renderer = Entry::render.renderer;
	renderer.background = background;
	renderer.projection = perspective(radians(zoom), Aspect(), zNear, zFar);
	renderer.frustum = Frustum::CreateFrustumFromCamera(
		*this, Aspect(), radians(zoom), zNear, zFar);
}

void Camera::UpdateRenderer()
{
	auto& renderer = Entry::render.renderer;
	renderer.view = GetViewMatrix();
}

mat4 Camera::GetViewMatrix() const
{
	auto pos = m_Object->transform.GetGlobalPosition();
	return lookAt(pos, pos + GetForward(), GetUp());
}

vec3 Camera::GetForward() const
{
	return m_Object->transform.GetForward();
}

vec3 Camera::GetRight() const
{
	return m_Object->transform.GetRight();
}

void Camera::Serialize(XMLElement* writer)
{
	auto camera = writer->InsertNewChildElement("camera");
	camera->SetAttribute("width", m_Width);
	camera->SetAttribute("height", m_Height);
	camera->SetAttribute("zNear", zNear);
	camera->SetAttribute("zFar", zFar);
	camera->SetAttribute("zoom", zoom);
	camera->SetAttribute("background",
						StringUtil::WriteVec4(background).c_str());
}

void Camera::Deserialize(XMLElement* reader)
{
	SetScreen(reader->UnsignedAttribute("width", 800),
			reader->UnsignedAttribute("height", 600));

	zNear = reader->FloatAttribute("zNear", 0.1f);
	zFar = reader->FloatAttribute("zFar", 100.f);
	zoom = reader->FloatAttribute("zoom", 90.f);
	background = StringUtil::ParseVec4(reader->Attribute("background"));
}

ComponentType Camera::GetType() const
{
	return ComponentType::CAMERA;
}

void Camera::Awake()
{
	m_SetMainCameraHandler=make_shared([this](){
		this->SetMainCamera();
		if(IsMainCamera())Entry::event.Unsubscribe<>(
			m_MainCameraDisableEvent,m_SetMainCameraHandler)
		});
}

void Camera::OnEnable()
{
	SetMainCamera();
	Entry::event.Subscribe("main camera disable",new EventHandler<int>([this](int a){
		this->SetMainCamera();
		}));
}

void Camera::Update()
{
	Component::Update();
}

void Camera::OnDisable()
{
	if (Entry::scene.current->mainCamera == this)
	{
		Entry::scene.current->mainCamera = nullptr;
	}
}

void Camera::OnDestroy()
{
	Component::OnDestroy();
}

vec3 Camera::GetUp() const
{
	return m_Object->transform.GetUp();
}
