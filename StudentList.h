#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif

class StudentList {
  public:
    StudentList();
    bool add(Student student)'
    bool remove(Student student);
    int find(Student student);
  
  private:
    Student* array;
    int size;
    int lastIndex;
};
