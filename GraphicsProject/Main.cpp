#include "gl_core_4_4.h"
#include "GLFW/glfw3.h"
#include "GraphicsGame.h"
int main() {

	if (!glfwInit()) {
		return -1;
	}

	GraphicsGame* game = new GraphicsGame();

	game->run();

	delete game;

	return 0;
}