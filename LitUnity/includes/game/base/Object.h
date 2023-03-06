#pragma once
#include <list> //std::list
#include <memory> //std::unique_ptr
#include <string>
#include <vector>

#include "Component.h"
#include "Transform.h"

namespace Game
{
	class Object : public ISerializable
	{
	public:
		const size_t id = 0;
		Transform transform;
		std::string name;
		std::list<std::unique_ptr<Object>> children{};

	private:
		bool m_Active = true;
		Object* m_Parent = nullptr;
		std::list<std::unique_ptr<Component>> m_Components{};

	public:
		// constructor, expects a filepath to a 3D model.
		explicit Object(std::string name = "object", Object* parent = nullptr);
		bool IsActive() const;
		void SetActive(bool active);
		void Destroy();
		Object* GetParent() const;
		Component* GetComponent(ComponentType type) const;
		std::vector<Component*> GetComponents(ComponentType type) const;
		//Add child. Argument input is argument of any constructor that you create. By default you can use the default constructor and don't put argument input.
		Object* GetChild(const std::string& name) const;

		template <typename... TArgs>
		Object* AddChild(TArgs&... args);
		template <typename T, typename... TArgs>
		T* AddComponent(TArgs&... args);

		void RemoveChild(size_t id);
		void RemoveChildren();
		void RemoveComponent(size_t id);
		void RemoveComponent(ComponentType type);
		void RemoveComponents(ComponentType type = ComponentType::EMPTY);
		//Update transform if it was changed
		void UpdateSelfAndChild();
		//Force update of transform even if local space don't change
		void ForceUpdateSelfAndChild();

		void Serialize(tinyxml2::XMLElement* object) override;
		void Deserialize(tinyxml2::XMLElement* object) override;
		void SerializeChildren(tinyxml2::XMLElement* objects);
		void DeserializeChildren(tinyxml2::XMLElement* objects);

	private:
		void M_Destroy();
		size_t IdMaker();
	};

	template <typename... TArgs>
	Object* Object::AddChild(TArgs&... args)
	{
		children.emplace_back(std::make_unique<Object>(args...));
		const auto child = children.back().get();
		child->m_Parent = this;
		return child;
	}

	template <typename T, typename... TArgs>
	T* Object::AddComponent(TArgs&... args)
	{
		m_Components.emplace_back(std::make_unique<T>(args...));
		auto component = m_Components.back().get();
		component->Awake();
		component->SetActive(true);
		return dynamic_cast<T*>(component);
	}
}
