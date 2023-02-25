#include <string>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentList.h"
#endif

using namespace std;

class Course {
  public:
    Course(string CRN, string department, string number, string name);
    string addStudent(Student student);
    string dropStudent(Student student);
    void printStudents();
  private:
    string CRN;
    string department;
    string number;
    string name;
    StudentList studentList;
};
