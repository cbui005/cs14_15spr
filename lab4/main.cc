/*
Name: Calvin Bui
SID: 861064458
Date: 5/3/15
*/
#include "lab4.h"
#include <iostream>
using namespace std;

int main()
{
    int k = 9;
    cout << "pre-order" << endl;
    coprime_print_preorder(k,2,1);
    coprime_print_preorder(k,3,1);
    cout << endl << "printing post order" << endl;
    coprime_print_postorder(k,2,1);
    coprime_print_postorder(k,3,1);
    cout << endl << "printing priority sorted" << endl;

    coprime_priority_print(k);
}