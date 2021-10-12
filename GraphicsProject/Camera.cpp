#include "Camera.h"
#include "GLFW/glfw3.h"
#include "glm/ext.hpp"
void Camera::update(double deltaTime, GLFWwindow* window)
{
	int keyForward = GLFW_KEY_W;
	int keyBack = GLFW_KEY_S;
	int keyLeft = GLFW_KEY_A;
	int keyRight = GLFW_KEY_D;
	int keyUp = GLFW_KEY_E;
	int keyDown = GLFW_KEY_Q;

	float thetaR = glm::radians(m_theta);
	float phiR = glm::radians(m_phi);

	//Calculate the forward vector
	glm::vec3 cameraForward{
		cos(phiR) * cos(thetaR),
		sin(phiR),
		cos(phiR) * sin(thetaR)
	};
	//Calculate the camera right vector
	glm::vec3 cameraRight{ -sin(thetaR),0.0f,cos(thetaR) };
	//Calculate the camera up vector
	glm::vec3 cameraUp{ 0.0f,1.0f,0.0f };

	float cameraSpeed = 10.0f;
	float cameraSensitivity = 0.5f;


	glfwGetCursorPos(window, &m_currentMouseX, &m_currentMouseY);

	//Rotate camera using change in mouse position
	double deltaMouseX = m_currentMouseX - m_previousMouseX;
	double deltaMouseY = m_currentMouseY - m_previousMouseY;

	if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_1))
	{
		m_theta += cameraSensitivity * deltaMouseX;
		m_phi -= cameraSensitivity * deltaMouseY;
	}

	//Store previous mouse coordinates
	m_previousMouseX = m_currentMouseX;
	m_previousMouseY = m_currentMouseY;

	//Get input
	if (glfwGetKey(window, keyForward))
	{
		//Move forward
		translateCamera(cameraForward, deltaTime);
	}
	if (glfwGetKey(window, keyBack))
	{
		//Move back
		translateCamera(-cameraForward, deltaTime);
	}
	if (glfwGetKey(window, keyRight))
	{
		//Move right
		translateCamera(cameraRight, deltaTime);
	}
	if (glfwGetKey(window, keyLeft))
	{
		//Move left
		translateCamera(-cameraRight,deltaTime);
	}
	if (glfwGetKey(window, keyUp))
	{
		//Move up
		translateCamera(cameraUp, deltaTime);
	}
	if (glfwGetKey(window, keyDown))
	{
		//Move down
		translateCamera(-cameraUp, deltaTime);
	}
}

glm::mat4 Camera::getViewMatrix()
{
	float thetaR = glm::radians(m_theta);
	float phiR = glm::radians(m_phi);
	glm::vec3 forward(
		cos(phiR) * cos(thetaR),
		sin(phiR),
		cos(phiR) * sin(thetaR)
	);
	return glm::lookAt(m_position, m_position + forward, glm::vec3(0.0f, 1.0f, 0.0f));
}

glm::mat4 Camera::getProjectionMatrix(float width, float height)
{
	return glm::perspective(m_fieldOfView,
		width / height,
		m_nearClip,
		m_farClip
	);
}

void Camera::translateCamera(glm::vec3 direction, double deltaTime, float speed)
{
	glm::vec3 cameraTransform = getPosition();
	cameraTransform += direction * speed * (float)deltaTime;
	setPosition(cameraTransform);
}
