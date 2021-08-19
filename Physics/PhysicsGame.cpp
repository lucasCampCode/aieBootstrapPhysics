#include "PhysicsGame.h"
#include "Input.h"
#include "Font.h"

PhysicsGame::PhysicsGame()
{
}

PhysicsGame::~PhysicsGame()
{
}

bool PhysicsGame::startup()
{
	setBackgroundColour(0.0f,0.0f,0.0f);

	m_Render = new aie::Renderer2D();
	m_Font = new aie::Font("../assets/font/consolas.ttf", 32);
	m_physics = new PhysicsScene();

	m_Timer = 0;

	return true;
}

void PhysicsGame::shutdown()
{
	delete m_Font;
	delete m_Render;
}

void PhysicsGame::update(float deltaTime)
{
	//get input instance
	aie::Input* input = aie::Input::getInstance();

	m_physics->update(deltaTime);
	m_physics->draw();

	//quits application when escape is pushed
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

void PhysicsGame::draw()
{
	//clear previous screen
	clearScreen();
	m_Render->begin();

	m_Render->setRenderColour(1.0f, 1.0f, 1.0f);
	//draw the fps
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_Render->drawText(m_Font, fps , 0.0f,0.0f);

	m_Render->end();

}
