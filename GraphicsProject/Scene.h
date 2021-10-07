#pragma once
#include "Shader.h"
#include "Camera.h"
#include "Light.h"
#include "Quad.h"
#include "glm/mat4x4.hpp"

struct GLFWwindow;

class Scene
{
public:
	Scene(int width, int height);
	~Scene() {}

	void start();
	void update(double deltaTime);
	void draw(aie::ShaderProgram* shader);
	void end();

	glm::mat4 getProjectionView();

	GLFWwindow* getWindow() { return m_window; }
	void setWindow(GLFWwindow* window) { m_window = window; }

private:

	int m_width = 1280, m_height = 720;

	glm::vec3 m_cameraPos = glm::vec3();
	Camera m_camera = Camera();
	glm::mat4 m_projectionMatrix = glm::mat4(1);

	Quad m_quad;
	Light m_light;

	GLFWwindow* m_window = nullptr;

	double m_currentMouseX = 0.0;
	double m_currentMouseY = 0.0;
	double m_previousMouseX = 0.0;
	double m_previousMouseY = 0.0;
};

