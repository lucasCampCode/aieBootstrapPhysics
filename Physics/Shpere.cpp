#include "Shpere.h"
#include "Gizmos.h"
Shpere::Shpere(glm::vec2 position, glm::vec2 velocity, float mass, float radius, glm::vec4 color) : RigidBody(SHPERE,position,velocity,0,mass)
{
	m_radius = radius;
	m_color = color;
}

Shpere::~Shpere()
{
}

void Shpere::draw()
{
	aie::Gizmos::add2DCircle(getPosition(),m_radius,8,m_color);
}
