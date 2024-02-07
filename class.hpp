#pragma once
#include <sdl.h>
#include <sdl_ttf.h>

#define SPEED 1000
#define BALLSPEED 1500

class game{

    SDL_Window *window=SDL_CreateWindow("pong",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1600,900,SDL_WINDOW_ALLOW_HIGHDPI);

    SDL_Rect    leftPlayer={0,300,50,300},  
                rightPlayer={1550,300,50,300}, 
                ball={775,425,50,50}; 

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = TTF_OpenFont("calibri.ttf", 30);

    

    uint32_t currentTime=0, lastFrameTime = 0;
    double deltaTime = 0;

    bool up=0;

    void move(){
        if(up){
            if(ball.y-BALLSPEED*deltaTime>0) ball.y-=BALLSPEED*deltaTime;
            else {
                ball.y=0;
                up=0;
            }
        }
        else{
            if(ball.y+BALLSPEED*deltaTime<850) ball.y+=BALLSPEED*deltaTime;
            else {
                ball.y=850;
                up=1;
            }
        }
    }

    public:

    SDL_Event event;
    SDL_Event WindowEvent;
    
    bool quit=0;

    

    void events(){
        switch(event.type){  
                case SDL_QUIT:
                    quit=1;
                    break;
                    
                default: 
                    break;
        } 
    }

    void draw(){ //TTF_Font *font

        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        
        SDL_RenderFillRect(renderer,&ball);
        SDL_RenderFillRect(renderer,&leftPlayer);
        SDL_RenderFillRect(renderer,&rightPlayer);

        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    int multiplayer(){

        while(!quit){

            currentTime = SDL_GetTicks();
            deltaTime = (currentTime - lastFrameTime) / 1000.0; 
            lastFrameTime = currentTime;

            const Uint8* key = SDL_GetKeyboardState(NULL);

            while (SDL_PollEvent(&event)){
                events();
            }

            if(key[SDL_SCANCODE_W]&&leftPlayer.y!=0){
                if(leftPlayer.y-SPEED*deltaTime>0) leftPlayer.y-=SPEED*deltaTime;
                else leftPlayer.y=0;
            }
            if(key[SDL_SCANCODE_S]&&leftPlayer.y!=600){
                if(leftPlayer.y+SPEED*deltaTime<600) leftPlayer.y+=SPEED*deltaTime;
                else leftPlayer.y=600;
            }                                                                                           

            if(key[SDL_SCANCODE_UP]&&rightPlayer.y!=0){
                if(rightPlayer.y-SPEED*deltaTime>0) rightPlayer.y-=SPEED*deltaTime;
                else rightPlayer.y=0;
            }
            if(key[SDL_SCANCODE_DOWN]&&rightPlayer.y!=600){
                if(rightPlayer.y+SPEED*deltaTime<600) rightPlayer.y+=SPEED*deltaTime;
                else rightPlayer.y=600;
            }

            draw();
        }
        return EXIT_SUCCESS;
    }

    int singlepayer(){

        while(!quit){
            
            currentTime = SDL_GetTicks();
            deltaTime = (currentTime - lastFrameTime) / 1000.0; 
            lastFrameTime = currentTime;

            const Uint8* key = SDL_GetKeyboardState(NULL);

            move();
            
            while (SDL_PollEvent(&event)){
                events();
            }
            
            if(key[SDL_SCANCODE_W]&&leftPlayer.y!=0){
                if(leftPlayer.y-SPEED*deltaTime>0) leftPlayer.y-=SPEED*deltaTime;
                else leftPlayer.y=0;
            }
            if(key[SDL_SCANCODE_S]&&leftPlayer.y!=600){
                if(leftPlayer.y+SPEED*deltaTime<600) leftPlayer.y+=SPEED*deltaTime;
                else leftPlayer.y=600;
            }

            if (ball.y+25 != rightPlayer.y+150){       
                if(ball.y+25 < rightPlayer.y+150 && rightPlayer.y!=0) {
                    if (rightPlayer.y-SPEED*deltaTime>0) rightPlayer.y-=SPEED*deltaTime;
                    else rightPlayer.y=0;
                }

                else if(ball.y+25 > rightPlayer.y+150 && rightPlayer.y!=600){
                    if(rightPlayer.y+SPEED*deltaTime<600) rightPlayer.y+=SPEED*deltaTime;
                    else rightPlayer.y=600;
                }
            }

            draw();
        }
        return EXIT_SUCCESS;
    }


}extern pong;