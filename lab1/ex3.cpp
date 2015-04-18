#include <iostream>
#include <list>
using namespace std;

void rotate(list<int>&list1, int node)
{
    list<int>::iterator i = list1.begin();
    for (int j = 0; j < node; j++)
    {
        i = list1.begin();
        list1.push_back(*i);
        list1.pop_front();
    }
    return;
}

int main()
{
    list<int> list1;
    int tmp = 0;
    cout << "Fill in list 1 (end with -1):  ";
    cin >> tmp;
    do
    {
        list1.push_back(tmp);
        cin >> tmp;
    }
    while (tmp != -1);
    cout << "Enter node: ";
    cin >> tmp;
    rotate(list1,tmp);
    
    list<int>::iterator i;
	 
	for(i=list1.begin(); i != list1.end(); ++i) cout << *i << " ";
	cout << endl;
	

    return 0;
    
}