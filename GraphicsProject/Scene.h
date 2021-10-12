#pragma once
#include "Camera.h"
#include "Quad.h"
#include "Texture.h"
#include "glm/mat4x4.hpp"
class GLFWwindow;
class Scene
{
public:
	Scene(int width, int height);
	~Scene() {}

	void start();
	void update(float deltaTime);
	void draw();
	void end();

	glm::mat4 getProjectionViewModel();

	void setWindow(GLFWwindow* window) { m_window = window; }

	float TimeStep(float& curTime, float& step);

private:
	GLFWwindow* m_window = nullptr;

	int m_width = 1280, m_height = 720;

	Quad m_quad = Quad({1.0f,1.0f,1.0f,1.0f});
	aie::Texture m_earthDiffuse;
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1);

};

