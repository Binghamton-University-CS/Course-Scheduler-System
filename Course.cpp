#include <string>
#ifndef MICHAELLIST
#define MICHAELLIST
#include "MichaelList.cpp"
#endif

#ifndef STUDENT
#define STUDENT
#include "Student.cpp"
#endif

class Course {
  public:
    Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
      studentList = new MichaelList<string>();
    }
    addStudent(Student student) {
      studentList.add(student);
    }
    dropStudent(Student student) {
      studentList.remove(student);
    }
  private:
    string CRN;
    string department;
    string number;
    string name;
    MichaelList<Student> studentList;
};
