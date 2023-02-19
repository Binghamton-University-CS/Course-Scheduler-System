#include <string>

class Student {
  public:
    Student(string first, string last, string userID, string bNumber);
  private:
    string bNumber;
    string first;
    string last;
    string userID;
}
