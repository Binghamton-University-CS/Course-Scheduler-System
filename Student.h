#include <string>

#ifndef COURSE
#define COURSE
#include "Course.h"
#endif

#ifndef COURSELIST
#define COURSELIST
#include "CourseList.h"
#endif

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
