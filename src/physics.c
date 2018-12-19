//
// Created by sajjad on 19/12/18.
//

#include "physics.h"
#include "structs.h"
#include "view.h"
void move_tank(Tank* tank,int mvment[]){
    if(mvment[0]==1) (tank->y)--;
    if(mvment[1]==1) (tank->y)++;
    if(mvment[2]==1) (tank->angle)++;
    if(mvment[3]==1) (tank->angle)--;
}
