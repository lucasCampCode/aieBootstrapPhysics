#include "PhysicsGame.h"
#include "Input.h"
#include "Font.h"
#include "Gizmos.h"
#include "glm/ext.hpp"
#include "Sphere.h"
#include "Plane.h"

PhysicsGame::PhysicsGame()
{
}

PhysicsGame::~PhysicsGame()
{
}

bool PhysicsGame::startup()
{
	aie::Gizmos::create(255U, 255U, 65535U, 65535U);

	m_Render = new aie::Renderer2D();
	setBackgroundColour(0.25f, 0.25f, 0.25f);

	m_Font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_scene = new PhysicsScene();
	m_scene->setGravity({ 0, -9.81 });
	m_scene->setTimeStep(0.01f);

	Sphere* ball = new Sphere({ 10, 15 }, { 0.0f,0.0f }, 4.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	m_scene->addActor(ball);

	Sphere* ball2 = new Sphere({ -20,10 }, { 0.0f,0.0f }, 4.0f, 4.0f, { 0.0f,0.5f,0.25f,1.0f });
	m_scene->addActor(ball2);

	Plane* plane1 = new Plane({ 0.0f,1.0f }, -30.0f, { 1.0f,1.0f,1.0f,1.0f });
	m_scene->addActor(plane1);

	//Plane* plane2 = new Plane({ -0.8f,1.0f }, -30.0f, { 1.0f,1.0f,1.0f,1.0f });
	//m_scene->addActor(plane2);


	m_Timer = 0;

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_Font;
	delete m_Render;
	delete m_scene;
}

void PhysicsGame::update(float deltaTime)
{
	//get input instance
	aie::Input* input = aie::Input::getInstance();

	aie::Gizmos::clear();
	
	m_scene->update(deltaTime);

	//quits application when escape is pushed
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

void PhysicsGame::draw()
{
	//clear previous screen
	clearScreen();
	m_Render->begin();

	m_scene->draw();

	static float aspectRatio = 16.0f / 9.f;
	aie::Gizmos::draw2D(glm::ortho<float>(-100, 100, -100 / aspectRatio, 100 / aspectRatio, -1.0f, 1.0f));

	m_Render->setRenderColour(1.0f, 1.0f, 1.0f);
	//draw the fps
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_Render->drawText(m_Font, fps , 0.0f,0.0f);

	m_Render->end();

}
