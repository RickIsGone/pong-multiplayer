#pragma once
#include <sdl.h>
#include <sdl_ttf.h>
#include "sdl_functions.hpp"

#define SPEED 1000
#define BALLSPEED 1050

enum directions{
    UP=-1,
    DOWN=1,
    LEFT=-1,
    RIGHT=1,
    NONE=0
};

struct balls{
    SDL_Rect hitbox={775,425,50,50};
    int dx=LEFT,dy=NONE;
    int speed=BALLSPEED;
}static ball;

class game{

    SDL_Window *window=SDL_CreateWindow("pong",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1600,900,SDL_WINDOW_ALLOW_HIGHDPI);

    struct player{
        SDL_Rect hitbox;
        int dy;
        int score;
    };

    player  leftPlayer={{0,300,50,300}, NONE, 0},  
            rightPlayer={{1550,300,50,300}, NONE, 0};

    uint32_t currentTime=0, lastFrameTime = 0;
    double deltaTime = 0;

    void move(){

        if(ball.hitbox.x <= 0 ) { 
            ball.hitbox={775,425,50,50};
            ball.speed=BALLSPEED;
            ball.dx=RIGHT;
            ball.dy=NONE;
            if(++rightPlayer.score==21) quit=1;
        }
        if(ball.hitbox.x >= 1550){
            ball.hitbox={775,425,50,50};
            ball.speed=BALLSPEED;
            ball.dx=LEFT;
            ball.dy=NONE;
            if(++leftPlayer.score==21) quit=1;
        }

        if(SDL_HasIntersection(&ball.hitbox,&leftPlayer.hitbox)&&ball.dx==LEFT){
            ball.dx=RIGHT;
            switch (leftPlayer.dy){
                case UP:
                    if(ball.dy==UP) break;
                    else if(ball.dy==DOWN) ball.dy=DOWN;
                    else ball.dy=UP;
                    break;
                
                case DOWN:
                    if(ball.dy==UP) ball.dy=UP;
                    else if(ball.dy==DOWN) break;
                    else ball.dy=DOWN;
                    break;
                    
                default:
                    break;
            }
        } 
        if(SDL_HasIntersection(&ball.hitbox,&rightPlayer.hitbox)&&ball.dx==RIGHT){
            ball.dx=LEFT;
            switch (leftPlayer.dy){
                case UP:
                    if(ball.dy==UP) break;
                    else if(ball.dy==DOWN) ball.dy=DOWN;
                    else ball.dy=UP;
                    break;
                
                case DOWN:
                    if(ball.dy==UP) ball.dy=UP;
                    else if(ball.dy==DOWN) break;
                    else ball.dy=DOWN;
                    break;
                    
                default:
                    break;
            }
        } 

        if(ball.hitbox.y <= 0 ||ball.hitbox.y >= 850) ball.dy*=-1; 

        ball.hitbox.x+=ball.dx*ball.speed*deltaTime;
        ball.hitbox.y+=ball.dy*ball.speed*deltaTime;
    }

    SDL_Event event;
    SDL_Event WindowEvent;
    
    bool quit=0;

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    void events(){
        switch(event.type){  
                case SDL_QUIT:
                    quit=1;
                    break;
                    
                default: 
                    break;
        } 
    }

