#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif

class StudentList {
  public:
    StudentList() {
      array = new Student[size];
    }
  
    bool add(Student student) {
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
  
    bool remove(Student student) {
      int index = this->find(student);
      if (index == -1) {
        return false;
      }
      for (int i = index; i < lastIndex - 1; i++) {
        array[i] = array[i + 1];
      }
      return true;
    }
  
    int find(Student student) {
      for (int i = 0; i < lastIndex; i++) {
        if (student == array[i]) {
          return i;
        }
      }
      return -1;
    }
  
  private:
    Student* array;
    int size = 100;
    int lastIndex;
};
