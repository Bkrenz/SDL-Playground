/**
 * The main Game class that defines the main loop functions 
 * 
 */

#ifndef __GAME_H__
#define __GAME_H__

#include <SDL2/SDL.h>
#include <string>

class Game
{
    public:
        Game(std::string title, int windowWidth, int windowHeight);

        void Initialize();
        void HandleEvents();
        void Update();
        void Render();
        void CleanUp();

        bool isRunning();

    
    private:
        Game();

        bool running;

        std::string title;
        int windowWidth;
        int windowHeight;

        SDL_Window* sdlWindow;
        SDL_Renderer* sdlRenderer;

        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        
	    SDL_Event event;


};

#endif