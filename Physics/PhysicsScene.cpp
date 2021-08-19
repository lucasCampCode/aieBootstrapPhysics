#include "PhysicsScene.h"
#include "PhysicsObject.h"

PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
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
	//update physics at a fixed time step
	static float accumlatedTime = 0.0f;
	accumlatedTime += deltaTime;

	while (accumlatedTime >= m_timeStep) {
		for (PhysicsObject* actor : m_actors) {
			actor->fixedUpdate(m_gravity, m_timeStep);
		}
		accumlatedTime -= m_timeStep;
		
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors) {
		actor->draw();
	}
}
