//
// Created by sajjad on 17/12/18.
//
#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "physics.h"
#include "structs.h"
#include "logic.h"

const double FPS=30;
const double P=3.14159265;
void read_map_file(Map* map,char* filepath);
int main(){

    Tank* redtank=malloc(sizeof(Tank));
    redtank->bullets=malloc(sizeof(Bullet)*5);
    Map* map=malloc(sizeof(Map));
    map->walls=malloc(sizeof(Wall)*100);

    read_map_file(map,"../src/maps/map2.txt");
    init_window();

    redtank->x = 150;
    redtank->y = 150;
    redtank->angle=P/2;
    redtank->remainingbullets=5;
    while (events[5]!=1){
        set_background();
        SDL_RenderClear(renderer);
        draw_walls(map);
        draw_tank(redtank);
        handle_events(events);
        move_tank(redtank,events);
        if(check_tank_collision(redtank,map)==true) {
            bool moveback[4] = {events[1], events[0], false, false};
            move_tank(redtank, moveback);
            for (int i = 0; i <4 ; ++i) {
                events[i]=false;
            }
        }
        fire(redtank);
        draw_bullets(redtank);
        move_bullets(redtank);

        SDL_RenderPresent(renderer);
        SDL_Delay(1000/FPS);
        }
    quit_window();
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
        map->walls[i].x1=1024/11*(tmp[0]-'0'+1);
        map->walls[i].y1=796/11*(tmp[2]-'0'+1);
        map->walls[i].x2=1024/11*(tmp[4]-'0'+1);
        map->walls[i].y2=796/11*(tmp[6]-'0'+1);
    }
    fclose(mapfile);
}