#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentList.h"
#endif

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

StudentList::StudentList() {
      array = new Student[size];
    }
  
bool StudentList::add(Student student) {
      if (this->find(student) != -1) {
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
      array[lastIndex] = student;
      return true;
    }
  
bool StudentList::remove(string BNumber) {
      int index = this->find(BNumber);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
  
int StudentList::find(string BNumber) {
      for (int i = 0; i < lastIndex; i++) {
        if (student == array[i]) {
          return i;
        }
      }
      return -1;
    }

bool StudentList::checkExists(string BNumber) {
      for (int i = 0; i < lastIndex; i++) {
            if (array[i].BNumber == BNumber) {
                  return true;
            }
      }
      return false;
}

//Student StudentList::getStudentByBNumber(string BNumber) {
//      for (int i = 0; i < lastIndex; i++) {
//            if (array[i].BNumber == BNumber) {
//                  return array[i]
//            }
//      }
//}
