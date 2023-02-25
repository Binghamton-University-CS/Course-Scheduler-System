#include <string>

//#ifndef STUDENT_H
//#define STUDENT_H
//#include "Student.h"
//#endif

//#ifndef STUDENTLIST_H
//#define STUDENTLIST_H
//#include "StudentList.h"
//#endif

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

using namespace std;

Course::Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
      studentList = new StudentList();
    }
string Course::addStudent(Student student) {
      studentList.add(student);
    }
string Course::dropStudent(Student student) {
      studentList.remove(student);
    }
void Course::printStudents() {
      ;
}
