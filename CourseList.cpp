#ifndef COURSELIST_H
#define COURSELIST_H
#include "CourseList.h"
#endif

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

CourseList::CourseList() {
      array = new Course[size];
}

bool CourseList::add(Course course) {
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
      return true;
    }

bool CourseList::remove(string CRN) {
      int index = this->find(CRN);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
    
int CourseList::find(string CRN) {
      for (int i = 0; i < lastIndex; i++) {
        if (CRN == array[i].CRN) {
          return i;
        }
      }
      return -1;
    }

bool CourseList::checkExists(string CRN) {
      for (int i = 0; i < lastIndex; i++) {
            if (array[i].CRN == CRN) {
                  return true;
            }
      }
      return false;
}

//Course CourseList::getCourseByCRN(string CRN) {
//      for (int i = 0; i < lastIndex; i++) {
//            if (array[i].CRN == CRN) {
//                  return array[i]
//            }
//      }
//}
