/*
Name: Calvin Bui
SID: 861064458
Date: 5/3/15
*/
#include "lab4.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Error on arguments";
        exit(-1);
    }
    int k = 9;
    cout << "pre-order" << endl;
    coprime_print_preorder(atoi(argv[1]),2,1);
    coprime_print_preorder(atoi(argv[1]),3,1);
    cout << endl << "printing post order" << endl;
    coprime_print_postorder(atoi(argv[1]),2,1);
    coprime_print_postorder(atoi(argv[1]),3,1);
    cout << endl << "printing priority sorted" << endl;

    coprime_priority_print(atoi(argv[1]));
}