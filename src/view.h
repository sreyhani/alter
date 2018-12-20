//
// Created by sajjad on 17/12/18.
//
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include "structs.h"
#include <stdbool.h>
#ifndef FOPPROJECT_VIEW_H
#define FOPPROJECT_VIEW_H

void init_window();
void quit_window();
void set_background();
void draw_tank(Tank* tank);
void handle_events(int mvment[]);
void draw_walls(Map* map);
void draw_bullets(Tank* tank);
//how to make line 15 & 16 const int
int  MAP_HEIGHT ;
int MAP_WIDTH ;
bool EXIT;
SDL_Renderer *renderer;
SDL_Window *window;
SDL_Event event;



#endif //FOPPROJECT_VIEW_H
