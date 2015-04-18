#include <iostream>
#include "lab2.h"
using namespace std;


int main()
{
    List<int> list1;
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);
    list1.display();
    cout << endl;
    list1.elementSwap(list1,0);
    list1.display();
    cout << endl;
    return 0;
}