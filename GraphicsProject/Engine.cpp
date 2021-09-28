#include "Engine.h"
#include "GLFW/glfw3.h"
#include "gl_core_4_4.h"
#include <iostream>
Engine::Engine()
{
	//create glfw window
	m_window = glfwCreateWindow(1280, 720, "Graphics Engine", nullptr, nullptr);
}


Engine::~Engine()
{
	delete m_window;
}

int Engine::run()
{
	int exitCode = 0;
	if (exitCode = start() != 0)
		return exitCode;

	while (getGameOver()) {
		exitCode = update();
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
	glfwSwapBuffers(m_window);
	glfwPollEvents();

	return 0;
}

int Engine::end()
{
	//end application
	glfwDestroyWindow(m_window);
	glfwTerminate();

	return 0;
}

bool Engine::getGameOver()
{
	bool gameOver = glfwWindowShouldClose(m_window);
	gameOver = gameOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return gameOver;
}
