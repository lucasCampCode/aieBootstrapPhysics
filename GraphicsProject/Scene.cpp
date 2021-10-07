#include "Scene.h"
#include "glm/ext.hpp"
#include"GLFW/glfw3.h"
Scene::Scene(int width, int height)
{
	m_width = width;
	m_height = height;
}
void Scene::start()
{
	m_quad.setTransform(glm::mat4(10.0f));
	m_quad.setColor({ 1.0f,0.25f,0.0f,1.0f });
	m_quad.start();
	//init light
	m_light.setDirection(glm::vec3(-1.0f));
	m_light.setAmbient({ 0.0f, 0.5f, 0.0f, 1.0f });
	m_light.setDiffuse({ 0.6f, 0.6f, 1.0f, 1.0f });
	m_light.setSpecular({ 1.0f, 1.0f, 1.0f, 1.0f });
	m_light.setSpecularPower(5.0f);


	setXStepSpeed(0.5f);
	setYStepSpeed(0.5f);

	//create camera transforms
	m_camera.setTransform(glm::lookAt(
		{ 2.0f,2.0f,2.0f },
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	));
		
	m_projectionMatrix = glm::perspective(
		m_camera.getFieldOfView() * glm::pi<float>() / 180,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
	);
}

void Scene::update(float deltaTime)
{
	cameraMovement(deltaTime);
}

void Scene::draw(aie::ShaderProgram* shader)
{
	shader->bindUniform("cameraPosition", glm::vec4(m_cameraPos,1.0f));
	shader->bindUniform("lightDirection", m_light.getDirection());
	shader->bindUniform("lightAmbient", m_light.getAmbient());
	shader->bindUniform("lightDiffuse", m_light.getDiffuse());
	shader->bindUniform("lightSpecular", m_light.getSpecular());
	shader->bindUniform("specularPower", m_light.getSpecularPower());

	m_quad.draw(shader);
}

void Scene::end()
{
}

glm::mat4 Scene::getProjectionView()
{
	return m_projectionMatrix * m_camera.getTransform();
}

void Scene::setXStepSpeed(float step) {
	if (step > 1.0f)
		step = 1.0f;
	if (step < 0.0f)
		step = 0.0f;
	m_xStep = step;
}

void Scene::setYStepSpeed(float step)
{
	if (step > 1.0f)
		step = 1.0f;
	if (step < 0.0f)
		step = 0.0f;
	m_yStep = step;
}


void Scene::cameraMovement(double deltaTime)
{
	switch (m_place)
	{
	case 0:
		m_yTime += deltaTime * m_yStep;
		if (m_yTime >= 1) {
			m_yStep *= -1;
			m_place++;
		}
		break;
	case 1:
		m_xTime += deltaTime * m_xStep;
		if (m_xTime >= 1) {
			m_xStep *= -1;
			m_place++;
		}
		break;
	case 2:
		m_yTime += deltaTime * m_yStep;
		if (m_yTime <= 0) {
			m_yStep *= -1;
			m_place++;
		}
		break;
	case 3:
		m_xTime += deltaTime * m_xStep;
		if (m_xTime <= 0) {
			m_xStep *= -1;
			m_place = 0;
		}
		break;
	default:
		break;
	}
	m_cameraPos.x = -2 + m_xTime * (2 + 2);
	m_cameraPos.y = 2.0f;
	m_cameraPos.z = -2 + m_yTime * (2 + 2);

	m_camera.setTransform(glm::lookAt(
		m_cameraPos,
		glm::vec3(0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
	));
}
