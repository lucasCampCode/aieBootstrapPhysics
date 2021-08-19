#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"
PhysicsScene::PhysicsScene() : m_timeStep(0.01f), m_gravity(glm::vec2(0,0))
{
}

PhysicsScene::~PhysicsScene()
{
	for (PhysicsObject* actor : m_actors) {
		delete actor;
	}
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

		int actorCount = m_actors.size();

		for(auto outer = m_actors.begin(); outer != --m_actors.end(); outer++) {
			for (auto inner = ++outer; inner != m_actors.end(); inner++) {
				PhysicsObject* object1 = *outer;
				PhysicsObject* object2 = *inner;

				spherToSphere(object1, object2);
			}
		}
		
	}
}

void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors) {
		actor->draw();
	}
}

bool PhysicsScene::spherToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);
	
	if (sphere1 != nullptr && sphere2 != nullptr) {
		glm::vec2 direction = sphere2->getPosition() - sphere1->getPosition();

	}

	return false;
}
