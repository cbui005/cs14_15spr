#ifndef __MYLIST_H__
#define __MYLIST_H__
#include <iostream>
#include <string.h>
using namespace std;


struct Node
{
    char value;
    Node* next;
    Node* pred;
    Node(char value):value(value) {}
};

class MyList
{
    private:
        Node* head;
    public:
        MyList();
        MyList(const MyList& str);
        MyList(const string& str);
        MyList(const char* str);
        ~MyList();
        void push_front(char value);
        void push_back(char value);
        void pop_front();
        void pop_back();
        void swap(int i, int j);
        void insert_at_position(int i, char value);
        void reverse();
        int size() const;
        void print() const;
        int find(char value) const;
        int find(MyList& query_str) const;
        MyList& operator=(const MyList& str);
        char& operator[](const int i);
        MyList& operator+(const MyList& str);
};

//Default constructor.
MyList::MyList()
{
    head = '\0';
    head->next = '\0';
    head->pred = '\0';
}

//Constructs a list from a passed-in MyList object, e.g., MyList list1(list2);
MyList::MyList(const MyList& str)
{
    head = str.head;
}


//Constructs a list from a passed-in string object,
MyList::MyList(const string& str)
{
    if (str.length() == 0)
    {
        head = '\0';
        return;
    }
    Node* start = new Node(str.at(0));
    head = start;
    Node* tmp2 = head;
    for (unsigned int i = 1; i < str.length(); i++)
    {
        Node* tmp = new Node(str.at(i));
        tmp2->next = tmp;
        (tmp2->next)->pred = tmp2;
        tmp2 = tmp2->next;
    }
    tmp2->next = head;
    head->pred = tmp2;
}

//Constructs a list from a passed-in string literal, e.g., MyList list1("Hello")
MyList::MyList(const char* str)
{
    if (*str == '\0')
    {
        head = '\0';
        return;
    }
    Node* start = new Node(*str);
    head = start;
    Node* tmp2 = head;
   for (int i = 1; (*(str+i)) != '\0'; i++)
   {
       Node* tmp = new Node(*(str+i));
       tmp2->next = tmp;
       (tmp2->next)->pred = tmp2;
       tmp2 = tmp2->next;
   }
   tmp2->next = head;
   head->pred = tmp2;
}

//destructor
MyList::~MyList()
{
    if (head == '\0')
    {
        return;
    }
    Node* tmp = head;
    delete tmp;
    for (tmp = head->next; tmp != head; tmp = tmp->next)
    {
        delete tmp;
    }
    head = '\0';
}

//insert value at the front of the list
void MyList::push_front(char value)
{
    Node* tmp = new Node(value);
    Node* last = head->pred;
    if (head == '\0')
    {
        head = tmp;
        head->next = '\0';
        head->pred = '\0';
        return;
    }
    else
    {
        
        tmp->next = head;
        head->pred=  tmp;
        head = tmp;
        head->pred = last;
        last->next = head;
    }
}

//inserts value at the back of the list
void MyList::push_back(char value)
{
    Node* tmp = new Node(value);
    if (head == '\0')
    {
        head = tmp;
        head->next = '\0';
        head->pred = '\0';
        return;
    }
    else
    {
        (head->pred)->next = tmp;
        tmp->pred = head->pred;
        head->pred = tmp;
        tmp->next = head;
        
    }
}

// removes the front item from the list
void MyList::pop_front()
{
    if (head == '\0')
    {
        return;
    }
    (head->pred)->next = head->next;
    (head->next)->pred = head->pred;
    head = head->next;
    
}

//removes the last item from the list
void MyList::pop_back()
{
    if (head == '\0')
    {
        return;
    }
    ((head->pred)->pred)->next = head;
    head->pred = (head->pred)->pred;
}

