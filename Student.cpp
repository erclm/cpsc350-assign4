#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
  waitTime = 0;
  timeTaken = 0;
}

Student::Student(int t){
  waitTime = 0;
  timeTaken = t;
}

Student::~Student(){

}

int Student::getTimeTaken(){
  return timeTaken;
}

int Student::getWaitTime(){
  return waitTime;
}

void Student::setWait(int t){
  waitTime = t;
}
