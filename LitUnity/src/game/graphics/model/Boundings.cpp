#include "game/graphics/model/Boundings.h"
#include "game/base/Object.h"
#include "game/base/Transform.h"
#include "game/scene/Camera.h"
#include "game/SourceHeader.h"

Plan::Plan(const vec3& p1, const vec3& norm)
	: normal(normalize(norm)),
	distance(dot(normal, p1))
{
}

float Plan::GetSignedDistanceToPlan(const vec3& point) const
{
	return dot(normal, point) - distance;
}

bool BoundingVolume::IsOnFrustum(const Frustum& camFrustum) const
{
	return (IsOnOrForwardPlan(camFrustum.leftFace) &&
		IsOnOrForwardPlan(camFrustum.rightFace) &&
		IsOnOrForwardPlan(camFrustum.topFace) &&
		IsOnOrForwardPlan(camFrustum.bottomFace) &&
		IsOnOrForwardPlan(camFrustum.nearFace) &&
		IsOnOrForwardPlan(camFrustum.farFace));
}

Sphere::Sphere(const vec3& inCenter, float inRadius) : BoundingVolume{}, center{inCenter}, radius{inRadius}
{
}

bool Sphere::IsOnOrForwardPlan(const Plan& plan) const
{
	return plan.GetSignedDistanceToPlan(center) > -radius;
}

bool Sphere::IsOnFrustum(const Frustum& camFrustum, const Transform& transform) const
{
	//Get global scale thanks to our transform
	const vec3 globalScale = transform.GetGlobalScale();

	//Get our global center with process it with the global model matrix of our transform
	const vec3 globalCenter{transform.GetModelMatrix() * vec4(center, 1.f)};

	//To wrap correctly our shape, we need the maximum scale scalar.
	const float maxScale = std::max(std::max(globalScale.x, globalScale.y), globalScale.z);

	//Max scale is assuming for the diameter. So, we need the half to apply it to our radius
	Sphere globalSphere(globalCenter, radius * (maxScale * 0.5f));

	//Check Firstly the result that have the most chance to failure to avoid to call all functions.
	return (globalSphere.IsOnOrForwardPlan(camFrustum.leftFace) &&
		globalSphere.IsOnOrForwardPlan(camFrustum.rightFace) &&
		globalSphere.IsOnOrForwardPlan(camFrustum.farFace) &&
		globalSphere.IsOnOrForwardPlan(camFrustum.nearFace) &&
		globalSphere.IsOnOrForwardPlan(camFrustum.topFace) &&
		globalSphere.IsOnOrForwardPlan(camFrustum.bottomFace));
}

SquareAABB::SquareAABB(const vec3& inCenter, float inExtent) : BoundingVolume{}, center{inCenter}, extent{inExtent}
{
}

bool SquareAABB::IsOnOrForwardPlan(const Plan& plan) const
{
	// Compute the projection interval radius of b onto L(t) = b.c + t * p.n
	const float r = extent * (std::abs(plan.normal.x) + std::abs(plan.normal.y) + std::abs(plan.normal.z));
	return -r <= plan.GetSignedDistanceToPlan(center);
}

bool SquareAABB::IsOnFrustum(const Frustum& camFrustum, const Transform& transform) const
{
	//Get global scale thanks to our transform
	const vec3 globalCenter{transform.GetModelMatrix() * vec4(center, 1.f)};

	// Scaled orientation
	const vec3 right = transform.GetRight() * extent;
	const vec3 up = transform.GetUp() * extent;
	const vec3 forward = transform.GetForward() * extent;

	const float newIi = std::abs(dot(vec3{1.f, 0.f, 0.f}, right)) +
		std::abs(dot(vec3{1.f, 0.f, 0.f}, up)) +
		std::abs(dot(vec3{1.f, 0.f, 0.f}, forward));

	const float newIj = std::abs(dot(vec3{0.f, 1.f, 0.f}, right)) +
		std::abs(dot(vec3{0.f, 1.f, 0.f}, up)) +
		std::abs(dot(vec3{0.f, 1.f, 0.f}, forward));

	const float newIk = std::abs(dot(vec3{0.f, 0.f, 1.f}, right)) +
		std::abs(dot(vec3{0.f, 0.f, 1.f}, up)) +
		std::abs(dot(vec3{0.f, 0.f, 1.f}, forward));

	const SquareAABB globalAABB(globalCenter, std::max(std::max(newIi, newIj), newIk));

	return (globalAABB.IsOnOrForwardPlan(camFrustum.leftFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.rightFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.topFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.bottomFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.nearFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.farFace));
}

AABB::AABB(const vec3& min, const vec3& max) : BoundingVolume{}, center{(max + min) * 0.5f},
												extents{max.x - center.x, max.y - center.y, max.z - center.z}
{
}

AABB::AABB(const vec3& inCenter, float iI, float iJ, float iK) : BoundingVolume{}, center{inCenter},
																extents{iI, iJ, iK}
{
}

