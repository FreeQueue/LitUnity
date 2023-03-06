#pragma once
#include <glm/ext/quaternion_float.hpp>
#include "ISerializable.h"

namespace Game
{
	class Transform : public ISerializable
	{
	protected:
		//Local space information
		glm::vec3 m_Pos = {0.0f, 0.0f, 0.0f};
		glm::quat m_Rotation = glm::quat({0.0f, 0.0f, 0.0f}); //In degrees
		glm::vec3 m_Scale = {1.0f, 1.0f, 1.0f};

		//Global space information concatenate in matrix
		glm::mat4 m_ModelMatrix = glm::mat4(1.0f);

		//Dirty flag
		bool m_IsDirty = true;

	protected:
		glm::mat4 GetLocalModelMatrix();

	public:
		void ComputeModelMatrix();

		void ComputeModelMatrix(const glm::mat4& parentGlobalModelMatrix);
		void AddLocalPosition(const glm::vec3& addPosition);

		void AddLocalRotation(const glm::quat& addRotation);

		void AddLocalScale(const glm::vec3& addScale);
		void SetLocalPosition(const glm::vec3& newPosition);

		void SetLocalRotation(const glm::quat& newRotation);

		void SetLocalScale(const glm::vec3& newScale);

		glm::vec3 GetGlobalPosition() const;

		const glm::vec3& GetLocalPosition() const;

		const glm::quat& GetLocalRotation() const;

		const glm::vec3& GetLocalScale() const;

		const glm::mat4& GetModelMatrix() const;

		glm::vec3 GetRight() const;

		glm::vec3 GetUp() const;

		glm::vec3 GetBackward() const;

		glm::vec3 GetForward() const;

		glm::vec3 GetGlobalScale() const;

		bool IsDirty() const;
		void Serialize(tinyxml2::XMLElement* element) override;
		void Deserialize(tinyxml2::XMLElement* element) override;
	};
}
