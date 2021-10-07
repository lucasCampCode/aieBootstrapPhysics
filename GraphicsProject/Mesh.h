#pragma once
#include "Shader.h"
#include "gl_core_4_4.h"
#include "glm/vec4.hpp"
#include "glm/mat4x4.hpp"
class Mesh
{
public:
	struct Vertex {
		glm::vec4 position;
		glm::vec4 normal;
		glm::vec2 texCoord;
		glm::vec4 tangent;
		glm::vec4 color;
	};
public:
	Mesh();
	~Mesh();

	void start();
	void draw(aie::ShaderProgram* shader);

	virtual Vertex* generateVertices(unsigned int& vertexCount,unsigned int& tricount) = 0;

	glm::mat4 getTransform() { return m_transform; }
	void setTransform(glm::mat4 transform) { m_transform = transform; }
private:
	glm::mat4 m_transform;
	unsigned int m_triCount;
	unsigned int m_vertexArrayObject, m_vertexBufferObject, m_indexBufferObject;
};

