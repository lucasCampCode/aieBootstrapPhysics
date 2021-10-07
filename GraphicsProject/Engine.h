#pragma once
#include "Shader.h"
#include "Scene.h"

struct GLFWwindow;

class Engine
{
public:
	Engine();
	Engine(int width, int height, const char* title);
	~Engine();

	int run();
	aie::ShaderProgram* getShader() { return m_shader; }
private:
	int start();
	int update(double deltaTime);
	int draw(aie::ShaderProgram* shader);
	int end();

	bool getGameOver();
private:
	GLFWwindow* m_window = nullptr;
	int m_width, m_height;
	const char* m_title;

	unsigned int m_fps;

	aie::ShaderProgram* m_shader;

	Scene* m_scene;
};

