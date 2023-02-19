#include <string>

class Course {
  public:
    Course(string CRN, string department, string number, string name);
  private:
    string CRN;
    string department;
    string number;
    string name;
};
