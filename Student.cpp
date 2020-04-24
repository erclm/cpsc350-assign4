#include "Student.h"
#include <iostream>

using namespace std;

Student::Student(){
  waitTime = 0;
  timeTaken = 0;
}

Student::Student(int d){
  waitTime = 0;
  timeTaken = d;
}

Student::~Student(){

}

int Student::getTimeTaken(){
  return timeTaken;
}

int Student::getWaitTime(){
  return waitTime;
}

void Student::setWait(int d){
  waitTime = d;
}

void Student::decrementTime(){
  timeTaken--;
}
