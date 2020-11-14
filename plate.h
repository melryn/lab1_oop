#ifndef PLATE_H
#define PLATE_H
#include "base.h"
#include <string>

class Plate: public Base{
public:
    Plate();
    Plate(double r, double t, double x, double y);
    Plate (const Plate *p);
    double getRadius() const;
    void setRadius(double r);
    virtual std::string who() override{
        std::string c = "Plate";
        return c;
    }

private:
    double radius;
};

#endif // PLATE_H
