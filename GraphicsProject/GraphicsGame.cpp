#include "GraphicsGame.h"

void GraphicsGame::run()
{
	Start();
	while (false) {
		Update();
		Draw();
	}
	End();
}
