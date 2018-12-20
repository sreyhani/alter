//
// Created by sajjad on 17/12/18.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "view.h"
#include "physics.h"
#include "structs.h"
const double FPS=30;
const double P=3.14159265;
void read_map_file(Map* map,char* filepath);
int main(){
    Tank* redtank=malloc(sizeof(Tank));
    Map* map=malloc(sizeof(Map));
    map->walls=malloc(sizeof(Wall)*100);
    read_map_file(map,"../src/mapmap.txt");
    printf("%d",map->walls[1].x2);
    init_window();
    redtank->x=(rand() % 800);
    redtank->y=(rand() % 600);
    redtank->angle=P/2;
    EXIT=false;
    while (!EXIT){
        set_background();
        SDL_RenderClear(renderer);
        draw_tank(redtank);
        handle_events(movment);
        move_tank(redtank,movment);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000/FPS);
        }

    return 0;
}
void read_map_file(Map* map,char* filepath){
    FILE *mapfile;
    char wallnum[50];
    mapfile = fopen(filepath,"r");
    fgets(wallnum,50,(FILE*)mapfile);
    map->numberofwalls=atoi(wallnum);
    for (int i = 0; i < map->numberofwalls; i++) {
        char tmp[25];
        fgets(tmp,25,mapfile);
        map->walls[i].x1=tmp[0]-'0';
        map->walls[i].y1=tmp[2]-'0';
        map->walls[i].x2=tmp[4]-'0';
        map->walls[i].y2=tmp[6]-'0';
    }
    fclose(mapfile);
}