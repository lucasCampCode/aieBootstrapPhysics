#include "Plane.h"
#include "Gizmos.h"
#include "RigidBody.h"
#include "glm/ext.hpp"
Plane::Plane(glm::vec2 normal, float distance,glm::vec4 color) :PhysicsObject(ShapeType::PLANE)
{
	m_normal = glm::normalize(normal);
	m_distance = distance;
	m_color = color;
}

Plane::~Plane()
{
}

void Plane::fixedUpdate(glm::vec2 gravity, float deltaTime)
{
}

void Plane::draw()
{
	float lineSegmentLength = 300;
	glm::vec2 centerPoint = m_normal * m_distance;
	glm::vec2 parallel(m_normal.y, -m_normal.x);
	
	glm::vec2 start = centerPoint + (parallel * lineSegmentLength);
	glm::vec2 end = centerPoint - (parallel * lineSegmentLength);

	aie::Gizmos::add2DLine(start, end, m_color);
}

void Plane::resolveCollision(RigidBody* other)
{
	// j = (Va-((1+e)Va dot n))*n
	// j is the impluse of collision
	//e is the coefficent of elasticity
	//Va is the velocity of other object
	//n is the plane normal
	float elasticity = 1.0f;
	glm::vec2 VelocityA = other->getVelocity();
	glm::vec2 planeNormal = getNormal();

	glm::vec2 j = (other->getMass()* planeNormal * -(1 + elasticity) * glm::dot(VelocityA, planeNormal)) ;

	other->applyForce(j);

}
