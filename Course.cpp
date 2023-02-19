#include <string>
#include "MichaelList.cpp"

class Course {
  public:
    Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
      BNumbers = new MichaelList<string>();
    }
    addStudent(string BNumber) {
      studentList.add(BNumber);
    }
    dropStudent(string BNumber) {
      studentList.remove(BNumber);
    }
  private:
    string CRN;
    string department;
    string number;
    string name;
    MichaelList<string> studentList;
};
