#include <SDL.h>
#include <SDL_ttf.h> 
#include <SDL_main.h>
#include "class.hpp"

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();

    game pong;

    TTF_Font* font = TTF_OpenFont("calibri.ttf", 50);
    if(!font) std::cout<<SDL_GetError();

    pong.singlepayer(font);
    // pong.multiplayer(font);
    return EXIT_SUCCESS;
}