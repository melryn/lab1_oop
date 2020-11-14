#ifndef PAPERSTACK_H
#define PAPERSTACK_H
#include <string>
#include "paper.h"
#include "plate.h"

struct ListElem
{
    friend class Base;
    Base *obj;
    ListElem *prev;
    ListElem()
    {
        obj = new Base();
        prev = nullptr;
    }
    ~ListElem(){

    }
};

struct Iterator{
private:
    ListElem *curr;
public:
    Iterator();
    Iterator(ListElem *lm);
    void incr();
    Base *get();
};

class PaperStack
{
private:
    struct ListElem *last;
    int cnt;
public:
    PaperStack();
        PaperStack(const PaperStack&);
        ~PaperStack();
        void push(const Plate &obj);
    void push(const Paper &obj);
    void pop();
    void delAll();
    void input(std::string fileName);
    void output(std::string fileName);
    int count();
    Iterator begin();
    Iterator end();
    bool isStand();
};

#endif // PAPERSTACK_H
