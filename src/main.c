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
#include "structs.h"
const double FPS=30;
const double P=3.14159265;
int main(){
    Tanks* redtank=malloc(sizeof(Tanks));
    init_window();
    redtank->x=(rand() % 800);
    redtank->y=(rand() % 600);
    redtank->angle=P/2;
    while (1){
        set_background();
        SDL_RenderClear(renderer);
        draw_tank(redtank);




        SDL_RenderPresent(renderer);
        SDL_Delay(2000);
        //SDL_Delay(1000/FPS);
        quit_window();
        break;
        }
    return 0;
}