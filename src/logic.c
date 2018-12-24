//
// Created by sajjad on 23/12/18.
//

#include "logic.h"
#include "structs.h"
#include "physics.h"
#include <stdlib.h>
bool check_tank_collision(Tank* tank,Map* map){
    for (int i = 0; i < map->numberofwalls; i++) {
        if(( map->walls[i].x1 == map->walls[i].x2) && ( abs(tank->x - map->walls[i].x1)<20 ) && (tank->y+20 > map->walls[i].y1) && (tank->y-20 < map->walls[i].y2)) {
//            bool tmp = events[0];
//            events[0] = events[1];
//            events[1] = tmp;
//            events[2]=false;
//            events[3]=false;
//            move_tank(tank,events);
//            events[0]=false;
//            events[1]=false;
            return true;
        }
        if(( map->walls[i].y1 == map->walls[i].y2) && ( abs(tank->y - map->walls[i].y1)<20 ) && (tank->x+20 > map->walls[i].x1) && (tank->x-20 < map->walls[i].x2)) {
//            bool tmp = events[0];
//            events[0] = events[1];
//            events[1] = tmp;
//            events[2]=false;
//            events[3]=false;
//            move_tank(tank,events);
//            events[0]=false;
//            events[1]=false;
            return true;
        }
    }
    return false;
}