//swaps the value of the node at position i in the list with value of the node 
//at position j. Be sure you handle out-of-range calls.
void MyList::swap(int i, int j)
{
    int sz = size()-1;
    if ((i > sz) || (j > sz))
    {
        cout << "out of range" << endl;
        return;
    }
    int count = 0;
    Node* tmp;
    for (tmp = head; count < i; count++)
    {
        tmp = tmp->next;
    }
    count = 0;
    Node* tmp2;
    for (tmp2 = head; count < j; count++)
    {
        tmp2 = tmp2->next;
    }
    Node* tmp3 = tmp->pred;
    Node* tmp4 = tmp->next;
    Node* tail = head->pred;
    Node* tmp5 = tmp2->pred;
    int test = i - j;
    if (test < 0)
    {
        test = test * -1;
    }
    if (((i == 0) || (j == 0)) && ((tmp == tail) || (tmp2 == tail)))
    {
        test = -1;
    }

    
    if ((test != 1) && (test != -1))
    {
        tmp->next = tmp2->next;
        tmp2->next->pred = tmp;
        tmp->pred = tmp2->pred;
        tmp2->pred->next = tmp;
        tmp2->pred = tmp3;
        tmp3->next = tmp2;
        tmp2->next = tmp4;
        tmp4->pred = tmp2;
    }
    else if (test == 1)
    {
        tmp->next = tmp2->next;
        tmp2->next->pred = tmp;
        tmp2->next = tmp;
        tmp->pred = tmp2;
        tmp2->pred = tmp3;
        tmp3->next = tmp2;
        
    }
    else if (test == -1)
    {
        tmp->next = tmp2;
        tmp2->pred = tmp;
        tmp2->next = tmp4;
        tmp4->pred = tmp2;
        tmp5->next = tmp;
        tmp->pred = tmp5;
    }
    if (i == 0)
    {
        head = tmp2;
    }
    else if (j == 0)
    {
        head = tmp;
    }
}

//inserts a node with value at position i in the list
void MyList::insert_at_position(int i, char value)
{
    int sz = size()-1;
    if (i > sz)
    {
        cout << "out of range" << endl;
        return;
    }
    int count = 0;
    Node* tmp = head;
    for (tmp = head; count < i; count++)
    {
        tmp = tmp->next;
    }
    Node* tmp2 = new Node(value);
    (tmp->pred)->next = tmp2;
    tmp2->pred = tmp->pred;
    tmp2->next = tmp;
    tmp->pred = tmp2;
    if (i == 0)
    {
        head = tmp2;
    }
}

//reverses the items in the list
void MyList::reverse()
{
    if (head == '\0')
    {
        return;
    }
    int sz = size()-1;
    if (size()%2 == 0)
    {
        for (int i = 0; i < size()/2; i++)
        {
            swap(i,sz-i);
        }
    }
    else if (size()%2 == 1)
    {
        for (int i = 0; i < (size()/2); i++)
        {
            swap(i,sz-i);
        }
    }
}


void MyList::print() const
{
    if (head == '\0')
    {
        return;
    }
    Node* tmp = head;
    cout << tmp->value << ' ';
    for (Node* tmp = head->next; tmp != head; tmp = tmp->next)
    {
        cout << tmp->value << ' ';
    }
}

//returns the number of nodes in the list
int MyList::size() const
{
    int count = 0;
    if (head == '\0')
    {
        return 0;
    }
    Node* tmp = 0;
    count++;
    for (tmp = head->next; tmp != head; tmp = tmp->next)
    {
        count++;
    }
    return count;
}

//finds the position of the first occurrence of a character value in the list and returns
//that position. If that character is not in the list, the function
//returns -1
int MyList::find(char value)const
{
    if (head == '\0')
    {
        return -1;
    }
    int pos = 0;
    Node* tmp = head;
    if (head->value == value)
    {
        return 0;
    }
    pos++;
    for (tmp = head->next; tmp != head; tmp = tmp->next)
    {
        if (tmp->value == value)
        {
            return pos;
        }
        pos++;
    }
    return -1;
}

//finds the position of the first occurrence of the MyList query_str in the 
//list and returns that position. If query_str is not in the list, the 
//function returns -1
int MyList::find(MyList& query_str)const
{
    /*
    if (head == '\0')
    {
        return -1;
    }
    int start = 0;
    int sz = query_str.size();
    Node* tmp = query_str.head;
    start = find(tmp->value);
    cout << "start: " << start << endl;
    if (start == -1)
    {
        return -1;
    }
    for (Node* tmp2 = )
    */
    return -1;
}

//assignment overloading
MyList&MyList::operator=(const MyList& str)
{
    head = str.head;
    return *this;

    //delete[] head;
    //head = str.head;
}

char&MyList::operator[](const int i)
{
    int count = 0;
    Node* tmp;
    for (tmp = head; count < i; tmp = tmp->next)
    {
        count++;
    }
    return tmp->value;
}


//concatenates two lists together
MyList&MyList::operator+(const MyList& str)
{
    Node*tmp = head;
    do
    {
        tmp = tmp->next;
    }
    while(tmp != head);
    tmp = tmp->pred;
    Node* tmp2 = str.head;
    tmp->next = tmp2;
    tmp2->pred = tmp;
    do
    {
        tmp2 = tmp2->next;
    }
    while (tmp2 != str.head);
    tmp2 = tmp2->pred;
    tmp2->next = head;
    head->pred = tmp2;
    return *this;
}



#endif
