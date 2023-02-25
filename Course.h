#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif

#ifndef STUDENTLIST
#define STUDENTLIST
#include "StudentList.h"
#endif

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
