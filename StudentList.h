#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

class StudentList {
  public:
    StudentList();
    ~StudentList();
    bool add(Student student);
    bool remove(string BNumber);
    int find(string BNumber);
    bool checkExists(string BNumber);
    Student* getStudent(string BNumber);
  private:
    Student* array;
    int size;
    int lastIndex;
};
