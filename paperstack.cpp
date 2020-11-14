#include "paperstack.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <cmath>

PaperStack::PaperStack()
{
    last = nullptr;
    cnt = 0;
}

PaperStack::~PaperStack()
{
    delAll();
}

PaperStack::PaperStack(const PaperStack &old){
    ListElem *uk = old.last;
    last = new ListElem;
    ListElem *un = last;
    cnt = old.cnt;
    if (uk->obj->who() == "Paper"){
        Paper p = dynamic_cast<Paper*>(uk->obj);
        un->obj = new Paper(p);

    }
    if (uk->obj->who() == "Plate"){
        Plate pl = dynamic_cast<Plate*>(uk->obj);
        un->obj = new Plate(pl);
    }
    while(uk->prev){
        uk = uk->prev;
        un->prev = new ListElem();
        un = un->prev;
        if (uk->obj->who() == "Paper"){
            Paper p = dynamic_cast<Paper*>(uk->obj);
            un->obj = new Paper(p);

        }
        if (uk->obj->who() == "Plate"){
            Plate pl = dynamic_cast<Plate*>(uk->obj);
            un->obj = new Plate(pl);
        }
    }
    un->prev = nullptr;

}



void PaperStack::push(const Plate &obj){
    ListElem *curr = new ListElem;
    curr->obj = new Plate(obj);
    ListElem *temp = new ListElem;
    if (last){
        temp = last;
        last = curr;
        last->prev = temp;
    }
    else {
        last = new ListElem;
        last->obj = new Plate(obj);
    }
    cnt++;
}

void PaperStack::push(const Paper &obj){
    ListElem *curr = new ListElem;
    curr->obj = new Paper(obj);
    ListElem *temp = new ListElem;
    if (last){
        temp = last;
        last = curr;
        last->prev = temp;
    }
    else {
        last = new ListElem;
        last->obj = new Paper(obj);
    }
    cnt++;
}

void PaperStack::pop(){
    ListElem *curr = new ListElem;
    if (last){
        curr = last;
        last = last->prev;
        delete curr;
        cnt--;
    }
}

void PaperStack::delAll(){
    while(last){
        pop();
    }
}

int PaperStack::count(){
    return cnt;
}

void PaperStack::input(std::string fileName){
    std::ifstream file;
    file.open(fileName, std::ios::in);
    double w, h, t, x, y, r;
    std::string className;
    if (file.is_open())
    {
        while (!file.eof())
        {
            file >> className;
            if (className == "Paper")
            {
                file >> w;
                file >> h;
                file >> t;
                file >> x;
                file >> y;
                Paper *temp = new Paper(w, h, t, x, y);
                push(temp);
            }
            else if (className == "Plate")
            {
                file >> r;
                file >> t;
                file >> x;
                file >> y;
                Plate *temp = new Plate(r, t, x, y);
                push(temp);
            }
        }
    }
}

void PaperStack::output(std::string fileName){
    std::ofstream file;
    file.open(fileName, std::ios::out);
    ListElem *curr = new ListElem;
    int c = cnt - 1;
    if (file.is_open())
    {
        if (last){
            while (c >= 0){
                curr = last;
                for (int i = 0; i < c; i++)
                    curr = curr->prev;
                if (curr->obj->who() == "Paper")
                {
                    Paper *temp = dynamic_cast<Paper*>(curr->obj);
                    file << temp->who() << std::endl;
                    file << temp->getWidth() << std::endl;
                    file << temp->getHeight() << std::endl;
                    file << temp->getThickness() << std::endl;
                    file << temp->getCoordinateX() << std::endl;
                    file << temp->getCoordinateY() << std::endl;
                    file << std::endl;
                }
                else if (curr->obj->who() == "Plate")
                {
                    Plate *temp = dynamic_cast<Plate*>(curr->obj);
                    file << temp->who() << std::endl;
                    file << temp->getRadius() << std::endl;
                    file << temp->getThickness() << std::endl;
                    file << temp->getCoordinateX() << std::endl;
                    file << temp->getCoordinateY() << std::endl;
                    file << std::endl;
                }
                c--;
            }   
        }
    }
}

Iterator::Iterator(){
    curr = nullptr;
}

Iterator::Iterator(ListElem *lm){
    curr = lm;
}

Iterator PaperStack::begin(){
    Iterator *iter = new Iterator(last);
    return *iter;
}

Iterator PaperStack::end(){
    ListElem *curr = new ListElem;
    curr = last;
    while(curr->prev)
        curr = curr->prev;
    Iterator *iter = new Iterator(curr);
    return *iter;
}

void Iterator::incr()
{
    curr = curr->prev;
}

Base *Iterator::get()
{
    return curr->obj;
}

bool PaperStack::isStand(){
    bool b = true;
    double M = 0;
    double xc = 0, yc = 0;
    double sumX = 0, sumY = 0;
    double firstX = 0, firstY = 0, firstW = 0, firstH = 0;
    if (cnt > 0){
        Iterator iter = this->begin();
        for (iter; iter.get() != this->end().get(); iter.incr()) {
            if(iter.get()->who() == "Paper"){
                Paper *pp = new Paper();
                pp = dynamic_cast<Paper*>(iter.get());
                double m = (pp->getWidth() * pp->getHeight() / 1000000) * 80;
                M += m;
                sumX += m * pp->getCoordinateX();
                sumY += m * pp->getCoordinateY();
            }
            if(iter.get()->who() == "Plate"){
                Plate *pl = new Plate();
                pl = dynamic_cast<Plate*>(iter.get());
                double m = (pl->getRadius() * pl->getRadius() * 3.14 / 1000000) * 80;
                M += m;
                sumX += m * pl->getCoordinateX();
                sumY += m * pl->getCoordinateY();
            }
        }
        if(iter.get()->who() == "Paper"){
            Paper *pp = new Paper();
            pp = dynamic_cast<Paper*>(iter.get());
            firstW = pp->getWidth() / 2;
            firstH = pp->getHeight() / 2;
            firstX = pp->getCoordinateX();
            firstY = pp->getCoordinateY();
            double m = (pp->getWidth() * pp->getHeight() / 1000000) * 80;
            M += m;
            sumX += m * pp->getCoordinateX();
            sumY += m * pp->getCoordinateY();
        }
        if(iter.get()->who() == "Plate"){
            Plate *pl = new Plate();
            pl = dynamic_cast<Plate*>(iter.get());
            firstW = pl->getRadius() / 2;
            firstH = pl->getRadius() / 2;
            firstX = pl->getCoordinateX();
            firstY = pl->getCoordinateY();
            double m = (pl->getRadius() * pl->getRadius() * 3.14 / 1000000) * 80;
            M += m;
            sumX += m * pl->getCoordinateX();
            sumY += m * pl->getCoordinateY();
        }

        xc = sumX / M;
        yc = sumY / M;
    }
    if (std::abs(xc - firstX) > firstW || std::abs(yc - firstY) > firstH)
        b = false;
    return b;
}
