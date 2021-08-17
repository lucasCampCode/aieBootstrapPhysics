#pragma once
#include "Application.h" 
#include "Renderer2D.h"

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
	float m_timer;
};

