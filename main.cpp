#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <SDL_main.h>
#include "class.hpp"

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    game pong;

    // pong.singlepayer();
    pong.multiplayer();
    
    return EXIT_SUCCESS;
}