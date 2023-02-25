#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentList.h"
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
  
bool StudentList::remove(Student student) {
      int index = this->find(student);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
  
int StudentList::find(Student student) {
      for (int i = 0; i < lastIndex; i++) {
        if (student == array[i]) {
          return i;
        }
      }
      return -1;
    }
