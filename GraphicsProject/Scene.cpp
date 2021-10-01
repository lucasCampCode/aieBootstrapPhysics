#include "Scene.h"
#include "glm/ext.hpp"
Scene::Scene(int width, int height)
{
	m_width = width;
	m_height = height;
}
void Scene::start()
{
	m_quad.start();

	//create camera transforms
	m_viewMatrix = glm::lookAt(
		{ 10.0f,10.0f,10.0f },
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
	m_projectionMatrix = glm::perspective(
		glm::pi<float>() / 4.0f,
		(float)m_width / (float)m_height,
		0.001f,
		1000.0f
	);
}

void Scene::update()
{
	
	m_viewMatrix = glm::lookAt(
		{ 10.0f,10.0f,10.0f },
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	);
}

void Scene::draw()
{
	m_quad.draw();
}

void Scene::end()
{
}

glm::mat4 Scene::getProjectionViewModel()
{
	return m_projectionMatrix * m_viewMatrix * m_quad.getTrasform();
}
