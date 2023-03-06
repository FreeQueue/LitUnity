#include "game/base/Object.h"
#include "game/scene/Scene.h"
#include "game/SourceHeader.h"
Object::Object(string name, Object* parent)
	: id(IdMaker()), name(std::move(name)), m_Parent(parent)
{
}

bool Object::IsActive() const
{
	return m_Active;
}

void Object::SetActive(bool active)
{
	if (active == m_Active)return;
	m_Active = active;
	if (m_Active)
	{
		for (auto& component : m_Components)
		{
			if (component.get()->IsActive())component.get()->OnEnable();
		}
	}
	else
	{
		for (auto& component : m_Components)
		{
			if (component.get()->IsActive())component.get()->OnDisable();
		}
	}
	for (auto& child : children)
	{
		child.get()->SetActive(m_Active);
	}
}

void Object::Destroy()
{
	if (m_Parent != nullptr)
	{
		m_Parent->RemoveChild(id);
	}
}

Object* Object::GetParent() const
{
	return m_Parent;
}

Component* Object::GetComponent(ComponentType type) const
{
	for (const auto& component : m_Components)
	{
		if (component->GetType() == type)return component.get();
	}
	return nullptr;
}

vector<Component*> Object::GetComponents(ComponentType type) const
{
	vector<Component*> components;
	for (const auto& component : m_Components)
	{
		if (component->GetType() == type)
			components.emplace_back(
				component.get());
	}
	return components;
}

Object* Object::GetChild(const std::string& name) const
{
	for (const auto& child : children)
	{
		if (child->name == name)return child.get();
	}
	return nullptr;
}

void Object::RemoveChild(size_t id)
{
	children.remove_if([id](std::unique_ptr<Object>& child)-> bool
	{
		if (child->id == id)
		{
			child->M_Destroy();
			return true;
		}
		return false;
	});
}

void Object::RemoveChildren()
{
	for (auto& child : children)
	{
		child->M_Destroy();
	}
	children.clear();
}

void Object::RemoveComponent(size_t id)
{
	m_Components.remove_if([id](std::unique_ptr<Component>& component)-> bool
	{
		if (component->id == id)
		{
			component->M_Destroy();
			return true;
		}
		return false;
	});
}

void Object::RemoveComponent(ComponentType type)
{
	TemplateUtil::ListRemoveOne<std::unique_ptr<Component>>(m_Components,[type](std::unique_ptr<Component>& component)-> bool
	{
		if (component->GetType() == type)
		{
			component->M_Destroy();
			return true;
		}
		return false;
	});
}

void Object::RemoveComponents(ComponentType type)
{
	if (type == ComponentType::EMPTY)
	{
		for (auto& component : m_Components)
		{
			component->M_Destroy();
		}
		m_Components.clear();
	}
	m_Components.remove_if([type](std::unique_ptr<Component>& component)->bool{
		if (type == component->GetType())
		{
			component->M_Destroy();
			return true;
		}
		return false;
	});
}

void Object::UpdateSelfAndChild()
{
	if (!transform.IsDirty())
		return;

	ForceUpdateSelfAndChild();
}

void Object::ForceUpdateSelfAndChild()
{
	if (m_Parent)
		transform.ComputeModelMatrix(m_Parent->transform.GetModelMatrix());
	else
		transform.ComputeModelMatrix();

	for (auto&& child : children)
	{
		child->ForceUpdateSelfAndChild();
	}
}

void Object::Serialize(XMLElement* object)
{
	object->SetAttribute("name", name.c_str());
	object->SetAttribute("active", StringUtil::WriteBool(m_Active).c_str());
	transform.Serialize(object);
	object->DeleteChildren();
	auto components = object->InsertNewChildElement("components");
	auto objects = object->InsertNewChildElement("objects");
	for (auto& component : m_Components)
	{
		component->Serialize(components);
	}
	SerializeChildren(objects);
}

void Object::Deserialize(XMLElement* object)
{
	name = object->Attribute("name","nameless");
	m_Active = StringUtil::ParseBool(object->Attribute("active", "true"));
	transform.Deserialize(object);
	m_Components.clear();
	auto components = object->FirstChildElement("components");
	auto objects = object->FirstChildElement("objects");
	if (components != nullptr)
		for (auto child = components->FirstChildElement(); child != nullptr;
			child =
			child->NextSiblingElement())
		{
			m_Components.emplace_back(ObjectUtil::ParseComponent(child));
		}
	if (objects != nullptr) DeserializeChildren(objects);
}

void Object::SerializeChildren(XMLElement* objects)
{
	for (auto& child : children)
	{
		auto childElement = objects->InsertNewChildElement("object");
		child->Serialize(childElement);
	}
}

void Object::DeserializeChildren(XMLElement* objects)
{
	for (auto object = objects->FirstChildElement(); object != nullptr; object =
		object->NextSiblingElement())
	{
		Object child;
		child.m_Parent = this;
		child.Deserialize(object);
	}
}

void Object::M_Destroy()
{
	RemoveChildren();
	RemoveComponents();
}

size_t Object::IdMaker()
{
	return Entry::scene.current->GetId();
}
