#pragma once
#include "ISerializable.h"

namespace Game
{
	class Object;
	class Transform;

	enum class ComponentType
	{
		EMPTY,
		LIGHT,
		CAMERA,
		MODEL,
		EFFECT,
	};

	class Component : public ISerializable
	{
	public:
		const size_t id = 0;

	protected:
		bool m_Active = false;
		Object* m_Object = nullptr;

	public:
		virtual ComponentType GetType() const;

		Component() = default;
		explicit Component(Object* object);
		Object* GetObject() const;
		bool IsActive() const;
		void SetActive(bool active);
		void Destroy();
		Transform* GetTransform();
		virtual void Awake();
		virtual void OnEnable();
		virtual void Update();
		virtual void OnDisable();
		virtual void OnDestroy();

	protected:
		friend class Object;
		void M_Destroy();
		size_t IdMaker();
	};
}
