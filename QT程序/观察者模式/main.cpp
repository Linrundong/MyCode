#include <iostream>
#include "user.h"
#include "stock.h"

using namespace std;


int main()
{
    cout << "Hello World!" << endl;

    CStock *Stock = new CStock;
    CUser_1 *User1 = new CUser_1(1000,"user1");
    CUser_2 *User2 = new CUser_2(1600,"user2");

    Stock->registerObserver(User1);
    Stock->registerObserver(User2);
    Stock->notifyObserver(1500);
    Stock->notifyObserver(1000);
    Stock->notifyObserver(800);
    Stock->notifyObserver(1300);

    return 0;
}
