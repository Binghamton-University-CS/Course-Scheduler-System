#include <string>

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef MICHAELLIST_H
#define MICHAELLIST_H
#include "MichaelList.h"
#endif

Student::Student(string BNumber, string userID, string first, string last) {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
      courseList = new MichaelList<Course>();
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
