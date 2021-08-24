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
	void checkCollision();

	void setGravity(const glm::vec2 gravity) { m_gravity = gravity; }
	glm::vec2 getGravity() const { return m_gravity; }

	void setTimeStep(const float timeStep) { m_timeStep = timeStep; }
	float getTimeStep() { return m_timeStep; }

	static bool planeToPlane(PhysicsObject* obj1, PhysicsObject* obj2) { return false; };
	static bool planeToSphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool planeToBox(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphereToPlane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphereToSphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool sphereToBox(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool boxToPlane(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool boxToSphere(PhysicsObject* obj1, PhysicsObject* obj2);
	static bool boxToBox(PhysicsObject* obj1, PhysicsObject* obj2);

private:
	glm::vec2 m_gravity;
	float m_timeStep;
	std::set<PhysicsObject*> m_actors;
};

