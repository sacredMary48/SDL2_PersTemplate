#ifndef GAME_H
#define GAME_H
#include <stdio.h>
#include <SDL.h>
#include "SDL_Exception.h"
//list ALL you variables and functions here
class Game
{
    public:
        void init();
        void playspace();
        void handlerEvent();
        void update(double elapsedSec);
        void render();
        void release_App();
        bool isRunning();

    private:
        bool _isRunning;
        SDL_Window *_window;
        SDL_Renderer *_renderer;

};

#endif // GAME_H
