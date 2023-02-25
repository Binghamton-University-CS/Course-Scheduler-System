#include <string>

using namespace std;

class Student {
  public:
    Student(string BNumber, string userID, string first, string last);
    void addCourse(string course);
    void removeCourse(string course);
    void printCourses();
  private:
    string BNumber;
    string userID;
    string first;
    string last; 
    StringList courseList;
};