    void draw(TTF_Font *font){ 

        SDL_SetRenderDrawColor(renderer,255,255,255,255);
        
        SDL_RenderFillRect(renderer,&ball.hitbox);
        SDL_RenderFillRect(renderer,&leftPlayer.hitbox);
        SDL_RenderFillRect(renderer,&rightPlayer.hitbox);

        sdl::v_quick_text(leftPlayer.score,255,255,255,700,50,renderer,font);
        sdl::v_quick_text(rightPlayer.score,255,255,255,850,50,renderer,font);

        SDL_SetRenderDrawColor(renderer,0,0,0,255);

        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);
    }

    public:

    int multiplayer(TTF_Font *font){

        while(!quit){

            currentTime = SDL_GetTicks();
            deltaTime = (currentTime - lastFrameTime) / 1000.0; 
            lastFrameTime = currentTime;

            const Uint8* key = SDL_GetKeyboardState(NULL);

            move();

            while (SDL_PollEvent(&event)){
                events();
            }

            if(key[SDL_SCANCODE_W]&&leftPlayer.hitbox.y!=0){
                if(leftPlayer.hitbox.y-SPEED*deltaTime>0){
                    leftPlayer.hitbox.y-=SPEED*deltaTime;
                    leftPlayer.dy=UP;
                }
                else{
                    leftPlayer.hitbox.y=0;
                    leftPlayer.dy=NONE;
                }
            }
            if(key[SDL_SCANCODE_S]&&leftPlayer.hitbox.y!=600){
                if(leftPlayer.hitbox.y+SPEED*deltaTime<600){
                    leftPlayer.hitbox.y+=SPEED*deltaTime;
                    leftPlayer.dy=DOWN;
                }
                else{
                    leftPlayer.hitbox.y=600;
                    leftPlayer.dy=NONE;
                }
            }                                                                                           

            if(key[SDL_SCANCODE_UP]&&rightPlayer.hitbox.y!=0){
                if(rightPlayer.hitbox.y-SPEED*deltaTime>0){
                    rightPlayer.hitbox.y-=SPEED*deltaTime;
                    rightPlayer.dy=UP;
                }
                else{
                    rightPlayer.hitbox.y=0;
                    rightPlayer.dy=NONE;
                }
            }
            if(key[SDL_SCANCODE_DOWN]&&rightPlayer.hitbox.y!=600){
                if(rightPlayer.hitbox.y+SPEED*deltaTime<600) {
                    rightPlayer.hitbox.y+=SPEED*deltaTime;
                    rightPlayer.dy=DOWN;
                }
                else {
                    rightPlayer.hitbox.y=600;
                    rightPlayer.dy=NONE;
                }
            }

            draw(font);
        }
        return EXIT_SUCCESS;
    }

    int singlepayer(TTF_Font *font){

        while(!quit){
            
            currentTime = SDL_GetTicks();
            deltaTime = (currentTime - lastFrameTime) / 1000.0; 
            lastFrameTime = currentTime;

            const Uint8* key = SDL_GetKeyboardState(NULL);

            move();
            
            while (SDL_PollEvent(&event)){
                events();
            }
            
            leftPlayer.dy=NONE;
            rightPlayer.dy=NONE;
            
            if(key[SDL_SCANCODE_W]&&leftPlayer.hitbox.y!=0){
                if(leftPlayer.hitbox.y-SPEED*deltaTime>0){
                    leftPlayer.hitbox.y-=SPEED*deltaTime;
                    leftPlayer.dy=UP;
                }
                else{
                    leftPlayer.hitbox.y=0;
                    leftPlayer.dy=NONE;
                }
            }
            if(key[SDL_SCANCODE_S]&&leftPlayer.hitbox.y!=600){
                if(leftPlayer.hitbox.y+SPEED*deltaTime<600){
                    leftPlayer.hitbox.y+=SPEED*deltaTime;
                    leftPlayer.dy=DOWN;
                }
                else{
                    leftPlayer.hitbox.y=600;
                    leftPlayer.dy=NONE;
                }
            }       

            if (ball.hitbox.y+25 != rightPlayer.hitbox.y+150){       
                if(ball.hitbox.y+25 < rightPlayer.hitbox.y+150 && rightPlayer.hitbox.y!=0) {
                    if (rightPlayer.hitbox.y-SPEED*deltaTime>0){
                        rightPlayer.hitbox.y-=SPEED*deltaTime;
                        rightPlayer.dy=DOWN;
                    }
                    else{
                        rightPlayer.hitbox.y=0;
                        rightPlayer.dy=NONE;
                    }
                }

                else if(ball.hitbox.y+25 > rightPlayer.hitbox.y+150 && rightPlayer.hitbox.y!=600){
                    if(rightPlayer.hitbox.y+SPEED*deltaTime<600){
                        rightPlayer.hitbox.y+=SPEED*deltaTime;
                        rightPlayer.dy=DOWN;
                    }
                    else {
                        rightPlayer.hitbox.y=600;
                        rightPlayer.dy=NONE;
                    }
                }
            }

            draw(font);
        }
        return EXIT_SUCCESS;
    }


}extern pong;