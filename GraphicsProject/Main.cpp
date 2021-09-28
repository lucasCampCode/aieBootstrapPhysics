#include "Engine.h"
int main() {
	int exitCode = 0;

	Engine* game = new Engine();

	exitCode = game->run();

	delete game;

	return exitCode;
}