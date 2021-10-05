#include "Quad.h"

Quad::Quad(glm::vec4 color): Quad()
{
	m_color = color;
}

Quad::Vertex* Quad::generateVertices(unsigned int& vertexCount, unsigned int& triCount)
{
	vertexCount = 6;
	triCount = 2;
	//define the vertices for a quad
	Vertex* vertices = new Vertex[vertexCount];
	//triangel 0
	vertices[0].position = { 0.5f,0.0f,0.5f,1.0f };
	vertices[1].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[2].position = { 0.5f,0.0f,-0.5f,1.0f };
	//triangle 1
	vertices[3].position = { 0.5f,0.0f,-0.5f,1.0f };
	vertices[4].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[5].position = { -0.5f,0.0f,-0.5f,1.0f };

	for (int i = 0; i < vertexCount; i++) {
		vertices[i].color = m_color;
	}

	vertices[0].normal = { 1.0f,1.0f,1.0f,0.0f };
	vertices[1].normal = { -1.0f,1.0f,1.0f,0.0f };
	vertices[2].normal = { 1.0f,1.0f,-1.0f,0.0f };
	vertices[3].normal = { 1.0f,1.0f,-1.0f,0.0f };
	vertices[4].normal = { -1.0f,1.0f,1.0f,0.0f };
	vertices[5].normal = { -1.0f,1.0f,-1.0f,0.0f };
	return vertices;
}