std::array<vec3, 8> AABB::GetVertice() const
{
	std::array<vec3, 8> vertice{};
	vertice[0] = {center.x - extents.x, center.y - extents.y, center.z - extents.z};
	vertice[1] = {center.x + extents.x, center.y - extents.y, center.z - extents.z};
	vertice[2] = {center.x - extents.x, center.y + extents.y, center.z - extents.z};
	vertice[3] = {center.x + extents.x, center.y + extents.y, center.z - extents.z};
	vertice[4] = {center.x - extents.x, center.y - extents.y, center.z + extents.z};
	vertice[5] = {center.x + extents.x, center.y - extents.y, center.z + extents.z};
	vertice[6] = {center.x - extents.x, center.y + extents.y, center.z + extents.z};
	vertice[7] = {center.x + extents.x, center.y + extents.y, center.z + extents.z};
	return vertice;
}

bool AABB::IsOnOrForwardPlan(const Plan& plan) const
{
	// Compute the projection interval radius of b onto L(t) = b.c + t * p.n
	const float r = extents.x * std::abs(plan.normal.x) + extents.y * std::abs(plan.normal.y) +
		extents.z * std::abs(plan.normal.z);

	return -r <= plan.GetSignedDistanceToPlan(center);
}

bool AABB::IsOnFrustum(const Frustum& camFrustum, const Transform& transform) const
{
	//Get global scale thanks to our transform
	const vec3 globalCenter{transform.GetModelMatrix() * vec4(center, 1.f)};

	// Scaled orientation
	const vec3 right = transform.GetRight() * extents.x;
	const vec3 up = transform.GetUp() * extents.y;
	const vec3 forward = transform.GetForward() * extents.z;

	const float newIi = std::abs(dot(vec3{1.f, 0.f, 0.f}, right)) +
		std::abs(dot(vec3{1.f, 0.f, 0.f}, up)) +
		std::abs(dot(vec3{1.f, 0.f, 0.f}, forward));

	const float newIj = std::abs(dot(vec3{0.f, 1.f, 0.f}, right)) +
		std::abs(dot(vec3{0.f, 1.f, 0.f}, up)) +
		std::abs(dot(vec3{0.f, 1.f, 0.f}, forward));

	const float newIk = std::abs(dot(vec3{0.f, 0.f, 1.f}, right)) +
		std::abs(dot(vec3{0.f, 0.f, 1.f}, up)) +
		std::abs(dot(vec3{0.f, 0.f, 1.f}, forward));

	const AABB globalAABB(globalCenter, newIi, newIj, newIk);

	return (globalAABB.IsOnOrForwardPlan(camFrustum.leftFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.rightFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.topFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.bottomFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.nearFace) &&
		globalAABB.IsOnOrForwardPlan(camFrustum.farFace));
}

Frustum Frustum::CreateFrustumFromCamera(const Camera& cam, float aspect, float fovY, float zNear, float zFar)
{
	Frustum frustum;
	Transform& camTransform=cam.GetObject()->transform;
	auto position=camTransform.GetGlobalPosition();
	auto front=camTransform.GetForward();
	auto right=camTransform.GetRight();
	auto up=camTransform.GetUp();
	
	const float halfVSide = zFar * tanf(fovY * .5f);
	const float halfHSide = halfVSide * aspect;
	const vec3 frontMultFar = zFar * cam.GetForward();
	frustum.nearFace = {position + zNear * front, front};
	frustum.farFace = {position + frontMultFar, -front};
	frustum.rightFace = {position, cross(up, frontMultFar + right * halfHSide)};
	frustum.leftFace = {position, cross(frontMultFar -right * halfHSide,up)};
	frustum.topFace = {position, cross(right, frontMultFar - up * halfVSide)};
	frustum.bottomFace = {position, cross(frontMultFar + up* halfVSide, right)};

	return frustum;
}

AABB* AABB::GenerateAabb(const Model& model)
{
	auto minAABB = vec3(std::numeric_limits<float>::max());
	auto maxAABB = vec3(std::numeric_limits<float>::min());
	for (auto&& mesh : model.meshes)
	{
		for (auto&& vertex : mesh.vertices)
		{
			minAABB.x = std::min(minAABB.x, vertex.position.x);
			minAABB.y = std::min(minAABB.y, vertex.position.y);
			minAABB.z = std::min(minAABB.z, vertex.position.z);

			maxAABB.x = std::max(maxAABB.x, vertex.position.x);
			maxAABB.y = std::max(maxAABB.y, vertex.position.y);
			maxAABB.z = std::max(maxAABB.z, vertex.position.z);
		}
	}
	return new AABB(minAABB, maxAABB);
}

Sphere Sphere::GenerateSphereBv(const Model& model)
{
	auto minAABB = vec3(std::numeric_limits<float>::max());
	auto maxAABB = vec3(std::numeric_limits<float>::min());
	for (auto&& mesh : model.meshes)
	{
		for (auto&& vertex : mesh.vertices)
		{
			minAABB.x = std::min(minAABB.x, vertex.position.x);
			minAABB.y = std::min(minAABB.y, vertex.position.y);
			minAABB.z = std::min(minAABB.z, vertex.position.z);

			maxAABB.x = std::max(maxAABB.x, vertex.position.x);
			maxAABB.y = std::max(maxAABB.y, vertex.position.y);
			maxAABB.z = std::max(maxAABB.z, vertex.position.z);
		}
	}

	return Sphere((maxAABB + minAABB) * 0.5f, length(minAABB - maxAABB));
}
