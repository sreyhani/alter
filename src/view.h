//
// Created by sajjad on 17/12/18.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "structs.h"
#ifndef FOPPROJECT_VIEW_H
#define FOPPROJECT_VIEW_H

void init_window();
void quit_window();
void set_background();
void draw_tank(Tanks* tank);
//how to make line 15 & 16 const int
int  MAP_HEIGHT ;
int MAP_WIDTH ;
SDL_Renderer *renderer;
SDL_Window *window;



#endif //FOPPROJECT_VIEW_H
