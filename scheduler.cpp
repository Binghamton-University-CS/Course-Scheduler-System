#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>

#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H
#include "ExtraFunctions.h"
#endif

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentList.h"
#endif

#ifndef COURSELIST_H
#define COURSELIST_H
#include "CourseList.h"
#endif

using namespace std;

void showPrompt();
vector<string> getTokenListFromString(string input);
void processInputAndPrint(vector<string> tL, CourseList& cL, StudentList& sL);

int main() {
	string input;
	CourseList courseList = CourseList();
	StudentList studentList = StudentList();
	while (true){
		showPrompt();
		getline(cin, input);
		processInputAndPrint(getTokenListFromString(input), courseList, studentList);
	}
	return 0;
}

void showPrompt() {
   cout << "Enter [\"build <crn> <department> <number> <name>\"" << endl <<
                "       \"cancel <crn>\"" << endl <<
                "       \"enroll <bnumber> <userid> <first> <last>\"" << endl <<
                "       \"add <bnumber> <crn>\"" << endl <<
                "       \"drop <bnumber> <crn>\"" << endl <<
                "       \"roster <crn>\"" << endl <<
                "       \"schedule <bnumber>\"" << endl <<
                "       \"quit\"]" << endl <<
                ": ";
}

vector<string> getTokenListFromString(string input) {
	vector<string> tL = {};
	string currentToken = "";
	for (unsigned int i = 0; i < input.size(); i++) {
		if (isspace(input[i]) != 0) {
			if (currentToken != "") {
				tL.push_back(currentToken);
				currentToken = "";
			}
		}
		else {
			currentToken += input[i];
		}
	}
	if (currentToken != "") {
		tL.push_back(currentToken);
	}
	return tL;
}

void processInputAndPrint(vector<string> tL, CourseList& cL, StudentList& sL) {
	if (tL.size() == 0) {
		cout << "Input Error: command not recognized, please try again." << endl;
	}
	else if (tL.at(0) == "quit") {
		checkExtraArguments(tL.size(), 1);
		exit(0);	
	}
	else if (tL.at(0) == "build") {
		if (tL.size() >= 5) {
			if (checkCRN(tL.at(1))) {
				if (checkDepartment(tL.at(2))) {
					if (checkNumber(tL.at(3))) {
						string courseName = getRemainingString(tL);
						if (cL.add(tL.at(1), tL.at(2), tL.at(3), courseName)) {
							cout << "Success: built course " << tL.at(2) << tL.at(3) << " (CRN: " << tL.at(1) << ") : " << courseName << endl;
						}
						else {
							cout << "Fail: cannot build course " << tL.at(2) << tL.at(3) << " (CRN: " << tL.at(1) << ") : " << "CRN exists" << endl;
						}
					}
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 5);
	}
	else if (tL.at(0) == "cancel") {
		checkExtraArguments(tL.size(), 2);
		if (tL.size() >= 2) {
			if (checkCRN(tL.at(1))) {
				if (cL.checkExists(tL.at(1))) {
					string courseString = cL.getCourse(tL.at(1))->getString();
					cL.remove(tL.at(1));
					sL.removeAllCourse(courseString);
					cout << "Success: cancelled course " << tL.at(1) << endl;
				}
				else {
					cout << "Fail: cannot cancel course, CRN does not exist" << endl;
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 2);
	}
	else if (tL.at(0) == "enroll") {
		if (tL.size() >= 5) {
			if (checkBNumber(tL.at(1))) {
				if (checkUserID(tL.at(2))) {
					string last = getRemainingString(tL);
					if (sL.add(tL.at(1), tL.at(2), tL.at(3), last)) {
						cout << "Success: enrolled student " << tL.at(1) << " (" << tL.at(2) << ") " << last << ", " << tL.at(3) << endl;
					}
					else {
						cout << "Fail: cannot enroll student, B Number exists" << endl;
					}
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 5);
	}
	else if (tL.at(0) == "add") {
		checkExtraArguments(tL.size(), 3);
		if (tL.size() >= 3) {
			if (checkBNumber(tL.at(1))) {
				if (checkCRN(tL.at(2))) {
					if (sL.checkExists(tL.at(1))) {
						if (cL.checkExists(tL.at(2))) {
							if (cL.getCourse(tL.at(2))->checkContainsStudent(sL.getStudent(tL.at(1))->getString()) == false) {
								cL.getCourse(tL.at(2))->addStudent(sL.getStudent(tL.at(1))->getString());
								sL.getStudent(tL.at(1))->addCourse(cL.getCourse(tL.at(2))->getString());
								cout << "Success: added student " << tL.at(1) << " into course " << tL.at(2) << endl;
							}
							else {
								cout << "Fail: cannot add, student " << tL.at(1) << " already enrolled in course " << tL.at(2) << endl;
							}
						}
						else {
							cout << "Fail: course does not exist" << endl;
						}
					}
					else {
						cout << "Fail: student does not exist" << endl;
					}
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 3);
	}
	else if (tL.at(0) == "drop") {
		checkExtraArguments(tL.size(), 3);
		if (tL.size() >= 3) {
			if (checkBNumber(tL.at(1))) {
				if (checkCRN(tL.at(2))) {
					if (sL.checkExists(tL.at(1))) {
						if (cL.checkExists(tL.at(2))) {
							if (cL.getCourse(tL.at(2))->checkContainsStudent(sL.getStudent(tL.at(1))->getString()) == true) {
								cL.getCourse(tL.at(2))->dropStudent(sL.getStudent(tL.at(1))->getString());
								sL.getStudent(tL.at(1))->removeCourse(cL.getCourse(tL.at(2))->getString());
								cout << "Success: removed student " << tL.at(1) << " from course " << tL.at(2) << endl;
							}
							else {
								cout << "Fail: cannot drop, student " << tL.at(1) << " not enrolled in course " << tL.at(2) << endl;
							}
						}
						else {
							cout << "Fail: course does not exist" << endl;
						}
					}
					else {
						cout << "Fail: student does not exist" << endl;
					}
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 3);
	}
	else if (tL.at(0) == "roster") {
		checkExtraArguments(tL.size(), 2);
		if (tL.size() >= 2) {
			if (checkCRN(tL.at(1))) {
				if (cL.checkExists(tL.at(1))) {
					cL.getCourse(tL.at(1))->printRoster();
				}
				else {
					cout << "Fail: CRN does not exist" << endl;
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 2);
	}
	else if (tL.at(0) == "schedule") {
		checkExtraArguments(tL.size(), 2);
		if (tL.size() >= 2) {
			if (checkBNumber(tL.at(1))) {
				if (sL.checkExists(tL.at(1))) {
					sL.getStudent(tL.at(1))->printSchedule();
				}
				else {
					cout << "Fail: BNumber does not exist" << endl;
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 2);
	}
	else {
		checkExtraArguments(tL.size(), 1);
		cout << "Input Error: command not recognized, please try again." << endl;
	}
}
