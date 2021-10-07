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

	m_projectionMatrix = glm::perspective(
		m_camera.getFieldOfView() * glm::pi<float>() / 180,
		(float)m_width / (float)m_height,
		m_camera.getNearClip(),
		m_camera.getFarClip()
	);
}

void Scene::update(double deltaTime)
{
	int keyForward = GLFW_KEY_W;
	int keyBack = GLFW_KEY_S;
	int keyLeft = GLFW_KEY_D;
	int keyRight = GLFW_KEY_A;
	int keyUp = GLFW_KEY_Q;
	int keyDown = GLFW_KEY_E;

	float cameraSpeed = 10.0f;
	float cameraSensitivity = 0.5f;

	//Calculate the forward vector
	glm::vec3 cameraForward = glm::vec3(0.0f, 0.0f, 1.0f);
	//Calculate the camera right vector
	glm::vec3 cameraRight = glm::vec3(1.0f, 0.0f, 0.0f);
	//Calculate the camera up vector
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	//Get current mouse coordinates
	glfwGetCursorPos(m_window, &m_currentMouseX, &m_currentMouseY);

	//Rotate camera using change in mouse position
	double deltaMouseX = m_currentMouseX - m_previousMouseX;
	double deltaMouseY = m_currentMouseY - m_previousMouseY;

	if ((deltaMouseX != 0.0 || deltaMouseY != 0.0) && glfwGetMouseButton(m_window,GLFW_MOUSE_BUTTON_1))
	{
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.rotate(glm::vec3(deltaMouseY, deltaMouseX, 0.0f) * (float)(cameraSensitivity * deltaTime));
		m_camera.setTransform(cameraTransform);
	}

	//Store previous mouse coordinates
	m_previousMouseX = m_currentMouseX;
	m_previousMouseY = m_currentMouseY;

	//Get input
	if (glfwGetKey(m_window, keyForward))
	{
		//Move forward
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(cameraForward * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyBack))
	{
		//Move back
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(-cameraForward * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyRight))
	{
		//Move right
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(cameraRight * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyLeft))
	{
		//Move left
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(-cameraRight * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyUp))
	{
		//Move up
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(cameraUp * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
	if (glfwGetKey(m_window, keyDown))
	{
		//Move down
		Transform cameraTransform = m_camera.getTransform();
		cameraTransform.translate(-cameraUp * cameraSpeed * (float)deltaTime);
		m_camera.setTransform(cameraTransform);
	}
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
	return m_projectionMatrix * m_camera.getTransform().getMatrix();
}

