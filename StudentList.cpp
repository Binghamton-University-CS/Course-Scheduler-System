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
      currentQuantity = 0;
      array = new Student*[size];
      for (int i = 0; i < size; i++) {
            array[i] = nullptr;
      }
    }

StudentList::~StudentList() {
      delete[] array;
}
  
bool StudentList::add(string BNumber, string userID, string first, string last) {
      if (this->find(BNumber) != -1) {
        return false;
      }
      
      if (currentQuantity == size) {
        Student** temp = new Student*[size * 2];
        for (int i_ = 0; i_ < size * 2; i_++) {
          temp[i_] = nullptr;
        }
        for (int i = 0; i < currentQuantity - 1; i++) {
          temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        size *= 2;
      }
      currentQuantity++;
      array[currentQuantity - 1] = new Student(BNumber, userID, first, last);
      return true;
    }
  
//bool StudentList::remove(string BNumber) {
 //     int index = this->find(BNumber);
 //     if (index == -1) {
 //       return false;
 //     }
 //     for (int i = index; i < currentQuantity - 1; i++) {
 //       array[i] = array[i + 1];
 //     }
 //     return true;
 //   }
  
int StudentList::find(string BNumber) {
      for (int i = 0; i < currentQuantity; i++) {
        if ((*(array[i])).getBNumber() == BNumber) {
          return i;
        }
      }
      return -1;
    }

bool StudentList::checkExists(string BNumber) {
      for (int i = 0; i < currentQuantity; i++) {
            if ((*(array[i])).getBNumber() == BNumber) {
                  return true;
            }
      }
      return false;
}

Student* StudentList::getStudent(string BNumber) {
      for (int i = 0; i < currentQuantity; i++) {
            if ((*(array[i])).getBNumber() == BNumber) {
                  return array[i];
            }
      }
      //only here to remove warning
      return array[0];
}

void StudentList::removeAllCourse(string course, string BNumber) {
      for (int i = 0; i < currentQuantity; i++) {
            (*(array[i])).removeCourse(course)) {
      }
}
