#include "Plane.h"
#include "Gizmos.h"
#include "RigidBody.h"
#include "glm/ext.hpp"
Plane::Plane(glm::vec2 normal, float distance,glm::vec4 color) :PhysicsObject(ShapeType::PLANE)
{
	m_normal = normal;
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

void Plane::resolveCollision(RigidBody* actor)
{
	float elasticity = 1;
	float j = glm::dot(actor->getVelocity() - (1 + elasticity) * actor->getVelocity(), m_normal);
	glm::vec2 force = m_normal * j;
	actor->applyForce(force);
}
