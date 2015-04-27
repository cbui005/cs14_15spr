/*
Name: Calvin Bui
SID: 861064458
Date: 4/27/15
*/
#ifndef __LAB_3_H__
#define __LAB_3_H__
#include <iostream>
#include <stack>
using namespace std;

template<typename T>
class TwoStackFixed
{
    private: 
        T* data;
        int size, maxtop, pos1, pos2;
    public:
        TwoStackFixed(int size, int maxtop)
        {
            data = new T[size];
            this->size = size;
            this->maxtop = maxtop;
            pos1 = 0;
            pos2 = size - 1;
        }
        ~TwoStackFixed()
        {
            delete [] data;
        }
        void pushStack1(T value)
        {
            if (pos1 > maxtop)
            {
                cout << "pos1 > maxtop error";
                return;
            }
            data[pos1] = value;
            pos1++;
            return;
        }
        void pushStack2(T value)
        {
            data[pos2] = value;
            pos2--;
        }
        T popStack1()
        {
            if (isEmptyStack1())
            {
                return 0;
            }
            pos1--;
            T tmp = data[pos1];
            data[pos1] = 0;
            return tmp;
        }
        T popStack2()
        {
            if (isEmptyStack2())
            {
                return 0;
            }
            pos2++;
            data[pos2] = 0;
        }
        bool isFullStack1()
        {
            if (pos1 == maxtop-1)
            {
                return true;
            }
            return false;
        }
        bool isFullStack2()
        {
            if (pos2 == maxtop)
            {
                return true;
            }
            return false;
        }
        bool isEmptyStack1()
        {
            if (pos1 == 0)
            {
                return true;
            }
            return false;
        }
        bool isEmptyStack2()
        {
            if (pos2 == size-1)
            {
                return true;
            }
            return false;
        }
};

template<typename T>
class TwoStackOptimal
{
    private:
        T* data;
        int size, pos1, pos2;
    public:
        TwoStackOptimal(int size)
        {
            data = new T[size];
            pos1 = 0;
            pos2 = size -1;
            this->size = size;
        }
        void pushFlexStack1(T value)
        {
            if (pos1 > pos2)
            {
                cout << "stack1 overflow";
                return;
            }
            data[pos1] = value;
            pos1++;
        }
        void pushFlexStack2(T value)
        {
            if (pos2 < pos1)
            {
                cout << "stack2 overflow";
                return;
            }
            data[pos2] = value;
            pos2--;
        }
        T popFlexStack1()
        {
            if (pos1 == 0)
            {
                cout << "stack1 empty";
                return -1;
            }
            pos1--;
            return data[pos1];
        }
        T popFlexStack2()
        {
            if (pos2 == size-1)
            {
                cout << "stack2 empty";
                return -1;
            }
            pos2++;
            return data[pos2];
        }
        bool isFullStack1()
        {
            if (pos1 >= pos2)
            {
                return true;
            }
            return false;
        }
        bool isFullStack2()
        {
            if (pos2 <= pos1)
            {
                return true;
            }
            return false;
        }
        bool isEmptyStack1()
        {
            if (pos1 == 0)
            {
                return true;
            }
            return false;
        }
        bool isEmptyStack2()
        {
            if (pos2 == size-1)
            {
                return true;
            }
            return false;
        }
};

template<typename T>
void showTowerStates(int n, stack<T>&A, stack<T>&B, stack<T>&C)
{
    static void*a = &A;
    static void*b = &B;
    if (n==0)
    {
        return;
    }
    showTowerStates(n-1,A,C,B);
    T test = A.top();
    C.push(A.top());
    A.pop();
    cout << "Moved " << test << " from peg ";
    if (&A == a)
    {
        cout << "A to ";
    }
    else if (&A == b)
    {
        cout << "B to ";
    }
    else
    {
        cout << "C to ";
    }
    if (&C == a)
    {
        cout << "A\n";
    }
    else if (&C == b)
    {
        cout << "B\n";
    }
    else
    {
        cout << "C\n";
    }
    
    showTowerStates(n-1,B,A,C);
}


#endif