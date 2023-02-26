#include <string>
#include <vector>

using namespace std;

//void printCourseRoster(string CRN, Course* courseList, Student* studentList);
//void printStudentSchedule(string BNumber, Course* courseList, Student* studentList;
void checkExtraArguments(int val, int max);
void checkNotEnoughArguments(int val, int min);
bool regexCheck(string s, string e);
bool checkCRN(string s);
bool checkDepartment(string s);
bool checkNumber(string s);
bool checkBNumber(string s);
bool checkUserID(string s);
string getRemainingString(vector<string> tL);
//bool checkCourseName(string s);
//bool checkFirst(string s);
//bool checkLast(string s);
