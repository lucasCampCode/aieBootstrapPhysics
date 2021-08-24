#include "RigidBody.h"
#include "glm/ext.hpp"

RigidBody::RigidBody(ShapeType shapeID, glm::vec2 position, glm::vec2 velocity, float orientaion, float mass) : PhysicsObject(shapeID)
{
	m_position = position;
	m_velocity = velocity;
	m_orientation = orientaion;
	m_mass = mass;
}

RigidBody::~RigidBody()
{
}

void RigidBody::fixedUpdate(glm::vec2 gravity, float timeStep)
{
	m_position += m_velocity * timeStep;
	applyForce(gravity * m_mass * timeStep);
}

void RigidBody::resolveCollision(RigidBody* other)
{
	//j is impulse magnitude
	// e is the coefficient of elasticity
	//Vrel is the relative velocity before collision
	//n is the collision normal
	//MA is the mass of object A
	//Mb is the mass of object B
	glm::vec2 collisionNormal = glm::normalize(other->getPosition() - getPosition());
	glm::vec2 relativeVelocity = other->getVelocity() - getVelocity();
	float massA = getMass();
	float massB = other->getMass();

	float elasticity = 1.0f;
	// j = ((-(1+e)*Vrel) dot n)/ (n dot(n*(1/MA+1/MA)))
	float j = glm::dot(-(1 + elasticity) * (relativeVelocity), collisionNormal) / 
			  ((1 / massA) + (1 / massB));

	glm::vec2 impulse = collisionNormal * j;
	applyForceToOther(other, impulse);
}

void RigidBody::applyForce(glm::vec2 force)
{
	glm::vec2 acceleration = force / m_mass;
	m_velocity += acceleration;
}

void RigidBody::applyForceToOther(RigidBody* other, glm::vec2 force)
{
	other->applyForce(force);
	applyForce(-force);
}
