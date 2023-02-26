#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

class CourseList {
  public:
    CourseList();
    bool add(Course course);
    bool remove(string CRN);
    int find(string CRN);
    bool checkExists(string CRN);
  private:
    Course* array;
    int size;
    int lastIndex;
};
