#include <asio.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h> 
#include <SDL_main.h>
#include <SDL_mixer.h>
#include "class.hpp"

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    TTF_Init();

    visualizer app;

    TTF_Font* font = TTF_OpenFont("calibri.ttf", 30);
    
    
    while(!app.quit){  

        while (SDL_PollEvent(&app.event)){
            app.events();
        }
        
    }
    
    return EXIT_SUCCESS;
}