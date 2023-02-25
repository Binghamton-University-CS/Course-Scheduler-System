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

class Student {
  public:
    Student(string BNumber, string userID, string first, string last);
    void addCourse(Course course);
    void removeCourse(Course course);
    void printCourses();
  private:
    string BNumber;
    string userID;
    string first;
    string last; 
    CourseList courseList;
};
