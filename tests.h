#ifndef TESTS_H
#define TESTS_H


#include <float.h>
#include <iostream>
#include <QRandomGenerator>
#include "paper.h"
#include "paperstack.h"

namespace Random
{

double realNumber(double from = -DBL_MAX/2, double to = DBL_MAX/2) {
    return from + (to - from) * QRandomGenerator::global()->generateDouble();
}

}


#define MIN_PAPER_SIZE 1.
#define MAX_PAPER_SIZE 10000.
#define MIN_T 0.05
#define MAX_T 3.
#define MIN_XY -10000.
#define MAX_XY 10000.
#define MIN_CNT 0


namespace Test
{

void assertValidity(const Paper &object){
    assert(object.getWidth() >= MIN_PAPER_SIZE);
    assert(object.getWidth() <= MAX_PAPER_SIZE);
    assert(object.getHeight() >= MIN_PAPER_SIZE);
    assert(object.getHeight() <= MAX_PAPER_SIZE);
    assert(object.getThickness() >= MIN_T);
    assert(object.getThickness() <= MAX_T);
    assert(object.getCoordinateX() >= MIN_XY);
    assert(object.getCoordinateX() <= MAX_XY);
    assert(object.getCoordinateY() >= MIN_XY);
    assert(object.getCoordinateY() <= MAX_XY);
}

void assertEquality(const Paper &first, const Paper &second){
    assert(abs(first.getWidth() - second.getWidth()) < 0.01);
    assert(abs(first.getHeight() - second.getHeight()) < 0.01);
    assert(abs(first.getThickness() - second.getThickness()) < 0.01);
    assert(abs(first.getCoordinateX() - second.getCoordinateX()) < 0.01);
    assert(abs(first.getCoordinateY() - second.getCoordinateY()) < 0.01);
}

void assertStability(Paper &object){
    double width = Random::realNumber(MIN_PAPER_SIZE, MAX_PAPER_SIZE);
    object.setWidth(width);
    assert(object.getWidth() == width);
    double errorW = Random::realNumber(MAX_PAPER_SIZE);
    object.setWidth(errorW);
    assert(object.getWidth() != errorW);
    assert(object.getWidth() == MIN_PAPER_SIZE);

    double height = Random::realNumber(MIN_PAPER_SIZE, MAX_PAPER_SIZE);
    object.setHeight(height);
    assert(object.getHeight() == height);
    double errorH = Random::realNumber(MAX_PAPER_SIZE);
    object.setHeight(errorH);
    assert(object.getHeight() != errorH);
    assert(object.getHeight() == MIN_PAPER_SIZE);

    double thickness = Random::realNumber(MIN_T, MAX_T);
    object.setThickness(thickness);
    assert(object.getThickness() == thickness);
    double errorT = Random::realNumber(MAX_T);
    object.setThickness(errorT);
    assert(object.getThickness() != errorT);
    assert(object.getThickness() == MIN_T);

    double x = Random::realNumber(MIN_XY, MAX_XY);
    object.setCoordinateX(x);
    assert(object.getCoordinateX() == x);
    double errorX = Random::realNumber(MAX_XY);
    object.setCoordinateX(errorX);
    assert(object.getCoordinateX() != errorX);
    assert(object.getCoordinateX() == MIN_XY);

    double y = Random::realNumber(MIN_XY, MAX_XY);
    object.setCoordinateY(y);
    assert(object.getCoordinateY() == y);
    double errorY = Random::realNumber(MAX_XY);
    object.setCoordinateY(errorX);
    assert(object.getCoordinateY() != errorY);
    assert(object.getCoordinateY() == MIN_XY);

}

void run(){
    Paper defaultObject;
        assertValidity(defaultObject);
        for (int i = 0; i < 1000; i++)
        {
            Paper randomObject(Random::realNumber(MIN_PAPER_SIZE - 100, MAX_PAPER_SIZE + 100),
                              Random::realNumber(MIN_PAPER_SIZE - 100, MAX_PAPER_SIZE + 100),
                              Random::realNumber(MIN_T - 0.03, MAX_T + 0.03),
                              Random::realNumber(MIN_XY - 100, MAX_XY + 100),
                              Random::realNumber(MIN_XY - 100, MAX_XY + 100));
            assertValidity(randomObject);
            Paper copyObject(randomObject);
            assertValidity(copyObject);
            assertEquality(randomObject, copyObject);
            assertStability(copyObject);
            assertValidity(copyObject);
        }
        std::cout << "\nTESTS PASSED SUCCESSFULLY_1\n";
}
};

