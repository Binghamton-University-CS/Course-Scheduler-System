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
      for (int i = 0; i < currentQuantity; i++) {
            delete array[i];
      }
      delete[] array;
}

bool CourseList::add(string CRN, string department, string number, string name) {
      if (this->find(CRN) != -1) {
        return false;
      }
      
      if (currentQuantity == size) {
        Course** temp = new Course*[size * 2];
        for (int i_ = 0; i_ < size * 2; i_++) {
              temp[i_] = nullptr;
        }
        for (int i = 0; i < currentQuantity; i++) {
          temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        size *= 2;
      }
      currentQuantity++;
      array[currentQuantity - 1] = new Course(CRN, department, number, name);
      return true;
    }

bool CourseList::remove(string CRN) {
      int index = this->find(CRN);
      if (index == -1) {
        return false;
      }
      delete array[index];
      if (index == currentQuantity - 1) {
            return true;
      }
      for (int i = index; i < currentQuantity - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
int CourseList::find(string CRN) {
      for (int i = 0; i < currentQuantity; i++) {
        if (CRN == (*(array[i])).getCRN()) {
          return i;
        }
      }
      return -1;
    }

bool CourseList::checkExists(string CRN) {
      for (int i = 0; i < currentQuantity; i++) {
            if ((*(array[i])).getCRN() == CRN) {
                  return true;
            }
      }
      return false;
}

Course* CourseList::getCourse(string CRN) {
      for (int i = 0; i < currentQuantity; i++) {
            if ((*(array[i])).getCRN() == CRN) {
                  return array[i];
            }
      }
      //only here to remove warning
      return array[0];
}
