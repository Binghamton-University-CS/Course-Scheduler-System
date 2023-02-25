#include <string>

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef MICHAELLIST_H
#define MICHAELLIST_H
#include "MichaelList.h"
#endif

//using namespace std;

class Student {
  public:
    Student(std::string BNumber, std::string userID, std::string first, std::string last);
    void addCourse(Course course);
    void removeCourse(Course course);
    void printCourses();
  private:
    std::string BNumber;
    std::string userID;
    std::string first;
    std::string last; 
    MichaelList<Course> courseList;
};
