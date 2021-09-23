#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"

int main(int argv, char** args)
{

	Game game = Game("Hello SDL", 800, 600);

	if(!game.Initialize())
	{
		return 0;
	}

	while(game.isRunning())
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}

	game.CleanUp();

	return 0;
}