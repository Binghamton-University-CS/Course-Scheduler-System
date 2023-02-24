#ifndef STUDENT
#define STUDENT
#include "Student.cpp"
#endif

class StudentList {
  public:
    StudentList() {
      array = new Student[size];
    }
    add(Student student) {
      if (lastIndex == size - 1) {
        T* temp = new T[size * 2];
        for (int i = 0; i < size; i++) {
          temp[i] = array[i];
        }
        delete array;
        array = temp;
        size *= 2;
      }
      lastIndex++;
      array[lastIndex] = student;
    }
    remove(Student student) {
      
    }
  private:
    Student* array;
    int size = 100;
    int lastIndex;
};
