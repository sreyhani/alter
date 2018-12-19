//
// Created by sajjad on 17/12/18.
//

#include "view.h"
#include "structs.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "physics.h"
#include <math.h>
void init_window() {
    MAP_HEIGHT=600;
    MAP_WIDTH=800;
    SDL_Init(SDL_INIT_VIDEO);
    window= SDL_CreateWindow("AlterTank", 100, 100, MAP_WIDTH , MAP_HEIGHT, SDL_WINDOW_OPENGL);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
void quit_window(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void set_background(){
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
}
void draw_tank(Tank* tank){
    thickLineRGBA(renderer,tank->x+30*cos(-tank->angle),tank->y+30*sin(-tank->angle),tank->x,tank->y,5,255,0,0,255);
    filledCircleRGBA(renderer,tank->x,tank->y,20,255,0,0,255);
}

void handle_events(int mvment[]) {
    while (SDL_PollEvent(&event)) {
        switch (event.type){
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) quit_window();
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_UP) mvment[0]=1;
//                if(event.key.keysym.sym == SDLK_DOWN) mvment[1]=1;
                if(event.key.keysym.sym == SDLK_RIGHT) mvment[2]=1;
                if(event.key.keysym.sym == SDLK_LEFT) mvment[3]=1;
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_UP) mvment[0]=0;
//                if(event.key.keysym.sym == SDLK_DOWN) mvment[1]=0;
                if(event.key.keysym.sym == SDLK_RIGHT) mvment[2]=0;
                if(event.key.keysym.sym == SDLK_LEFT) mvment[3]=0;
                break;
        }

    }
    return 0;
}