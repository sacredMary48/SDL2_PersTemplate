#include <SDL.h>
#include <SDL_image.h>
#include "SDL_Exception.h"
#include "Game.h"
//Here you can make the code for the functions you're gonna use.

/*You're init for make changes*/
void Game::init()
{
    auto isInitialized = SDL_Init(SDL_INIT_VIDEO) >= 0;

    if(!isInitialized)
        {
            throw SDL_Exception(SDL_GetError());
        }
    playspace();
    SDL_SetRenderDrawColor(_renderer, 60, 205, 245, 255); //RGBA

    _isRunning = true;
}

/*This is the space from you can work and see what you build.*/
void Game::playspace()
{
    SDL_CreateWindowAndRenderer(512, 512, SDL_WINDOW_SHOWN, &_window, &_renderer );
        if( _window == NULL || _renderer == NULL)
        {
			throw SDL_Exception(SDL_GetError());
		}
}
/*Start core*/
void Game::handlerEvent() /*The Events(the first event here is for swicth of/off the app)*/
{
    SDL_Event event;
        while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            _isRunning = false;
        }
    }

}

void Game::update(double elapsedSec) /*Refresh of the app*/
{

}

void Game::render() /*The graphics of the app*/
{
    SDL_RenderClear(_renderer);
    SDL_RenderPresent(_renderer);

}
/*End core*/
void Game::release_App()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}
/*The loop switch*/
bool Game::isRunning()
{
    return _isRunning;
}
