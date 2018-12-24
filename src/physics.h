//
// Created by sajjad on 19/12/18.
//
#include <stdbool.h>
#include "structs.h"
#ifndef FOPPROJECT_PHYSICS_H
#define FOPPROJECT_PHYSICS_H
void move_tank(Tank* tank,bool mvment[]);
void fire(Tank* tank);
void move_bullets(Tank* tank);

bool events[6];    //=={up,down,right,left,fire,exit}


#endif //FOPPROJECT_PHYSICS_H
