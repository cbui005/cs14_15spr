/*
Name: Calvin Bui
SID: 861064458
Date: 4/18
*/
#include <iostream>
#include "lab2.h"
#include <forward_list>
using namespace std;

bool isPrime(int i) 
{
    int tmp;
    for (tmp = 2; tmp < i; tmp++)
    {
        if (i % tmp == 0)
        {
            return false;
        }
    }
    return true;
}

int primeCount(forward_list<int> lst)
{
    if (lst.end() == lst.begin())
    {
        return 0;
    }
    else if (isPrime(*lst.begin()) == true)
    {
        lst.pop_front();
        return 1 + primeCount(lst);
    }
    lst.pop_front();
    return primeCount(lst);
}

int main()
{
    List<int> list1;
    list1.push_back(5);
    list1.push_back(6);
    list1.push_back(7);
    list1.display();
    cout << endl;
    list1.elementSwap(0);
    list1.display();
    cout << endl;
    return 0;
}