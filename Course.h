#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef MICHAELLIST_H
#define MICHAELLIST_H
#include "MichaelList.h"
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
    MichaelList<Student> studentList;
};
