#include "Engine.h"
#include "GLFW/glfw3.h"
Engine::Engine()
{
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
		update();
	}

	if (exitCode = end() != 0)
		return exitCode;

	return 0;
}

int Engine::start()
{
	return 0;
}

int Engine::update()
{
	return 0;
}

int Engine::end()
{
	return 0;
}

bool Engine::getGameOver()
{
	bool gameOver = glfwWindowShouldClose(m_window);
	gameOver = gameOver || glfwGetKey(m_window, GLFW_KEY_ESCAPE) == GLFW_PRESS;

	return gameOver;
}
