#include <iostream>
#include "base.h"


#define MIN_T 0.05
#define MAX_T 3.
#define MIN_XY -10000.
#define MAX_XY 10000.


Base::Base(){
    thickness = 0.05;
    coordX = 0;
    coordY = 0;
}

Base::Base(double t, double x, double y){
    if (t < MIN_T || t > MAX_T){
        thickness = MIN_T;
    }
    else
        thickness = t;
    if (x < MIN_XY || x > MAX_XY){
        coordX = MIN_XY;
    }
    else
        coordX = x;
    if (y < MIN_XY || y > MAX_XY){
        coordY = MIN_XY;
    }
    else
        coordY = y;
}



double Base::getThickness() const{
    return this->thickness;
}

double Base::getCoordinateX() const{
    return this->coordX;
}

double Base::getCoordinateY() const{
    return this->coordY;
}

void Base::setThickness(double t){
    if (t < MIN_T || t > MAX_T)
        this->thickness = MIN_T;
    else
        this->thickness = t;
}

void Base::setCoordinateX(double x){
    if (x < MIN_XY || x > MAX_XY)
        this->coordX = MIN_XY;
    else
        this->coordX = x;
}

void Base::setCoordinateY(double y){
    if (y < MIN_XY || y > MAX_XY)
        this->coordY = MIN_XY;
    else
        this->coordY = y;
}
