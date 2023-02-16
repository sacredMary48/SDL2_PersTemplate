#include <iostream>
#include <string>
#include <chrono>
#include <SDL.h>
#include <exception>
#include "Game.h"

int main( int argc, char * argv[] )
{
auto game=Game();
try{
    game.init();
    auto prev = std::chrono::system_clock::now();//getCurrentTime;
    while(game.isRunning()){ //game Loop start here
    auto actual = std::chrono::system_clock::now();//getCurrentTimeLocal;
    std::chrono::duration<double> elapsedSec = actual - prev;//Permited to play the game to the stable speed can go you're hardware.
    game.handlerEvent();
    game.update(elapsedSec.count()); //here come the time control
    game.render();
    prev = actual;
    } //game Loop end here
    game.release_App();//SDL_QUIT_PARAMETERS
}catch (std::exception &exception){ // catch the erros if the program not On.
    fprintf(stderr, exception.what());
    SDL_Quit();
    return -1;
    }

    return 0;
}
