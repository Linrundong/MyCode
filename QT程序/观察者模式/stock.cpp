#include "stock.h"

void CStock::registerObserver(Observer *o)
{
    lisObserver.push_back(o);
}

void CStock::removeObserver(Observer *o)
{
    lisObserver.remove(o);
}

void CStock::notifyObserver(int i)
{
    list<Observer *>::iterator it;
    for (it = lisObserver.begin();it != lisObserver.end();++it)
    {
        Observer *obj = *it;
        obj->update(i);
    }
}
