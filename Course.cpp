#include <string>

class Course {
  public:
    Course(string CRN, string department, string number, string name) {
      this->CRN = CRN;
      this->department = department;
      this->number = number;
      this->name = name;
    }
  private:
    string CRN;
    string department;
    string number;
    string name;
};
