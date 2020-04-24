#include <iostream>
using namespace std;

class Student
{
public:
  Student();
  Student(int t);
  ~Student();
  int waitTime;
  int timeTaken;
  int getTimeTaken();
  int getWaitTime();
  void setWait(int t);
};
