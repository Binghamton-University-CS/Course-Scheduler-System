#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

class CourseList {
  public:
    CourseList();
    bool add(Course course);
    bool remove(Course course);
    int find(Course course);
    bool checkCourseExistsByCRN(string CRN);
    Course getCourseByCRN(string CRN);
  private:
    Course* array;
    int size;
    int lastIndex;
};
