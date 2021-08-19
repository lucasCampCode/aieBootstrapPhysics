#include <iostream>
#include "PhysicsGame.h"
int main()
{
	PhysicsGame* game = new PhysicsGame();

	game->run("Physics Game", 1600, 900, false);

	delete game;

	return 0;
}
