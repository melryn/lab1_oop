#include "paper.h"
#include <iostream>


#define MIN_PAPER_SIZE 1.
#define MAX_PAPER_SIZE 10000.
#define MIN_T 0.05
#define MAX_T 3.
#define MIN_XY -10000.
#define MAX_XY 10000.

Paper::Paper(): Base(){
    width = 1;
    height = 1;
}

Paper::Paper(double w, double h, double t, double x, double y): Base(t, x, y){
    if (w < MIN_PAPER_SIZE || w > MAX_PAPER_SIZE){
        width = MIN_PAPER_SIZE;
    }
    else
        width = w;

    if (h < MIN_PAPER_SIZE || h > MAX_PAPER_SIZE){
        height = MIN_PAPER_SIZE;
    }
    else
        height = h;

}

Paper::Paper(const Paper *p): Base(p->getThickness(), p->getCoordinateX(), p->getCoordinateY()){
    width = p->width;
    height = p->height;
}

double Paper::getWidth() const{
    return this->width;
}

double Paper::getHeight() const{
    return this->height;
}


void Paper::setWidth(double w){
    if (w < MIN_PAPER_SIZE || w > MAX_PAPER_SIZE)
        this->width = MIN_PAPER_SIZE;
    else
        this->width = w;
}

void Paper::setHeight(double h){
    if (h < MIN_PAPER_SIZE || h > MAX_PAPER_SIZE)
        this->height = MIN_PAPER_SIZE;
    else
        this->height = h;
}


