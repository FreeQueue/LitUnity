#include "game/base/Component.h"
#include "game/base/Object.h"
#include "game/scene/Scene.h"
#include "game/SourceHeader.h"

ComponentType Component::GetType() const
{
	return ComponentType::EMPTY;
}

Component::Component(Object* object): id(IdMaker()), m_Object(object)
{
}

Object* Component::GetObject() const
{
	return m_Object;
}

bool Component::IsActive() const
{
	return m_Active;
}

void Component::SetActive(bool active)
{
	if (active == m_Active)return;
	m_Active = active;
	if (m_Active)OnEnable();
	else
	{
		OnDisable();
	}
}

void Component::Destroy()
{
	if (m_Object != nullptr)m_Object->RemoveComponent(id);
}

void Component::M_Destroy()
{
	OnDisable();
	OnDestroy();
}

size_t Component::IdMaker()
{
	return Entry::scene.current->GetId();
}

Transform* Component::GetTransform()
{
	if (m_Object == nullptr)return nullptr;
	return &m_Object->transform;
}

void Component::Awake()
{
}

void Component::OnEnable()
{
}

void Component::Update()
{
}

void Component::OnDisable()
{
}

void Component::OnDestroy()
{
}
