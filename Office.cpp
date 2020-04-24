#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#include "GenQueue.h"
#include "Window.h"

using namespace std;

int main(int argc, char *argv[]){
  GenQueue<Student*> queue;
  ifstream input(argv[1]);
  int numStudents = 0;
  int numWindows = 0;

  //math vars
  int totalWait = 0;
  int totalIdle = 0;
  float meanWait = 0;
  float meanIdle = 0;
  int medianWait = 0;
  int maxWait = 0;
  int maxIdle = 0;
  int numWinIdle = 0;
  int numStudWait = 0;

  //tracker
  int time = 0;
  string line = "";
  GenQueue<int> waitTimes;

  getline(input,line);
  numWindows = stoi(line);
  Window** windows = new Window*[numWindows];
  for(int i = 0; i<numWindows; i++){
    Window* temp = new Window();
    windows[i] = temp;
  }

  while(getline(input,line)){
    time++;
    getline(input,line);
    numStudents = numStudents + stoi(line);
    int tempStudents = stoi(line);
    Student *s;

    for(int i = 1; i<=tempStudents; i++){
      getline(input,line);
      s = new Student(stoi(line));
      queue.insert(s);
    }

    for(int i = 0; i<numWindows; i++){
      if(!queue.isEmpty()){
        windows[i]->setStudent(queue.remove());
      }else{
        break;
      }
    }

    int currWait = 0;
    if(tempStudents<numWindows){
      for(int i = 1; i<=tempStudents; i++){
        waitTimes.insert(0);
      }
    }else{
      for(int i = 1; i<=numWindows; i++){
        waitTimes.insert(0);
      }
    }

    while(!queue.isEmpty()){
      for(int i = 0; i<numWindows; i++){
        if(windows[i]->getStudent()->getTimeTaken() == 0){
          if(!queue.isEmpty()){
            windows[i]->setStudent(queue.remove());
            windows[i]->getStudent()->timeTaken--;
            totalWait = totalWait + currWait;
            waitTimes.insert(currWait);
            if(currWait>=10){
              numStudWait++;
            }
          }else{
            windows[i]->setStudent(NULL);
          }
        }else{
          windows[i]->getStudent()->timeTaken--;
        }
      }
      currWait++;
    }
    if(maxWait<currWait-1){
      maxWait = currWait-1;
    }

    int timetakentemp = 0;

    for(int i = 0; i<numWindows; i++){
      if(!windows[i]->isIdle()){
        if(timetakentemp<windows[i]->getStudent()->getTimeTaken()){
          timetakentemp = windows[i]->getStudent()->getTimeTaken();
        }
      }
    }


    for(int i = 0; i<numWindows; i++){
      if(!windows[i]->isIdle()){
        windows[i]->setTotalIdle(windows[i]->getTotalIdle() + (timetakentemp-windows[i]->getStudent()->getTimeTaken()));
        windows[i]->setCurrIdle(timetakentemp-windows[i]->getStudent()->getTimeTaken());
      }else if(queue.isEmpty()){
        windows[i]->setTotalIdle(windows[i]->getTotalIdle() + timetakentemp + 1);
        windows[i]->setCurrIdle(timetakentemp + 1);//if empty, its time taken + 1
      }else{
        windows[i]->setTotalIdle(windows[i]->getTotalIdle() + timetakentemp);
        windows[i]->setCurrIdle(timetakentemp);
      }
    }

    //set max idle time
    for(int i = 0; i<numWindows; i++){
      if(maxIdle < windows[i]->getCurrIdle()){
        maxIdle = windows[i]->getCurrIdle();
      }
    }
  }

  //calculate mean wait time
  meanWait = (totalWait*1.0)/numStudents;

  //calculate number of windows idle for 5
  for(int i = 0; i<numWindows; i++){
    totalIdle = totalIdle + windows[i]->getTotalIdle();
    if(5 <= windows[i]->getTotalIdle()){
      numWinIdle++;
    }
  }

  //calculate mean idle time
  meanIdle = totalIdle/(numWindows*time*1.0);


  int array[numStudents];
  for(int i = 0; i<numStudents; i++){
    array[i] = waitTimes.remove();
  }
  sort(array,array+numStudents);
  if(numStudents%2 == 0){
    medianWait = (array[numStudents/2] + array[(numStudents/2) + 1])/2;
  }else{
    medianWait = array[(numStudents/2) + 1];
  }

  cout<<"Mean student wait time: "<<meanWait<<endl;
  cout<<"Median student wait time: "<< medianWait<<endl;
  cout<<"Longest student wait time: "<< maxWait<<endl;
  cout<<"Number of students waiting over 10: "<<numStudWait<<endl;
  cout<<"Mean window idle time: "<< meanIdle<<endl;
  cout<<"Longest window idle time: "<< maxIdle<<endl;
  cout<<"Number of windows idle over 5: "<<numWinIdle<<endl;

  return 0;
}
