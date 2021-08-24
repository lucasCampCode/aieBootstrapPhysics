#include "PhysicsScene.h"
#include "PhysicsObject.h"
#include "Sphere.h"
#include "Plane.h"
#include "glm/ext.hpp"
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

		checkCollision();
		
	}
}


void PhysicsScene::draw()
{
	for (PhysicsObject* actor : m_actors) {
		actor->draw();
	}
}
typedef bool(*fn)(PhysicsObject*, PhysicsObject*);

static fn collisionFunctionArray[] = {
	PhysicsScene::planeToPlane,PhysicsScene::planeToSphere,PhysicsScene::planeToBox,
	PhysicsScene::sphereToPlane,PhysicsScene::sphereToSphere,PhysicsScene::sphereToBox,
	PhysicsScene::boxToPlane,PhysicsScene::boxToSphere,PhysicsScene::boxToBox
};
void PhysicsScene::checkCollision()
{
	auto last = m_actors.end();
	last--;
	for (auto outer = m_actors.begin(); outer != last; outer++) {
		auto innerStart = outer;
		innerStart++;
		for (auto inner = innerStart; inner != m_actors.end(); inner++) {
			PhysicsObject* object1 = *outer;
			PhysicsObject* object2 = *inner;
			int shapeId1 = (int)(object1->getShapeID());
			int shapeId2 = (int)(object2->getShapeID());

			int functionIdx = (shapeId1 * (int)ShapeType::LENGTH) + shapeId2;
			fn collisionFuntionPtr = collisionFunctionArray[functionIdx];
			if (collisionFuntionPtr != nullptr) {
				collisionFuntionPtr(object1, object2);
			}
		}
	}
}
bool PhysicsScene::sphereToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere1 = dynamic_cast<Sphere*>(obj1);
	Sphere* sphere2 = dynamic_cast<Sphere*>(obj2);
	
	if (sphere1 != nullptr && sphere2 != nullptr) {
		glm::vec2 direction = glm::normalize(sphere2->getPosition() - sphere1->getPosition());

		float powX = glm::pow((sphere2->getPosition().x - sphere1->getPosition().x), 2);
		float powY = glm::pow((sphere2->getPosition().y - sphere1->getPosition().y), 2);
		float magnitude = glm::sqrt(powX + powY);

		if (magnitude < sphere1->getRadius() + sphere2->getRadius()) {
			sphere1->resolveCollision(sphere2);
		}
	}

	return false;
}

bool PhysicsScene::sphereToBox(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}

bool PhysicsScene::boxToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}

bool PhysicsScene::boxToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}

bool PhysicsScene::boxToBox(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}

bool PhysicsScene::sphereToPlane(PhysicsObject* obj1, PhysicsObject* obj2)
{
	Sphere* sphere = dynamic_cast<Sphere*>(obj1);
	Plane* plane = dynamic_cast<Plane*>(obj2);
	if (sphere && plane) {
		//D1 (C dot N) - D - R
		//D1 is the distance from the sphere to the plane surface
		//C is the center of the Sphere
		//N is the normal of the plane
		//D is the distance from the plane to the origin
		//R is the tadius of the sphere
		glm::vec2 sphereCenter = sphere->getPosition();
		glm::vec2 planeNormal = plane->getNormal();
		float planeDistance = plane->getDistance();
		float sphereRadius = sphere->getRadius();
		float intersectionDistance = glm::dot(sphereCenter, planeNormal) - planeDistance - sphereRadius;
		if (intersectionDistance <= 0) {
			plane->resolveCollision(sphere);
			return true;
		}
	}
	return false;
}

bool PhysicsScene::planeToSphere(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return sphereToPlane(obj2, obj1);
}

bool PhysicsScene::planeToBox(PhysicsObject* obj1, PhysicsObject* obj2)
{
	return false;
}

