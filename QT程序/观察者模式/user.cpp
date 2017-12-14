#include"user.h"
#include <iostream>
using namespace std;

void CUser_1::update(int newprice)
{
    cout <<"user:"<< username;
    cout << "   past price:" << m_nCurentPrice;
    cout << "   current price:" << newprice;
    if (newprice > m_nCurentPrice)
    {
        cout << "  up" << endl;
    }
    else
    {
        cout << "  down" << endl;
    }
    m_nPastPrice = m_nCurentPrice;
    m_nCurentPrice = newprice;
}

void CUser_2::update(int newprice)
{
    cout <<"user:"<< username;
    cout << "   past price:" << m_nCurentPrice;
    cout << "   current price:" << newprice;

    if (newprice > m_nCurentPrice)
    {
        cout << "  up" << endl;
    }
    else
    {
        cout << "  down" << endl;
    }
    m_nPastPrice = m_nCurentPrice;
    m_nCurentPrice = newprice;
}
