#ifndef PAPER_H
#define PAPER_H
#include "base.h"
#include <string>

class Paper: public Base
{
public:
    Paper();
    Paper(double w, double h, double t, double x, double y);
    Paper(const Paper *p);
    double getWidth() const;
    double getHeight() const;
    void setWidth(double w);
    void setHeight(double h);
    virtual std::string who() override{
        std::string c = "Paper";
        return c;
    }

private:
    double width, height;
};


#endif // PAPER_H
