#include "Camera.h"
#include "glm/ext.hpp"

void Camera::update(double deltaTIme)
{
	
}

glm::mat4 Camera::getViewMatrix()
{
	float thetaRotation = glm::radians(m_theta);
	float phiRotation = glm::radians(m_phi);
	glm::vec3 forward(cos(phiRotation) * cos(thetaRotation), sin(phiRotation), cos(phiRotation) * sin(thetaRotation));
	return glm::lookAt(m_transform.getPosition(),m_transform.getPosition()+forward,glm::vec3(0.0f,1.0f,0.0f));
}

glm::mat4 Camera::getProjectionMatrix(float width, float height)
{
	return glm::perspective(glm::pi<float>() * 0.25f,
		width/height,
		m_nearClip,
		m_farClip
	);
}

