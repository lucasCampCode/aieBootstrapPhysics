#pragma once
#include "glm/mat4x4.hpp"
class GLFWwindow;
class Camera
{
public:
	Camera() {}
	Camera(float fieldOfView, float nearClip, float farClip)
		: m_fieldOfView{ fieldOfView }, m_nearClip{ nearClip }, m_farClip{ farClip } {}
	~Camera() {}

	void update(double deltaTime, GLFWwindow* window);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(float width, float height);

	float getPitch() { return m_phi; }
	void setPitch(float pitch) { m_phi = pitch; }
	float getYaw() { return m_theta; }
	void setYaw(float yaw) { m_theta = yaw; }

	void translateCamera(glm::vec3 direction,double deltaTime,float speed = 1.0f);

	glm::vec3 getPosition() { return m_position; }
	void setPosition(glm::vec3 position) { m_position = position; }
	float getFieldOfView() { return m_fieldOfView; }
	void setFieldOfView(float FOV) { m_fieldOfView = FOV; }
	float getNearClip() { return m_nearClip; }
	void setNearClip(float nearClip) { m_nearClip = nearClip; }
	float getFarClip() { return m_farClip; }
	void setFarClip(float farClip) { m_farClip = farClip; }

private:
	//glm::mat4 m_transform = glm::mat4(1.0f);
	glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
	float m_fieldOfView = 45.0f;
	float m_nearClip = 0.001f;
	float m_farClip = 1000.0f;

	float m_theta{ 0.0f };
	float m_phi{ 0.0f };

private:
	double m_currentMouseX;
	double m_currentMouseY;
	double m_previousMouseX;
	double m_previousMouseY;
};

