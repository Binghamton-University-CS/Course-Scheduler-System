#include <string>

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef STRINGLIST_H
#define STRINGLIST_H
#include "StringList.h"
#endif

using namespace std;

Student::Student(string BNumber, string userID, string first, string last) {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
      courseList = new StringList();
    }
void Student::addCourse(Course course) {
      StringList.add(course);
    }
void Student::removeCourse(Course course) {
      StringList.remove(course);
    }
void Student::printCourses() {
      ;
    }
