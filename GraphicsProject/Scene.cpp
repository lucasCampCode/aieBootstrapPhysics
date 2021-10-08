#include "Scene.h"
#include "glm/ext.hpp"
#include "GLFW/glfw3.h"
#include <iostream>
Scene::Scene(int width, int height)
{
	m_width = width;
	m_height = height;
}
void Scene::start()
{
	//init the obj mesh
	m_objMesh.load("Dragon.obj",false);
	//init the quad
	m_quad.setTransform(glm::mat4(10.0f));
	m_quad.setColor({ 1.0f,0.25f,0.0f,1.0f });
	m_quad.start();
	//init light
	m_light.setDirection(glm::vec3(-1.0f));
	m_light.setAmbient({ 0.0f, 0.5f, 0.0f, 1.0f });
	m_light.setDiffuse({ 0.6f, 0.6f, 1.0f, 1.0f });
	m_light.setSpecular({ 1.0f, 1.0f, 1.0f, 1.0f });
	m_light.setSpecularPower(5.0f);

	Transform cameraTransform = m_camera.getTransform();
	cameraTransform.setPosition(glm::vec3(10.0f));
	cameraTransform.setRotation(glm::vec3(-45.0f, 45.0f, 0.0f));

}

void Scene::update(double deltaTime)
{
	m_camera.update(deltaTime, m_window);

}

void Scene::draw(aie::ShaderProgram* shader)
{
	shader->bindUniform("cameraPosition", m_camera.getTransform().getPosition());
	shader->bindUniform("lightDirection", m_light.getDirection());
	shader->bindUniform("lightAmbient", m_light.getAmbient());
	shader->bindUniform("lightDiffuse", m_light.getDiffuse());
	shader->bindUniform("lightSpecular", m_light.getSpecular());
	shader->bindUniform("LightSpecularPower", m_light.getSpecularPower());

	shader->bindUniform("modelMatrix", m_objTransform);
	m_objMesh.draw();
	m_quad.draw(shader);
}

void Scene::end()
{
}

glm::mat4 Scene::getProjectionView()
{
	return m_camera.getProjectionMatrix(m_width,m_height) * m_camera.getViewMatrix();
}

