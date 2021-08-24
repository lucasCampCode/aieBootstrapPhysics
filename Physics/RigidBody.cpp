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

void RigidBody::resolveCollision(RigidBody* actor)
{
	glm::vec2 normal = glm::normalize(actor->getPosition() - m_position);
	glm::vec2 relativeVelocity = actor->getVelocity() - m_velocity;

	float elasticity = 0.95;
	float j = glm::dot(-(1 + elasticity) * (relativeVelocity), normal) / 
			  ((1 / m_mass) + (1 / actor->getMass()));
	glm::vec2 force = normal * j;
	applyForceToActor(actor, force);
}

void RigidBody::applyForce(glm::vec2 force)
{
	glm::vec2 acceleration = force / m_mass;
	m_velocity += acceleration;
}

void RigidBody::applyForceToActor(RigidBody* actor2, glm::vec2 force)
{
	actor2->applyForce(force);
	applyForce(-force);
}
