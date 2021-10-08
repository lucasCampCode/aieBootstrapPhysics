#pragma once
#include "Transform.h"
class GLFWwindow;

class Camera
{
public:
	Camera() {}
	Camera(float fieldOfView, float nearClip, float farClip)
		: m_fieldOfView{ fieldOfView }, m_nearClip{ nearClip }, m_farClip{ farClip } {}
	~Camera() {}

	void update(double deltaTime,GLFWwindow* window);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(float width, float height);

	float getPitch() { return m_phi; }
	void setPitch(float pitch) { m_phi = pitch; }
	float getYaw() { return m_theta; }
	void setYaw(float yaw) { m_theta = yaw; }

	Transform getTransform() { return m_transform; }
	void setTransform(Transform transform) { m_transform = transform; }
	float getFieldOfView() { return m_fieldOfView; }
	void setFieldOfView(float FOV) { m_fieldOfView = FOV; }
	float getNearClip() { return m_nearClip; }
	void setNearClip(float nearClip) { m_nearClip = nearClip; }
	float getFarClip() { return m_farClip; }
	void setFarClip(float farClip) { m_farClip = farClip; }

private:
	Transform m_transform = Transform();
	float m_fieldOfView{ 45.0f };
	float m_nearClip{ 0.001f };
	float m_farClip{ 1000.0f };

	float m_theta{ 0.0f };
	float m_phi{ 0.0f };

private:
	double m_currentMouseX;
	double m_currentMouseY;
	double m_previousMouseX;
	double m_previousMouseY;
};

