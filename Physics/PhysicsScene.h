#pragma once
#include "glm/vec2.hpp"
#include <set>
class PhysicsObject;

class PhysicsScene
{
public:
	PhysicsScene();
	~PhysicsScene();

	void addActor(PhysicsObject* actor);
	void removeActor(PhysicsObject* actor);
	void update(float deltaTime);
	void draw();
	
	static bool spherToSphere(PhysicsObject* obj1,PhysicsObject* obj2);

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const { return m_gravity; }

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() { return m_timeStep; }

	protected:
		glm::vec2 m_gravity;
		float m_timeStep;
		std::set<PhysicsObject*> m_actors;
};

