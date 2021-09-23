/**
 * The main Game class that defines the main loop functions 
 * 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <string>
#include <stdio.h>
#include <iostream>

#include <game.h>

Game::Game(std::string title, int windowWidth, int windowHeight)
{
    this->title = title;
    this->windowHeight = windowHeight;
    this->windowWidth = windowWidth;
}

bool Game::Initialize()
{
    // Initialize all the things
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Failed to load: %s", SDL_GetError());
        return false;
    }

    // Setup the window
	this->sdlWindow = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->windowWidth, this->windowHeight, 0);
	if (this->sdlWindow == NULL)
    {
        printf("Failed to load: %s", SDL_GetError());
        return false;
    }
    
    // Setup the Renderer
    this->sdlRenderer = SDL_CreateRenderer(this->getWindow(), -1, 0);
    if (this->sdlRenderer == NULL)
    {
        printf("Failed to load: %s", SDL_GetError());
        return false;
    }

    // Get the SDL Surface
    this->screenSurface = SDL_GetWindowSurface( this->getWindow() );
    if (this->screenSurface == NULL)
    {
        printf("Failed to load: %s", SDL_GetError());
        return false;
    }

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        printf("Failed to load: %s", SDL_GetError());
        return false;
    }

    // Try to load the splash image
    this->splashImage = this->loadSurface("..\\assets\\images\\splash.png");
    if (this->splashImage == NULL)
    {
        printf("Failed to load: %s", SDL_GetError());
        return false;
    }

    // Everything works.
	this->running = true;
    return true;
}

SDL_Surface* Game::loadSurface( std::string path )
{
    //The final optimized image
    SDL_Surface* optimizedSurface = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
    }
    else
    {
        //Convert surface to screen format
        optimizedSurface = SDL_ConvertSurface( loadedSurface, this->screenSurface->format, 0 );
        if( optimizedSurface == NULL )
        {
            printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return optimizedSurface;
}

void Game::HandleEvents() {
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE)
            {
                running = false;
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

    SDL_BlitSurface(this->splashImage, NULL, this->screenSurface, NULL);
    SDL_UpdateWindowSurface(this->getWindow());

}

void Game::CleanUp()
{
    SDL_FreeSurface(this->splashImage);
    SDL_FreeSurface(this->screenSurface);
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
