#ifndef __LAB2_H__
#define __LAB2_H__
#include <iostream>
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
        void push_front(int value);
        void push_back(int value);
        void elementSwap(List<Type>lst, int pos);
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
void List<Type>::push_front(int value)
{
    IntNode* tmp = new IntNode(value);
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
void List<Type>::push_back(int value)
{
    IntNode* tmp = new IntNode(value);
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
void List<Type>::elementSwap(List<Type>lst, int pos)
{
    
    int count = 0;
    IntNode* tmp;
    
    for (tmp = lst.head; count < pos; tmp = tmp->next)
    {
        count++;
    }
    
    cout << "tmp:  " << tmp->data << endl;
    IntNode* tmp2 = tmp;
    cout << "tmp2: " << tmp2->data << endl;

    
}
#endif
