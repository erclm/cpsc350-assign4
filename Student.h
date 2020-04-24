#include <iostream>
using namespace std;

class Student
{
public:
  Student();
  Student(int d);
  ~Student();
  int waitTime;
  int timeTaken;
  int getTimeTaken();
  int getWaitTime();
  void setWait(int d);
  void decrementTime();
};
