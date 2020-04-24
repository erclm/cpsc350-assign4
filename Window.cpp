#include <iostream>
#include "Window.h"

Window::Window(){
  currIdleTime = 0;
  totalIdleTime = 0;
  student = NULL;
}

Window::~Window(){
  delete student;
}

void Window::setCurrIdle(int t){
  currIdleTime = t;
}

void Window::setTotalIdle(int t){
  totalIdleTime = t;
}

int Window::getCurrIdle(){
  return currIdleTime;
}

int Window::getTotalIdle(){
  return totalIdleTime;
}

bool Window::isIdle(){
  return (student==NULL);
}

void Window::setStudent(Student* s){
  student = s;
}

Student* Window::getStudent(){
  return student;
}
