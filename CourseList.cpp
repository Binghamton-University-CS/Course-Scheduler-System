#ifndef COURSE
#define COURSE
#include "Course.h"
#endif

class CourseList {
  public:
    CourseList() {
      array = new Course[size];
    }
    bool add(Course course) {
      if (this->find(course) != -1) {
        return false;
      }
      
      if (lastIndex == size - 1) {
        T* temp = new T[size * 2];
        for (int i = 0; i < lastIndex; i++) {
          temp[i] = array[i];
        }
        delete array;
        array = temp;
        size *= 2;
      }
      lastIndex++;
      array[lastIndex] = course;
      true;
    }
    bool remove(Course course) {
      int index = this->find(course);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
    int find(Course course) {
      for (int i = 0; i < lastIndex; i++) {
        if (course == array[i]) {
          return i;
        }
      }
      return -1;
    }
    
  private:
    Course* array;
    int size = 100;
    int lastIndex;
};
