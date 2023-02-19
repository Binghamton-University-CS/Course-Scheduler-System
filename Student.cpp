#include <string>

class Student {
  public:
    Student(string BNumber, string userID, string first, string last) {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
    }
  private:
    string BNumber;
    string userID;
    string first;
    string last;  
};
