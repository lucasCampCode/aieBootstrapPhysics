#pragma once
#include "Camera.h"
#include "Quad.h"
#include "glm/mat4x4.hpp"
class Scene
{
public:
	Scene(int width, int height);
	~Scene() {}

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	glm::mat4 getProjectionViewModel();

	float TimeStep(float& curTime, float& step);

private:

	int m_width = 1280, m_height = 720;

	Quad m_quad = Quad({1.0f,0.5f,0.25f,1.0f});
	glm::vec3 m_cameraPos = glm::vec3();
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1);

};

