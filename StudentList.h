#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

class StudentList {
  public:
    StudentList();
    bool add(Student student);
    bool remove(Student student);
    int find(Student student);
    bool checkStudentExistsByBNumber(string BNumber);
    Student getStudentByBNumber(string BNumber);
  private:
    Student* array;
    int size;
    int lastIndex;
};
