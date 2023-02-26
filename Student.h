#include <string>

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

using namespace std;

class Student {
  public:
    Student(string BNumber, string userID, string first, string last);
    ~Student();
    void addCourse(string course);
    void removeCourse(string course);
    void printSchedule();
    string getBNumber();
  private:
    string BNumber;
    string userID;
    string first;
    string last; 
    StringList courseList;
};
