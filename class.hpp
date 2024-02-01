#pragma once
#include <sdl.h>
#include <sdl_ttf.h>


class visualizer{

    SDL_Window *window=SDL_CreateWindow("pong",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1600,900,SDL_WINDOW_ALLOW_HIGHDPI);
    


    public:

    SDL_Event event;
    SDL_Event WindowEvent;
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    bool quit=0;

    

    void events(){
        switch(event.type){  
                case SDL_QUIT:
                    quit=1;
                    break;
                    
                default: 
                    break;
        }
    };

    void draw(TTF_Font *font){
        
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

}extern app;