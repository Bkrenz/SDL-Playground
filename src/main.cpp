#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"

int main(int argv, char** args)
{
	
    std::cout << "Starting up." << std::endl;

	Game game = Game("Hello SDL", 800, 600);

    std::cout << "Initializing..." << std::endl;

	if(!game.Initialize())
	{
		std::cout << "Failed to load: " << SDL_GetError() << std::endl;
		return 0;
	}

	std::cout << "Initialization complete. Running." << std::endl;

	while(game.isRunning())
	{
		game.HandleEvents();
		game.Update();
		game.Render();
	}

	game.CleanUp();

	return 0;
}