#include "Mesh.h"

Mesh::Mesh()
{
	m_transform = {
		1.0f,0.0f,0.0f,0.0f,
		0.0f,1.0f,0.0f,0.0f,
		0.0f,0.0f,1.0f,0.0f,
		0.0f,0.0f,0.0f,1.0f
	};
	m_triCount = 0;
	m_vertexArrayObject = 0;
	m_vertexBufferObject = 0;
	m_indexBufferObject = 0;
}

Mesh::~Mesh()
{
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	glDeleteBuffers(1, &m_vertexBufferObject);
	glDeleteBuffers(1, &m_indexBufferObject);
}

void Mesh::start()
{
	assert(m_vertexArrayObject == 0);
	//generate Buffer and array
	glGenBuffers(1, &m_vertexBufferObject);
	glGenVertexArrays(1, &m_vertexArrayObject);

	//bind vertex array and vertex buffer
	glBindVertexArray(m_vertexArrayObject);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject);
	
	//generate the Vertices
	/*Vertex* vertices{};
	int vertexCount;
	generateVertices(vertices, vertexCount);*/
	const int vertexCount = 6;
	//define the vertices for a quad
	Vertex vertices[vertexCount];
	//triangel 0
	vertices[0].position = { 0.5f,0.0f,0.5f,1.0f };
	vertices[1].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[2].position = { 0.5f,0.0f,-0.5f,1.0f };
	//triangle 1
	vertices[3].position = { 0.5f,0.0f,-0.5f,1.0f };
	vertices[4].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[5].position = { -0.5f,0.0f,-0.5f,1.0f };

	//fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,	//type of buffer
		sizeof(Vertex) * 6, //size in bytes of all vertices
		vertices,			//all vertices
		GL_STATIC_DRAW		//how the data will update
	);

	//enable vertex position as first attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,					//attribute index
		4,					//number of value within the attrivute
		GL_FLOAT,			//type of each value
		GL_FALSE,			//whether to normalize
		sizeof(Vertex),		//size in bytes of one vertex
		0					//memory position of this attribute
	);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void Mesh::draw()
{
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Mesh::generateVertices(Vertex* vertices, int& vertexCount)
{
	vertexCount = 6;
	//define the vertices for a quad
	vertices = new Vertex [vertexCount];
	//triangel 0
	vertices[0].position = { 0.5f,0.0f,0.5f,1.0f };
	vertices[1].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[2].position = { 0.5f,0.0f,-0.5f,1.0f };
	//triangle 1
	vertices[3].position = { 0.5f,0.0f,-0.5f,1.0f };
	vertices[4].position = { -0.5f,0.0f,0.5f,1.0f };
	vertices[5].position = { -0.5f,0.0f,-0.5f,1.0f };
}
