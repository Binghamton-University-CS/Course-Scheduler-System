#ifndef COURSE_H
#define COURSE_H
//#include "Course.h"
class Course;
#endif

class CourseList {
  public:
    CourseList();
    bool add(Course course);
    bool remove(Course course);
    int find(Course course);
  private:
    Course* array;
    int size;
    int lastIndex;
};
