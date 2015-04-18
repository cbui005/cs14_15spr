#include "MyList.h"
#include <iostream>
using namespace std;

int main()
{
    
    string test = "hello";
    MyList list1(test);
    list1.print();
    cout << endl;
    list1.reverse();
    list1.print();
    cout << endl;
    
    list1.push_front('5');
    list1.print();
    cout << endl;
    list1.push_back('z');
    list1.print();
    cout << endl;
    list1.pop_front();
    list1.print();
    cout << endl;
    list1.pop_back();
    list1.print();
    cout << endl;
    list1.pop_back();
    list1.print();
    cout << endl;
   
    list1.insert_at_position(3,'z');
    list1.print();
    cout << endl;
    list1.push_front('a');
    list1.print();
    cout << endl;
    list1.push_front('5');
    list1.print();
    cout << endl;
    list1.push_front('6');
    list1.print();
    cout << endl;
    list1.push_front('7');
    list1.print();
    cout << endl;
    list1.reverse();
    list1.print();
    cout << endl;
    MyList list2("test2");
    list2.print();
    cout << endl;
    list2.swap(0,2);
    list2.print();
    cout << endl;
    list2.reverse();
    list2.print();
    cout << endl;
    list2.swap(1,4);
    list2.print();
    cout << endl;
    list2.insert_at_position(0,'a');
    list2.print();
    cout << endl;
    list2.reverse();
    list2.print();
    cout << endl;
    cout << list2.find('a');
    cout << "list1 : ";
    list1.print();
    cout << endl;
    cout << "list2: ";
    list2.print();
    cout << endl;
    list2 = list1;
    list2.print();
    cout << endl;
    

    
    
    //MyList list3("hello world");
    //list3.print();

    //MyList list2(list1);
    //list2.print();
    
    
    
   // MyList list3("te");
    //list3.print();
    /*
    char tmp = 'P';
    list3.push_front(tmp);
    cout << endl;
    list3.print();
    */
    return 0;
}