#pragma once
#include "Transform.h"
class Camera
{
public:
	Camera() {}
	Camera(float fieldOfView, float nearClip, float farClip)
		: m_fieldOfView{ fieldOfView }, m_nearClip{ nearClip }, m_farClip{ farClip } {}
	~Camera() {}

	void update(double deltaTIme);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix(float width,float height);

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
	float m_fieldOfView = 45.0f;
	float m_nearClip = 0.001f;
	float m_farClip = 1000.0f;

	float m_theta;
	float m_phi;
};
