/* Name: Calvin Bui
SID: 861064458
5/12/15 */
#include "lab5.h"
#include <iostream>

using namespace std;
int main()
{
    BST<int> tmp1;
    tmp1.insert(50);
    tmp1.insert(20);
    tmp1.insert(60);
    tmp1.insert(10);
    tmp1.insert(40);
    tmp1.insert(35);
    tmp1.insert(45);
    tmp1.insert(70);

    //tmp1.clearSelect();
    tmp1.minCover();
    tmp1.displayMinCover();
    int array[1000];
    tmp1.findSumPath(tmp1.root, 80, array);
    tmp1.printVertSum();

   
    

    return 0;
}