#ifndef BASE_H
#define BASE_H
#include <string>


class Base
{
public:
    Base();
    Base(double t, double x, double y);
    virtual std::string who(){
        std::string c = "Base";
        return c;
    }
    double getThickness() const;
    double getCoordinateX() const;
    double getCoordinateY() const;
    void setCoordinateX(double x);
    void setCoordinateY(double x);
    void setThickness(double t);

protected:
    double thickness, coordX, coordY;
};

#endif // BASE_H
