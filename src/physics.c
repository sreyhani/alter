//
// Created by sajjad on 19/12/18.
//

#include "physics.h"
#include "structs.h"
#include "view.h"
#include "math.h"
const double P2=3.14159265;
void move_tank(Tank* tank,int mvment[]){
    if(mvment[0]==1) {
        (tank->y)+=(4*sin(-tank->angle));
        (tank->x)+=(4*cos(-tank->angle));
    }
    if(mvment[1]==1) {
        (tank->y)-=(4*sin(-tank->angle));
        (tank->x)-=(4*cos(-tank->angle));
    }
    if(mvment[2]==1) (tank->angle)-=P2/36;
    if(mvment[3]==1) (tank->angle)+=P2/36;
}
void fire(Tank* tank){
    if(tank->remainingbullets>0){
        tank->bullets[5-tank->remainingbullets].x=tank->x;
        tank->bullets[5-tank->remainingbullets].y=tank->y;
        tank->bullets[5-tank->remainingbullets].angle=tank->angle;
        tank->remainingbullets--;
    }
}