namespace Test2 {
void assertValidity(PaperStack &object)
{
    assert(object.count() >= 0);
    Iterator it = object.begin();
    for (it = object.begin(); it.get() != object.end().get(); it.incr())
    {
        if (it.get()->who() == "Plate")
        {

            Plate *temp= dynamic_cast<Plate*>(it.get());
            assert(temp->getThickness() >= MIN_T);
            assert(temp->getThickness() <= MAX_T);
            assert(temp->getCoordinateX() >= MIN_XY);
            assert(temp->getCoordinateX() <= MAX_XY);
            assert(temp->getCoordinateY() >= MIN_XY);
            assert(temp->getCoordinateY() <= MAX_XY);
            assert(temp->getRadius() >= MIN_PAPER_SIZE);
            assert(temp->getRadius() <= MAX_PAPER_SIZE);
        }
        if (it.get()->who() == "Paper")
        {
            Paper *temp = dynamic_cast<Paper*>(it.get());
            assert(temp->getWidth() >= MIN_PAPER_SIZE);
            assert(temp->getWidth() <= MAX_PAPER_SIZE);
            assert(temp->getHeight() >= MIN_PAPER_SIZE);
            assert(temp->getHeight() <= MAX_PAPER_SIZE);
            assert(temp->getThickness() >= MIN_T);
            assert(temp->getThickness() <= MAX_T);
            assert(temp->getCoordinateX() >= MIN_XY);
            assert(temp->getCoordinateX() <= MAX_XY);
            assert(temp->getCoordinateY() >= MIN_XY);
            assert(temp->getCoordinateY() <= MAX_XY);
        }
    }
}
void assertEquality(PaperStack &first, PaperStack &second)
{
    assert(first.count() == second.count());
    Iterator iterf = first.begin();
    Iterator iters = second.begin();
    for(iterf = first.begin(), iters = second.begin(); iterf.get() != first.end().get() && iters.get() != second.end().get(); iters.incr(), iterf.incr())
    {
        if (iterf.get()->who() == "Plate" && iters.get()->who() == "Plate")
        {
            Plate *tempf= dynamic_cast<Plate*>(iterf.get());
            Plate *temps= dynamic_cast<Plate*>(iters.get());
            assert(abs(tempf->getRadius() - temps->getRadius()) < 0.01);
            assert(abs(tempf->getThickness() - temps->getThickness()) < 0.01);
            assert(abs(tempf->getCoordinateX() - temps->getCoordinateX()) < 0.01);
            assert(abs(tempf->getCoordinateY() - temps->getCoordinateY()) < 0.01);
        }
        if (iterf.get()->who() == "Paper" && iters.get()->who() == "Paper")
        {
            Paper *tempf = dynamic_cast<Paper*>(iterf.get());
            Paper *temps = dynamic_cast<Paper*>(iters.get());
            assert(abs(tempf->getThickness() - temps->getThickness()) < 0.01);
            assert(abs(tempf->getCoordinateX() - temps->getCoordinateX()) < 0.01);
            assert(abs(tempf->getCoordinateY() - temps->getCoordinateY()) < 0.01);
            assert(abs(tempf->getHeight() - temps->getHeight()) < 0.01);
            assert(abs(tempf->getWidth() - temps->getWidth()) < 0.01);
        }

        }
    if (iterf.get()->who() == "Plate" && iters.get()->who() == "Plate")
    {
        Plate *tempf= dynamic_cast<Plate*>(iterf.get());
        Plate *temps= dynamic_cast<Plate*>(iters.get());
        assert(abs(tempf->getRadius() - temps->getRadius()) < 0.01);
        assert(abs(tempf->getThickness() - temps->getThickness()) < 0.01);
        assert(abs(tempf->getCoordinateX() - temps->getCoordinateX()) < 0.01);
        assert(abs(tempf->getCoordinateY() - temps->getCoordinateY()) < 0.01);
    }
    if (iterf.get()->who() == "Paper" && iters.get()->who() == "Paper")
    {
        Paper *tempf = dynamic_cast<Paper*>(iterf.get());
        Paper *temps = dynamic_cast<Paper*>(iters.get());
        assert(abs(tempf->getThickness() - temps->getThickness()) < 0.01);
        assert(abs(tempf->getCoordinateX() - temps->getCoordinateX()) < 0.01);
        assert(abs(tempf->getCoordinateY() - temps->getCoordinateY()) < 0.01);
        assert(abs(tempf->getHeight() - temps->getHeight()) < 0.01);
        assert(abs(tempf->getWidth() - temps->getWidth()) < 0.01);
    }
}
void assertFile(PaperStack &object){
    object.output("C:\\Study\\Qt\\test1.txt");
    PaperStack *inputPs = new PaperStack();
    inputPs->input("C:\\Study\\Qt\\test1.txt");
    Iterator iterf = object.begin();
    Iterator iters = inputPs->begin();
    Test2::assertEquality(object, *inputPs);
}
void outputToConsole(PaperStack &object){
    int c = 1;
    Iterator it = object.begin();

    for(it = object.begin(); it.get() != object.end().get(); it.incr())
    {
        if (it.get()->who() == "Plate")
        {

            Plate *temp= dynamic_cast<Plate*>(it.get());
            std::cout << "Number: " << c << std::endl <<
                         "Radius: " << temp->getRadius() << std::endl <<
                         "Thickness: " << temp->getThickness() << std::endl <<
                         "X: " << temp->getCoordinateX() << std::endl <<
                         "Y: " << temp->getCoordinateY() << std::endl;
            c++;
        }
        if (it.get()->who() == "Paper")
        {
            Paper *temp = dynamic_cast<Paper*>(it.get());
            std::cout << "Number: " << c << std::endl <<
                         "Width: " << temp->getWidth() << std::endl <<
                         "Height: " << temp->getHeight() << std::endl <<
                         "Thickness: " << temp->getThickness() << std::endl <<
                         "X: " << temp->getCoordinateX() << std::endl <<
                         "Y: " << temp->getCoordinateY() << std::endl;
            c++;
        }

    }
    if (it.get()->who() == "Plate")
    {

        Plate *temp= dynamic_cast<Plate*>(it.get());
        std::cout << "Number: " << c << std::endl <<
                     "Radius: " << temp->getRadius() << std::endl <<
                     "Thickness: " << temp->getThickness() << std::endl <<
                     "X: " << temp->getCoordinateX() << std::endl <<
                     "Y: " << temp->getCoordinateY() << std::endl;
        c++;
    }
    if (it.get()->who() == "Paper")
    {
        Paper *temp = dynamic_cast<Paper*>(it.get());
        std::cout << "Number: " << c << std::endl <<
                     "Width: " << temp->getWidth() << std::endl <<
                     "Height: " << temp->getHeight() << std::endl <<
                     "Thickness: " << temp->getThickness() << std::endl <<
                     "X: " << temp->getCoordinateX() << std::endl <<
                     "Y: " << temp->getCoordinateY() << std::endl;
        c++;
    }
}

void run(){
    std::cout << "SUCCESSFUL" << std::endl;
    PaperStack defaultPs;
    for (int j = 0; j < 6; j++){
            Paper randomObject(Random::realNumber(MIN_PAPER_SIZE - 100, MAX_PAPER_SIZE + 100),
                              Random::realNumber(MIN_PAPER_SIZE - 100, MAX_PAPER_SIZE + 100),
                              Random::realNumber(MIN_T - 0.03, MAX_T + 0.03),
                              Random::realNumber(MIN_XY - 100, MAX_XY + 100),
                              Random::realNumber(MIN_XY - 100, MAX_XY + 100));
            defaultPs.push(randomObject);
            Test::assertValidity(randomObject);
        }

    std::cout << "SUCCESSFUL" << std::endl;
    outputToConsole(defaultPs);
    defaultPs.output("C:\\Study\\test.txt");
    PaperStack newPs;
    newPs.input("C:\\Study\\test.txt");
    std::cout << std::endl;
    outputToConsole(newPs);
    std::cout << "SUCCESSFUL" << std::endl;
    std::cout << "\nTESTS PASSED SUCCESSFULLY_2\n";


}
};

#endif // TESTS_H
