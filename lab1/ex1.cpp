#include <iostream>
#include <list>
using namespace std;

void mergeList(list<int>&list1, list<int>&list2)
{
    list<int>::iterator i = list1.begin();
    ++i;
    list<int>::iterator j;
    for(j=list2.begin(); j != list2.end(); ++j)
    {            
        list1.insert(i,*j);
        ++i;
    }
    return;
    
}

int main()
{
    list<int> list1;
    list<int> list2;
    int tmp = 0;
    cout << "Fill in list 1 (end with -1):  ";
    cin >> tmp;
    do
    {
        list1.push_back(tmp);
        cin >> tmp;
    }
    while (tmp != -1);
    cout << "Fill in list 2 (end with -1): ";
    cin >> tmp;
    do
    {
        list2.push_back(tmp);
        cin >> tmp;
    }
    while (tmp != -1);

    mergeList(list1,list2);
    list<int>::iterator i;
	 
	for(i=list1.begin(); i != list1.end(); ++i) cout << *i << " ";
	cout << endl;
	
    

    return 0;
    
}