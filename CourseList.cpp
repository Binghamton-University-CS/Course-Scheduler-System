#ifndef COURSELIST_H
#define COURSELIST_H
#include "CourseList.h"
#endif

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

CourseList::CourseList() {
      size = 1;
      currentQuantity = 0;
      array = new Course*[size];
      for (int i = 0; i < size; i++) {
            array[i] = nullptr;
      }
}

CourseList::~CourseList() {
      delete[] array;
}

bool CourseList::add(Course course) {
      if (this->find(course.getCRN()) != -1) {
        return false;
      }
      
      if (currentQuantity == size) {
        Course* temp = new Course*[size * 2];
        for (int i_ = 0; i_ < size * 2; i_++) {
              temp[i_] = nullptr;
        }
        for (int i = 0; i < currentQuantity; i++) {
          temp[i] = array[i];
        }
        delete array;
        array = temp;
        size *= 2;
      }
      currentQuantity++;
      *array[currentQuantity - 1] = course;
      return true;
    }

bool CourseList::remove(string CRN) {
      int index = this->find(CRN);
      if (index == -1) {
        return false;
      }
      delete array[index];
      for (int i = index; i < currentQuantity - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
int CourseList::find(string CRN) {
      for (int i = 0; i < currentQuantity; i++) {
        if (CRN == (*array[i]).getCRN()) {
          return i;
        }
      }
      return -1;
    }

bool CourseList::checkExists(string CRN) {
      for (int i = 0; i < currentQuantity; i++) {
            if ((*array[i]).getCRN() == CRN) {
                  return true;
            }
      }
      return false;
}

Course* CourseList::getCourse(string CRN) {
      for (int i = 0; i < currentQuantity; i++) {
            if ((*array[i]).getCRN() == CRN) {
                  return array[i];
            }
      }
      //only here to remove warning
      return array[0];
}
