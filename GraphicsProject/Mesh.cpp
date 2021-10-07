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
	unsigned int vertexCount;
	//define the vertices for a quad
	Vertex* vertices = generateVertices(vertexCount, m_triCount);

	//fill vertex buffer
	glBufferData(
		GL_ARRAY_BUFFER,	//type of buffer
		sizeof(Vertex) * vertexCount, //size in bytes of all vertices
		vertices,			//all vertices
		GL_STATIC_DRAW		//how the data will update
	);
	unsigned int memoryPosition = 0u;
	//enable vertex position as first attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(
		0,						//attribute index
		4,						//number of value within the attrivute
		GL_FLOAT,				//type of each value
		GL_FALSE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);
	//enable vertex normal as second attribute
	memoryPosition += sizeof(Vertex::position);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(
		1,						//attribute index
		4,						//number of value within the attrivute
		GL_FLOAT,				//type of each value
		GL_TRUE,				//whether to normalize
		sizeof(Vertex),			//size in bytes of one vertex
		(void*)memoryPosition	//memory position of this attribute
	);

	memoryPosition += sizeof(Vertex::normal);
	//enable vertex texture	cooSrdnate as third attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(
		2,								//attribute index
		2,								//number of value within the attrivute
		GL_FLOAT,						//type of each value
		GL_FALSE,						//whether to normalize
		sizeof(Vertex),					//size in bytes of one vertex
		(void*)memoryPosition			//memory position of this attribute
	);

	memoryPosition += sizeof(Vertex::texCoord);
	//enable vertex tangent as fourth attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(
		3,								//attribute index
		4,								//number of value within the attrivute
		GL_FLOAT,						//type of each value
		GL_FALSE,						//whether to normalize
		sizeof(Vertex),					//size in bytes of one vertex
		(void*)memoryPosition			//memory position of this attribute
	);

	memoryPosition += sizeof(Vertex::tangent);
	//enable vertex color as fifth attribute
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(
		4,								//attribute index
		4,								//number of value within the attrivute
		GL_FLOAT,						//type of each value
		GL_FALSE,						//whether to normalize
		sizeof(Vertex),					//size in bytes of one vertex
		(void*)memoryPosition			//memory position of this attribute
	);
	memoryPosition += sizeof(Vertex::color);

	//unbind buffer and array
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	delete[] vertices;
}

void Mesh::draw(aie::ShaderProgram* shader)
{
	shader->bindUniform("modelMatrix", m_transform);
	glBindVertexArray(m_vertexArrayObject);
	glDrawArrays(GL_TRIANGLES, 0, m_triCount * 3);
}

Mesh::Vertex* Mesh::generateVertices(unsigned int& vertexCount,unsigned int& triCount)
{
	return nullptr;
}
