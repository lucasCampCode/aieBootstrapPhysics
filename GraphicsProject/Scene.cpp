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
	m_camera.setTransform(
		glm::lookAt(
			{ 2.0f,2.0f,2.0f },
			glm::vec3(0.0f),
			glm::vec3(0.0f, 1.0f, 0.0f)
		)
	);
		
	m_projectionMatrix = glm::perspective(
		m_camera.getFieldOfView() * glm::pi<float>() / 180,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
	);
}

void Scene::update(float deltaTime)
{
	
}

void Scene::draw(aie::ShaderProgram* shader)
{
	m_quad.draw(shader);
}

void Scene::end()
{
}

glm::mat4 Scene::getProjectionView()
{
	return m_projectionMatrix * m_camera.getTransform();
}

float Scene::TimeStep(float& curTime, float& step)
{
	if (curTime > 1 || curTime < 0)
		step *= -1;

	return 0.0f;
}
