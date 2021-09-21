#pragma once
#include "Application.h" 
#include "Renderer2D.h"
#include "PhysicsScene.h"
class Sphere;

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
	PhysicsScene* m_scene;

	Sphere* _cue;
	Sphere* _ball2;
	Sphere* _ball3;
	Sphere* _ball4;
	Sphere* _ball5;
	Sphere* _ball6;
	Sphere* _ball7;
	Sphere* _ball8;
	Sphere* _ball9;
	Sphere* _ball10;
	Sphere* _ball11;
	Sphere* _ball12;
	Sphere* _ball13;
	Sphere* _ball14;
	Sphere* _ball15;
	Sphere* _ball16;
	
	float m_Timer;
	bool _cueHit = false;
};

