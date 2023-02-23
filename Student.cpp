#include <string>

class Student {
  public:
    Student(string BNumber, string userID, string first, string last) {
      this->BNumber = BNumber;
      this->userID = userID;
      this->first = first;
      this->last = last;
    }
    void addCourse(Course course) {
      courseList.add(course);
    }
    void removeCourse(Course course) {
      courseList.remove(course);
    }
  private:
    string BNumber;
    string userID;
    string first;
    string last; 
    MichaelList<Course> courseList;
};
