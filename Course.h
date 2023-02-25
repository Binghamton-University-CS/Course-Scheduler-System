#include <string>

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

using namespace std;

class Course {
  public:
    Course(string CRN, string department, string number, string name);
    string addStudent(string student);
    string dropStudent(string student);
    void printStudents();
  private:
    string CRN;
    string department;
    string number;
    string name;
    StringList studentList;
};
