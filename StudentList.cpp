#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentList.h"
#endif

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

StudentList::StudentList() {
      size = 1;
      array = new Student[size];
    }

StudentList::~StudentList() {
      delete[] array;
}
  
bool StudentList::add(Student student) {
      if (this->find(student.getBNumber()) != -1) {
        return false;
      }
      
      if (lastIndex == size - 1) {
        Student* temp = new Student[size * 2];
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
        if (BNumber == array[i].getBNumber()) {
          return i;
        }
      }
      return -1;
    }

bool StudentList::checkExists(string BNumber) {
      for (int i = 0; i < lastIndex; i++) {
            if (array[i].getBNumber() == BNumber) {
                  return true;
            }
      }
      return false;
}

Student* StudentList::getStudent(string BNumber) {
      for (int i = 0; i < lastIndex; i++) {
            if (array[i].getBNumber() == BNumber) {
                  return &array[i];
            }
      }
      //only here to remove warning
      return &array[0];
}
