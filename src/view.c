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
    MAP_HEIGHT=796;
    MAP_WIDTH=1024;
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
    thickLineRGBA(renderer,tank->x+40*cos(-tank->angle),tank->y+40*sin(-tank->angle),tank->x,tank->y,5,0,255,0,255);

    filledCircleRGBA(renderer,tank->x,tank->y,20,0,255,0,255);
//    int a=15; //nesfe tol tank
//    int b=10; //nesfe arz tank
//    rectangleRGBA(renderer,tank->x+(a*cos(-tank->angle)+b*sin(-tank->angle)),tank->y+(a*sin(-tank->angle)+b*cos(-tank->angle)),tank->x-(a*cos(-tank->angle)+b*sin(-tank->angle)),tank->y-(a*sin(-tank->angle)+b*cos(-tank->angle)),0,255,0,255);
}

void handle_events(int eventarr[]) {
    while (SDL_PollEvent(&event)) {
        switch (event.type){
            case SDL_WINDOWEVENT:
                if (event.window.event == SDL_WINDOWEVENT_CLOSE) eventarr[5]=1;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_UP) eventarr[0]=1;
                if(event.key.keysym.sym == SDLK_DOWN) eventarr[1]=1;
                if(event.key.keysym.sym == SDLK_RIGHT) eventarr[2]=1;
                if(event.key.keysym.sym == SDLK_LEFT) eventarr[3]=1;
                if(event.key.keysym.sym == SDLK_SPACE) eventarr[4]=1;
                break;
            case SDL_KEYUP:
                if(event.key.keysym.sym == SDLK_UP) eventarr[0]=0;
                if(event.key.keysym.sym == SDLK_DOWN) eventarr[1]=0;
                if(event.key.keysym.sym == SDLK_RIGHT) eventarr[2]=0;
                if(event.key.keysym.sym == SDLK_LEFT) eventarr[3]=0;
                if(event.key.keysym.sym == SDLK_SPACE) eventarr[4]=0;

                break;
        }

    }
}
void draw_walls(Map* map){
    for (int i = 0; i < map->numberofwalls; i++) {
        thickLineRGBA(renderer,map->walls[i].x1,map->walls[i].y1,map->walls[i].x2,map->walls[i].y2,5,255,0,0,255);
    }

}
void draw_bullets(Tank* tank){
    for (int i =0; i <5-tank->remainingbullets ; i++) {
        filledCircleRGBA(renderer,tank->bullets[i].x,tank->bullets[i].y,5,0,0,0,255);
    }
}
