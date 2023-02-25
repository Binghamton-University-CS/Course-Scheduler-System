#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef COURSELIST_H
#define COURSELIST_H
#include "CourseList.h"
#endif

CourseList::CourseList() {
      array = new Course[size];
}

bool CourseList::add(Course* course) {
      if (this->find(*course) != -1) {
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
      array[lastIndex] = *course;
      true;
    }

bool CourseList::remove(Course* course) {
      int index = this->find(*course);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
int CourseList::find(Course* course) {
      for (int i = 0; i < lastIndex; i++) {
        if (*course == array[i]) {
          return i;
        }
      }
      return -1;
    }
