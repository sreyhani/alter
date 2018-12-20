//
// Created by sajjad on 19/12/18.
//

#include "physics.h"
#include "structs.h"
#include "view.h"
#include "math.h"
const double P2=3.14159265;
void move_tank(Tank* tank,int events[]){
    if(events[0]==1) {
        (tank->y)+=(4*sin(-tank->angle));
        (tank->x)+=(4*cos(-tank->angle));
    }
    if(events[1]==1) {
        (tank->y)-=(4*sin(-tank->angle));
        (tank->x)-=(4*cos(-tank->angle));
    }
    if(events[2]==1) (tank->angle)-=P2/36;
    if(events[3]==1) (tank->angle)+=P2/36;
}
void fire(Tank* tank){
    if(tank->remainingbullets>0 && events[4]==1){
        tank->bullets[5-tank->remainingbullets].x=tank->x+40*cos(-tank->angle);
        tank->bullets[5-tank->remainingbullets].y=tank->y+40*sin(-tank->angle);
        tank->bullets[5-tank->remainingbullets].angle=tank->angle;
        tank->remainingbullets--;
    }
}
void move_bullets(Tank* tank){
    for (int i =0; i <5-tank->remainingbullets ; i++) {
        tank->bullets[i].x+=(6*cos(-tank->bullets[i].angle));
        tank->bullets[i].y+=(6*sin(-tank->bullets[i].angle));

    }
}