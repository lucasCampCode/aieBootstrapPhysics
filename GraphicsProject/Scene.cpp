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

	if (!m_earthDiffuse.load("earth_diffuse.jpg")) {
		printf("Failed to load texture");
	}

	m_camera.setPosition({ 0.0f,1.0f,0.0f });
	m_camera.setPitch(-45.0f);
}

void Scene::update(float deltaTime)
{
	m_camera.update(deltaTime, m_window);
}

void Scene::draw()
{
	int program = -1;
	glGetIntegerv(GL_CURRENT_PROGRAM, &program);
	if (program == -1)
		printf("no shader bound.\n");

	int diffuseTextureUniform = glGetUniformLocation(program,"diffuseTexture");
	if (diffuseTextureUniform >= 0)
		glUniform1i(diffuseTextureUniform, 0);
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D,m_earthDiffuse.getHandle());

	m_quad.draw();
}

void Scene::end()
{
}

glm::mat4 Scene::getProjectionViewModel()
{
	return m_camera.getProjectionMatrix(m_width, m_height) * m_camera.getViewMatrix() * m_quad.getTrasform();
}

float Scene::TimeStep(float& curTime, float& step)
{
	curTime;
	if (curTime > 1 || curTime < 0)
		step *= -1;
	return 0.0f;
}
