#include <string>
#include <iostream>

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

using namespace std;

Course::Course() {}

Course::Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
      studentList = StringList();
    }

string Course::addStudent(string student) {
      studentList.add(student);
      return "";
    }
string Course::dropStudent(string student) {
      studentList.remove(student);
      return "";
    }
void Course::printRoster() {
      cout << "CRN: " << CRN << endl;
      cout << "Students: " << studentList.getCurrentQuantity() << endl;
      studentList.printAll();
}

string Course::getCRN() {
      return CRN;
}

string Course::getString() {
      return CRN + " " + department + " " + number + " " name;
}
