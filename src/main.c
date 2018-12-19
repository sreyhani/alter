//
// Created by sajjad on 17/12/18.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "view.h"
#include "physics.h"
#include "structs.h"
const double FPS=30;
const double P=3.14159265;
int main(){
    Tank* redtank=malloc(sizeof(Tank));
    init_window();
    redtank->x=(rand() % 800);
    redtank->y=(rand() % 600);
    redtank->angle=P/2;
//    movment[0]=1;
//    movment[2]=1;
    while (1){
        set_background();
        SDL_RenderClear(renderer);
        draw_tank(redtank);
        handle_events(movment);
        move_tank(redtank,movment);


        SDL_RenderPresent(renderer);
//        SDL_Delay(2000);
        SDL_Delay(1000/FPS);
//        quit_window();
//        break;
        }
    return 0;
}