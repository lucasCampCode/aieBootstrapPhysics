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

	void setGravity
};

