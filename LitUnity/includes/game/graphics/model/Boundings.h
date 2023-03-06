#pragma once
#include <glm/ext/vector_float3.hpp>
#include <array>

namespace Game
{
	class Model;
	class Transform;
	class Camera;

	struct Plan
	{
		glm::vec3 normal = {0.f, 1.f, 0.f}; // unit vector
		float distance = 0.f; // Distance with origin

		Plan() = default;

		Plan(const glm::vec3& p1, const glm::vec3& norm);

		float GetSignedDistanceToPlan(const glm::vec3& point) const;
	};

	struct Frustum
	{
		Plan topFace;
		Plan bottomFace;

		Plan rightFace;
		Plan leftFace;

		Plan farFace;
		Plan nearFace;
		static Frustum CreateFrustumFromCamera(const Camera& cam, float aspect,
												float fovY, float zNear,
												float zFar);
	};

	struct BoundingVolume
	{
		virtual bool IsOnFrustum(const Frustum& camFrustum,
								const Transform& transform) const = 0;

		virtual bool IsOnOrForwardPlan(const Plan& plan) const = 0;

		bool IsOnFrustum(const Frustum& camFrustum) const;
	};

	struct Sphere : public BoundingVolume
	{
		glm::vec3 center{0.f, 0.f, 0.f};
		float radius{0.f};

		Sphere(const glm::vec3& inCenter, float inRadius);

		bool IsOnOrForwardPlan(const Plan& plan) const final;

		bool IsOnFrustum(const Frustum& camFrustum,
						const Transform& transform) const final;

		static Sphere GenerateSphereBv(const Model& model);
	};

	struct SquareAABB : public BoundingVolume
	{
		glm::vec3 center{0.f, 0.f, 0.f};
		float extent{0.f};

		SquareAABB(const glm::vec3& inCenter, float inExtent);

		bool IsOnOrForwardPlan(const Plan& plan) const final;

		bool IsOnFrustum(const Frustum& camFrustum,
						const Transform& transform) const final;;
	};

	struct AABB : public BoundingVolume
	{
		glm::vec3 center{0.f, 0.f, 0.f};
		glm::vec3 extents{0.f, 0.f, 0.f};

		AABB(const glm::vec3& min, const glm::vec3& max);

		AABB(const glm::vec3& inCenter, float iI, float iJ, float iK);

		std::array<glm::vec3, 8> GetVertice() const;

		//see https://gdbooks.gitbooks.io/3dcollisions/content/Chapter2/static_aabb_plan.html
		bool IsOnOrForwardPlan(const Plan& plan) const final;

		bool IsOnFrustum(const Frustum& camFrustum,
						const Transform& transform) const final;

		static AABB* GenerateAabb(const Model& model);
	};
}
