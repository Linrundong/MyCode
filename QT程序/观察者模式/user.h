#ifndef USER_H
#define USER_H

#include<string>
#include "stock.h"
using namespace ::std;

class Observer
{
public:
    virtual ~Observer (){}
    virtual void update(int) = 0;
};

class Subject;

class CUser_1 : public Observer
{
public:
    ~CUser_1(){}
    CUser_1(int i,string j)
        :m_nCurentPrice(i), m_nPastPrice(0),username(j)
    {}
    void update(int newprice);

private:
    int m_nCurentPrice;
    int m_nPastPrice;
    string username;
};


class CUser_2 : public Observer
{
public:
    ~CUser_2(){}
    CUser_2(int i,string j)
        :m_nCurentPrice(i), m_nPastPrice(0),username(j)
    {}
    void update(int newprice);

private:

    int m_nCurentPrice;
    int m_nPastPrice;
    string username;
};


#endif // USER_H
