#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentList.h"
#endif

class Course {
  public:
    Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
      studentList = new StudentList();
    }
    string addStudent(Student student) {
      studentList.add(student);
    }
    string dropStudent(Student student) {
      studentList.remove(student);
    }
    void printStudents() {
      ;
    }
  private:
    string CRN;
    string department;
    string number;
    string name;
    StudentList studentList;
};
