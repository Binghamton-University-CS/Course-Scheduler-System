#include <string>
#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

using namespace std;

Student::Student(string BNumber = "", string userID = "", string first = "", string last = "") {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
      courseList = StringList();
    }

void Student::addCourse(string course) {
      courseList.add(course);
    }
void Student::removeCourse(string course) {
      courseList.remove(course);
    }
void Student::printSchedule() {
      cout << "Student: " << BNumber << ": " << first;
      courseList.printAll();
    }

int Student::getBNumber() {
      return BNumber;
}
