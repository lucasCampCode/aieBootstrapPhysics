#pragma once
#include "Application.h" 
#include "Renderer2D.h"
#include "phys"

class PhysicsGame : public aie::Application
{
public:
	PhysicsGame();
	virtual ~PhysicsGame();


	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();
private:
	
	aie::Font* m_Font;
	aie::Renderer2D* m_Render;

	float m_Timer;
};

