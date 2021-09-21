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
	m_scene->setGravity({ 0, 0 });
	m_scene->setTimeStep(0.01f);

	_cue = new Sphere({ -80,10 }, { 0.0f,0.0f }, 4.0f, 4.0f, { 0.0f,0.5f,0.25f,1.0f });
	_ball2 = new Sphere({ 7, 15 }, { 0.0f,0.0f }, 3.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball3 = new Sphere({ 0, 10 }, { 0.0f,0.0f }, 5.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball4 = new Sphere({ 7, 5 }, { 0.0f,0.0f }, 7.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball5 = new Sphere({ 14,20 }, { 0.0f,0.0f }, 3.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball6 = new Sphere({ 14,10 }, { 0.0f,0.0f }, 8.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball7 = new Sphere({ 14,0 }, { 0.0f,0.0f }, 2.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball8 = new Sphere({ 21,-5 }, { 0.0f,0.0f }, 6.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball9 = new Sphere({ 21,5 }, { 0.0f,0.0f }, 9.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball10 = new Sphere({ 21,15 }, { 0.0f,0.0f }, 4.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball11 = new Sphere({ 21,25 }, { 0.0f,0.0f }, 10.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball12 = new Sphere({ 28,30 }, { 0.0f,0.0f }, 6.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball13 = new Sphere({ 28,20 }, { 0.0f,0.0f }, 8.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball14 = new Sphere({ 28,10 }, { 0.0f,0.0f }, 10.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball15 = new Sphere({ 28,0 }, { 0.0f,0.0f }, 10.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	_ball16 = new Sphere({ 28,-10 }, { 0.0f,0.0f }, 10.0f, 4.0f, { 0.25f,0.75f,0.75f,1.0f });
	Plane* plane1 = new Plane({ 0.0f,1.0f }, -55.0f, { 1.0f,1.0f,1.0f,1.0f });
	Plane* plane2 = new Plane({ 0.0f,-1.0f }, -55.0f, { 1.0f,1.0f,1.0f,1.0f });
	Plane* plane3 = new Plane({ 1.0f,0.0f }, -99.9f, { 1.0f,1.0f,1.0f,1.0f });
	Plane* plane4 = new Plane({ -1.0f,0.0f }, -100.0f, { 1.0f,1.0f,1.0f,1.0f });

	m_scene->addActor(_cue);
	m_scene->addActor(_ball2);
	m_scene->addActor(_ball3);
	m_scene->addActor(_ball4);
	m_scene->addActor(_ball5);
	m_scene->addActor(_ball6);
	m_scene->addActor(_ball7);
	m_scene->addActor(_ball8);
	m_scene->addActor(_ball9);
	m_scene->addActor(_ball10);
	m_scene->addActor(_ball11);
	m_scene->addActor(_ball12);
	m_scene->addActor(_ball13);
	m_scene->addActor(_ball14);
	m_scene->addActor(_ball15);
	m_scene->addActor(_ball16);
	m_scene->addActor(plane1);
	m_scene->addActor(plane2);
	m_scene->addActor(plane3);
	m_scene->addActor(plane4);

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
	if (input->isMouseButtonDown(aie::INPUT_MOUSE_BUTTON_LEFT) && !_cueHit) {
		_cue->applyForce({250 , 0});
		_cueHit = true;
	}
	if (input->isKeyDown(aie::INPUT_KEY_R)) {
		//set positions of all
		_cue->setPosition({ -80,10 });
		_ball2->setPosition({ 7, 15 });
		_ball3->setPosition({ 0, 10 });
		_ball4->setPosition({ 7, 5 });
		_ball5->setPosition({ 14,20 });
		_ball6->setPosition({ 14,10 });
		_ball7->setPosition({ 14,0 });
		_ball8->setPosition({ 21,-5 });
		_ball9->setPosition({ 21,5 });
		_ball10->setPosition({ 21,15 });
		_ball11->setPosition({ 21,25 });
		_ball12->setPosition({ 28,30 });
		_ball13->setPosition({ 28,20 });
		_ball14->setPosition({ 28,10 });
		_ball15->setPosition({ 28,0 });
		_ball16->setPosition({ 28,-10 });
		//set velocity of all
		_cue->SetVelocity({ 0,0 });
		_ball2->SetVelocity({ 0,0 });
		_ball3->SetVelocity({ 0,0 });
		_ball4->SetVelocity({ 0,0 });
		_ball5->SetVelocity({ 0,0 });
		_ball6->SetVelocity({ 0,0 });
		_ball7->SetVelocity({ 0,0 });
		_ball8->SetVelocity({ 0,0 });
		_ball9->SetVelocity({ 0,0 });
		_ball10->SetVelocity({ 0,0 });
		_ball11->SetVelocity({ 0,0 });
		_ball12->SetVelocity({ 0,0 });
		_ball13->SetVelocity({ 0,0 });
		_ball14->SetVelocity({ 0,0 });
		_ball15->SetVelocity({ 0,0 });
		_ball16->SetVelocity({ 0,0 });

		_cueHit = false;
	}
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
