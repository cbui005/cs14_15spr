#include "selectionsort.h"
#include <iostream>
/* Calvin Bui
SID 861064458
*/
#include <list>
#include <vector>
#include <map>
using namespace std;

int main()
{

    vector<int> A;
    list<pair<int,int> > tmp { pair<int,int>(1,2), pair<int,int>(3,-1), 
                                 pair<int,int>(-1,3), pair<int,int>(0,0)};
    selectionsort(tmp);
    printList(tmp);
    
    A.push_back(2);
    A.push_back(4);
    A.push_back(5);
    A.push_back(1);
    A.push_back(8);
    A.push_back(9);
    cout << "pre: ";
    printList(A);
    selectionsort(A);
    cout << "post: ";
    printList(A);
    
    //printList(pairA);
    //selectionsort(pairA);
    //printList(pairA);
    return 0;
}