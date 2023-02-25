#include <string>

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef COURSELIST_H
#define COURSELIST_H
#include "CourseList.h"
#endif

using namespace std;

Student::Student(string BNumber, string userID, string first, string last) {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
      courseList = new CourseList();
    }
void Student::addCourse(Course course) {
      courseList.add(course);
    }
void Student::removeCourse(Course course) {
      courseList.remove(course);
    }
void Student::printCourses() {
      ;
    }
