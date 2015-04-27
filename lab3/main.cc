/*
Name: Calvin Bui
SID: 861064458
Date: 4/27/15
*/
#include "lab3.h"

#include <iostream>
using namespace std;

int main() {
    stack<int> testTower;
    testTower.push(5);
    testTower.push(4);
    testTower.push(3);
    testTower.push(2);
    testTower.push(1);
    stack<int> testTower2;
    stack<int> testTower3;
    showTowerStates(5,testTower,testTower2,testTower3);
    while (!testTower3.empty())
    {
        cout << testTower3.top() << ' ';
        testTower3.pop();
    }
    cout << endl;
    /*
  TwoStackFixed<int> test(11, 6);
  test.pushStack1(4);
  test.pushStack1(70);

  test.pushStack2(10);
  test.pushStack2(2);


  while (!test.isEmptyStack1()) 
  {
    cout << test.popStack1() << ' ';
  }
  cout << endl;

  test.popStack1();

  test.pushStack2(5);
  TwoStackOptimal<char> tmp2(5);
  tmp2.pushFlexStack1('z');
  tmp2.pushFlexStack1('1');
  tmp2.pushFlexStack1('2');
  tmp2.pushFlexStack2('x');
  tmp2.pushFlexStack2('y');
  tmp2.pushFlexStack2('z');
  if (tmp2.isFullStack1())
  {
      cout << "full";
  }
  else
  {
      cout << "not full";
  }
  tmp2.popFlexStack1();
  tmp2.popFlexStack2();
  */
  return 0;
}