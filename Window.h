
#include <iostream>
#include "Student.h"
using namespace std;

class Window{
public:
  int currIdleTime;
  int totalIdleTime;
  Student *student;

  Window();
  ~Window();

  void setCurrIdle(int d);
  void setTotalIdle(int d);
  int getCurrIdle();
  int getTotalIdle();
  bool isIdle();
  void setStudent(Student* s);
  Student* getStudent();
};
