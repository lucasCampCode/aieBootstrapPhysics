#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "Engine.h"
#include <iostream>
Engine::Engine() : Engine(1280,720,"window")
{
}

Engine::Engine(int width, int height, const char* title)
{
	m_width = width;
	m_height = height;
	m_title = title;
}


Engine::~Engine()
{
}

int Engine::run()
{
	int exitCode = 0;
	if (exitCode = start() != 0)
		return exitCode;

	while (getGameOver()) {
		exitCode = update();
		if (exitCode = update() != 0)
			return exitCode;
		if (exitCode = draw() != 0)
			return exitCode;
	}

	if (exitCode = end() != 0)
		return exitCode;

	return 0;
}

int Engine::start()
{
	if (glfwInit() == GLFW_FALSE) {
		return -1;
	}

	//create glfw window
	m_window = glfwCreateWindow(m_width, m_height, m_title, nullptr, nullptr);

	//if window wasm't sucefully created end application
	if (!m_window) {
		glfwTerminate();
		return -2;
	}

	glfwMakeContextCurrent(m_window);

	//load openGL
	if (ogl_LoadFunctions() == ogl_LOAD_FAILED) {
		glfwDestroyWindow(m_window);
		glfwTerminate();
		return -3;
	}

	//print openGL version to console
	printf("OpenGL version: %i.%i\n", ogl_GetMajorVersion(), ogl_GetMinorVersion());

	return 0;
}

int Engine::update()
{
	if (!m_window) return -4;

	glfwSwapBuffers(m_window);
	glfwPollEvents();

	return 0;
}

int Engine::draw()
{
	if (!m_window) return -5;

	glfwSwapBuffers(m_window);
	return 0;
}

int Engine::end()
{
	if (!m_window) return -6;

	//end application
	glfwDestroyWindow(m_window);
	glfwTerminate();

	return 0;
}

bool Engine::getGameOver()
{
	if (!m_window)
		return true;

	bool gameOver = !glfwWindowShouldClose(m_window);
	gameOver = gameOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return gameOver;
}
