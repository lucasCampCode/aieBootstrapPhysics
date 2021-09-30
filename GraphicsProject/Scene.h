#pragma once
#include "Mesh.h"
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

	Mesh m_quad;

	glm::mat4 m_viewMatrix = glm::mat4(1);
	glm::mat4 m_projectionMatrix = glm::mat4(1);

};

