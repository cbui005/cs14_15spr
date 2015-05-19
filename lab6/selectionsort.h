#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__
#include <iostream>
#include <utility>
#include <vector>
#include <list>
using namespace std;

template <typename L>
void printList(L&l)
{
    for (auto it2 = l.begin(); it2 != l.end(); it2++)
        {
            cout << *it2 << ' ';
        }
        cout << endl;
}

void printList(list<pair<int,int> >&l)
{
    for (auto it : l)
    {
        cout << '(' << it.first << ',' << it.second << ") ";
    }
    cout << endl;
}


template<typename L>
void selectionsort(L&l)
{
    int cnt = 0;
    if (l.size() <= 0)
    {
        return;
    }
    auto smallest = l.begin();
    for (auto it = l.begin(); it != l.end(); it++)
    {
        smallest = it;
        for (auto it2 = it; it2 != l.end(); it2++)
        {
            if (*it2 < *smallest)
            {
                smallest = it2;
            }
        }
        if (*it != *smallest)
        {
           
            swap(*it,*smallest);
            cnt += 3;
        }
    }
    cout << "0 copes and " << cnt << " moves" << endl;
}

#endif