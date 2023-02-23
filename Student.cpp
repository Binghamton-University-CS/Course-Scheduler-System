#include <string>

#ifndef COURSE
#define COURSE
#include "Course.cpp"
#endif

#ifndef MICHAELLIST
#define MICHAELLIST
#include "MichaelList.cpp"
#endif

class Student {
  public:
    Student(string BNumber, string userID, string first, string last) {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
      courseList = new MichaelList<Course>();
    }
    void addCourse(Course course) {
      courseList.add(course);
    }
    void removeCourse(Course course) {
      courseList.remove(course);
    }
    void printCourses() {
      ;
    }
  private:
    string BNumber;
    string userID;
    string first;
    string last; 
    MichaelList<Course> courseList;
};
