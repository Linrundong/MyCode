#ifndef _STOCK_H_
#define _STOCK_H_
#include<list>
#include "user.h"
using namespace std;

class Observer;

class Subject
{
public:
    virtual ~Subject(){}
    virtual void registerObserver(Observer *) = 0;
    virtual void removeObserver(Observer *) = 0;
    virtual void notifyObserver(int) = 0;

};



class CStock : public Subject
{
public:
    CStock(){}
    ~CStock(){}
    void registerObserver(Observer * o);
    void removeObserver(Observer * o);
    void notifyObserver(int i);

private:
    list<Observer *> lisObserver;

};


#endif
