#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef MICHAELLIST_H
#define MICHAELLIST_H
#include "MichaelList.h"
#endif

Course::Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
      studentList = new MichaelList<Student>();
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
}
