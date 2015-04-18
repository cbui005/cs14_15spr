/*
Name: Calvin Bui
SID: 861064458
Date: 4/18
*/

#ifndef __LAB2_H__
#define __LAB2_H__
#include <iostream>
#include <forward_list>
using namespace std;

struct IntNode
{
    int data;
    IntNode *next;
    IntNode(int data):data(data),next(0) {}
};


template <class Type>
class List
{
    private:
        IntNode* head;
        IntNode* tail;
    public:
        List();
        ~List();
        void display() const;
        void push_front(int data);
        void push_back(int data);
        void elementSwap(int pos);
        forward_list<Type> listCopy(forward_list<Type>L, forward_list<Type>&P);
        void printLots(forward_list<Type> L, forward_list<int> P);
};

template <class Type>
List<Type>::List()
{
    head = '\0';
    tail = '\0';
}

template <class Type>
List<Type>::~List()
{
    if (head == '\0')
    {
        return;
    }
    for (IntNode* tmp = head; tmp != '\0'; tmp = tmp->next)
    {
        delete tmp;
    }
    head = '\0';
    tail = '\0';
}

template <class Type>
void List<Type>::display() const
{
    if (head == '\0')
    {
        return;
    }
    for (IntNode* tmp = head; tmp != '\0'; tmp = tmp->next)
    {
        if (tmp->next == '\0')
        {
            cout << tmp->data;
            return;
        }
        cout << tmp->data << ' ';
    }
}

template <class Type>
void List<Type>::push_front(int data)
{
    IntNode* tmp = new IntNode(data);
    if (head == '\0')
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;

    }
}

template <class Type>
void List<Type>::push_back(int data)
{
    IntNode* tmp = new IntNode(data);
    if (head == '\0')
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}

template <class Type>
void List<Type>::elementSwap(int pos)
{
   IntNode* tmp = head;
   int count = 0;
   for (tmp = head; count < pos; count++)
   {
       tmp = tmp->next;
   }
   cout << "tmp data: " << tmp->data << endl;
   cout << "next data: " << tmp->next->data << endl;
   IntNode* tmp2 = tmp->next;
   if (pos != 0)
   {
       IntNode* pred = head;
       int count = 1;
       for (pred = head; count < pos; count++)
       {
           pred = pred->next;
       }
       pred->next = tmp2;
   }
   tmp->next = tmp2->next;
   tmp2->next = tmp;
   if (pos == 0)
   {
       head = tmp2;
   }
}

template <class Type>
forward_list<Type>listCopy(forward_list<Type> L, forward_list<Type>&P)
{
    if (L.empty())
    {
        if (P.empty())
        {
            return P;
        }
        for (auto tmp = P.begin(); tmp != P.end(); tmp++)
        {
            P.pop_front();
        }
        return P;
    }
    if (P.empty())
    {
        for (auto tmp = L.begin(); tmp != L.end(); tmp++)
        {
            P.push_front(*tmp);
        }
        return P;
    }
    else
    {
        for (auto tmp = P.begin(); tmp != P.end(); tmp++)
        {
            P.pop_front();
        }
        for (auto tmp = L.begin(); tmp != L.end(); tmp++)
        {
            P.push_front(*tmp);
        }
        return P;
    }
}

template <class Type>
void printLots(forward_list<Type>L, forward_list<int> P)
{
    if (L.empty())
    {
        return;
    }
    int cntr = 0;
    int sz = 0;
    auto tmp = L.begin();
    for (auto tmp = L.begin(); tmp != L.end(); tmp++)
    {
        sz++;
    }
    P.sort(less<int>());
    for(auto pos = P.begin(); pos != P.end(); pos++)
    {
        if (*pos >= sz)
        {
            return;
        }
        while(cntr != *pos)
        {
            cntr++;
            tmp++;

        }
        if(cntr == *pos)
        {
            cout << *tmp << " ";
        }

    }
}


#endif
