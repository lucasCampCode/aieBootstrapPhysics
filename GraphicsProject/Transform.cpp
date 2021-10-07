#include "Transform.h"
#include "glm/ext.hpp"

void Transform::translate(glm::vec3 translation)
{
	m_position += translation;
	m_shouldUpdateMatrix = true;
}

void Transform::rotate(glm::vec3 rotation)
{
	m_rotation += rotation;
	m_shouldUpdateMatrix = true;
}

void Transform::scale(glm::vec3 scale)
{
	m_scale += scale;
	m_shouldUpdateMatrix = true;
}

void Transform::setPosition(glm::vec3 position)
{
	m_position = position;
	m_shouldUpdateMatrix = true;
}

void Transform::setRotation(glm::vec3 rotation)
{
	m_rotation = rotation;
	m_shouldUpdateMatrix = true;
}

void Transform::setScale(glm::vec3 scale)
{
	m_scale = scale;
	m_shouldUpdateMatrix = true;
}

glm::mat4 Transform::getMatrix()
{
	glm::mat4 matrix = m_matrix;

	if (m_shouldUpdateMatrix) {
		glm::translate(matrix, m_position);
		glm::rotate(matrix, m_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		glm::rotate(matrix, m_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		glm::rotate(matrix, m_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));
		glm::scale(matrix, m_scale);
		m_shouldUpdateMatrix = false;
	}

	return matrix;
}
