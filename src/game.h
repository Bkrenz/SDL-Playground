/**
 * The main Game class that defines the main loop functions 
 * 
 */

#ifndef __GAME_H__
#define __GAME_H__

#include <SDL.h>
#include <string>

class Game
{
    public:
        Game(std::string title, int windowWidth, int windowHeight);

        bool Initialize();
        void HandleEvents();
        void Update();
        void Render();
        void CleanUp();

        bool isRunning();

    
    private:
        Game();

        bool running;

        SDL_Surface* screenSurface;
        SDL_Surface* splashImage;

        std::string title;
        int windowWidth;
        int windowHeight;

        SDL_Window* sdlWindow;
        SDL_Renderer* sdlRenderer;

        SDL_Window* getWindow();
        SDL_Renderer* getRenderer();
        
	    SDL_Event event;

        SDL_Surface* loadSurface( std::string path );



};

#endif