#pragma once
#include "Quad.h"
#include "glm/mat4x4.hpp"
class Scene
{
public:
	Scene(int width, int height);
	~Scene() {}

	void start();
	void update();
	void draw();
	void end();

	glm::mat4 getProjectionViewModel();

private:

	int m_width = 1280, m_height = 720;

	Quad m_quad = Quad({1.0f,0.5f,0.25f,1.0f});
	glm::vec3 m_cameraPos = glm::vec3();
	glm::mat4 m_viewMatrix = glm::mat4(1);
	glm::mat4 m_projectionMatrix = glm::mat4(1);

};

