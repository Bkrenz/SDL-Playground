/**
 * The main Game class that defines the main loop functions 
 * 
 */

#ifndef __GAME_CPP__
#define __GAME_CPP__

#include <SDL2/SDL.h>
#include <string>
#include <game.h>

Game::Game(std::string title, int windowWidth, int windowHeight)
{
    this->title = title;
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
};

void Game::Initialize()
{
    SDL_Init(SDL_INIT_EVERYTHING);

	this->sdlWindow = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowWidth, this->windowHeight, 0);
	this->sdlRenderer = SDL_CreateRenderer(this->getWindow(), -1, 0);

	this->running = true;
};

void Game::HandleEvents() {
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            this->running = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                this->running = false;
            }
        }
    }
}

void Game::Update()
{

}

void Game::Render()
{
    
    SDL_RenderClear(sdlRenderer);

    SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);

    SDL_RenderPresent(sdlRenderer);
}

void Game::CleanUp()
{
	SDL_DestroyRenderer(sdlRenderer);
	SDL_DestroyWindow(sdlWindow);
	SDL_Quit();
}

bool Game::isRunning()
{
    return this->running;
}

SDL_Window* Game::getWindow()
{
    return this->sdlWindow;
}

SDL_Renderer* Game::getRenderer()
{
    return this->sdlRenderer;
}

#endif