#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

class StudentList {
  public:
    StudentList();
    ~StudentList();
    bool add(string BNumber, string userID, string first, string last);
    //bool remove(string BNumber);
    int find(string BNumber);
    bool checkExists(string BNumber);
    Student* getStudent(string BNumber);
    void removeAllCourse(string course);
  private:
    int size;
    int currentQuantity;
    Student** array;
};
