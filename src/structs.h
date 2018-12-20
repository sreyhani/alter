//
// Created by sajjad on 17/12/18.
//

#ifndef FOPPROJECT_STRUCTS_H
#define FOPPROJECT_STRUCTS_H
typedef struct {
    double x;
    double y;
    double angle;
} Tank;
typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Wall;
typedef struct {
    Tank* tanks;
    Wall* walls;
    int numberofwalls;
} Map;
#endif //FOPPROJECT_STRUCTS_H
