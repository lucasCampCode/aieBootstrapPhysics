#pragma once
#include "Shader.h"
#include "Camera.h"
#include "Light.h"
#include "Quad.h"
#include "glm/mat4x4.hpp"
class Scene
{
public:
	Scene(int width, int height);
	~Scene() {}

	void start();
	void update(float deltaTime);
	void draw(aie::ShaderProgram* shader);
	void end();

	glm::mat4 getProjectionView();

	void setXStepSpeed(float step);
	void setYStepSpeed(float step);

	void cameraMovement(double deltaTime);

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

private:
	float m_xTime = 0;
	float m_yTime = 0;

	float m_xStep = 1;
	float m_yStep = 1;

	int m_place = 0;

};

