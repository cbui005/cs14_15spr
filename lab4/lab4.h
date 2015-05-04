/*
Name: Calvin Bui
SID: 861064458
Date: 5/3/15
*/
#ifndef __LAB4_H__
#define __LAB4_H__
#include <iostream>
#include <queue>
using namespace std;
void coprime_print_preorder(int k, int m, int n)
{
    if ((m + n) >= k)
    {
        return;
    }
    cout << m << ' ' << n << endl;
    coprime_print_preorder(k,2*m-n,m);
    coprime_print_preorder(k,2*m+n,m);
    coprime_print_preorder(k,m+2*n,n);
}

void coprime_print_postorder(int k, int m, int n)
{
    if ((m + n) >= k)
    {
        return;
    }
    coprime_print_postorder(k,2*m-n,m);
    coprime_print_postorder(k,2*m+n,m);
    coprime_print_postorder(k,m+2*n,n);
    cout << m << ',' << n << endl;
}

struct comp_greater
{
    bool operator() (pair<int,int>a, pair<int,int> b)
    {
        if (a.first + a.second > b.first + b.second)
        {
            return true;
        }
        else if (a.first + a.second == b.first + b.second)
        {
            if (a.first >= b.first)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
};

void coprime_priority_print(int k)
{
    priority_queue<pair<int,int>, vector<pair<int, int> >, comp_greater > tmp;
    tmp.push(pair<int,int>(2,1));
    tmp.push(pair<int,int>(3,1));
    while (!tmp.empty())
    {
        if (tmp.top().first + tmp.top().second < k)
        {
            cout << tmp.top().first << " " <<  tmp.top().second << endl;
            tmp.push(pair<int,int> (tmp.top().first*2 - tmp.top().second, tmp.top().first));
            tmp.push(pair<int,int> (tmp.top().first*2 + tmp.top().second, tmp.top().first));
            tmp.push(pair<int,int> (tmp.top().second*2 + tmp.top().first, tmp.top().second));
        }
        tmp.pop();
    }
}
#endif