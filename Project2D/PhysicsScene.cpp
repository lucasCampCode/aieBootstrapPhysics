#include "PhysicsScene.h"
#include "PhysicsObject.h"

PhysicsScene::PhysicsScene(): m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{
}

PhysicsScene::~PhysicsScene()
{
}

void PhysicsScene::addActor(PhysicsObject* actor)
{
	m_actors.insert(actor);
}

void PhysicsScene::removeActor(PhysicsObject* actor)
{
	m_actors.erase(actor);
}

void PhysicsScene::update(float deltaTime)
{
	// update physics at a fixed time step
	static float accumulatedTime = 0.0f;
	accumulatedTime += deltaTime;
	//as long as there is enough time accumulated
	while (accumulatedTime >= m_timeStep) {
		//run fixed update for all physics objects
		for (PhysicsObject* actor : m_actors) {
			actor->fixedUpdate(m_gravity, m_timeStep); 
		}
		accumulatedTime -= m_timeStep;
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors) {
		actor.draw();
	}
}
