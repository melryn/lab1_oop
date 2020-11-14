#include <iostream>
#include "plate.h"

Plate::Plate(): Base(){
    radius = 1.;
}

Plate::Plate(double r, double t, double x, double y): Base(t, x, y){
    if (r < 1. || r > 10000.)
        radius = 1;
    else
        radius = r;
}

Plate::Plate(const Plate *p): Base(p->getThickness(), p->getCoordinateX(), p->getCoordinateY()){
    radius = p->radius;
}

double Plate::getRadius() const{
    return this->radius;
}

void Plate::setRadius(double r){
    if (r < 1 || r > 10000.)
        this->radius = 1;
    else
        this->radius = r;
}
