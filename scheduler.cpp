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
	string currentToken;
	for (unsigned int i = 0; i < input.size(); i++) {
		if (isspace(input[i]) != 0) {
			tL.push_back(currentToken);
			currentToken = "";
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
		cout << "Command not recognized, please try again." << endl;
	}
	else if (tL.at(0) == "quit") {
		checkExtraArguments(tL.size(), 1);
		exit(0);	
	}
	else if (tL.at(0) == "build") {
		checkExtraArguments(tL.size(), 5);
		if (tL.size() >= 5) {
			if (checkCRN(tL.at(1))) {
				if (checkDepartment(tL.at(2))) {
					if (checkNumber(tL.at(3))) {
						if (checkCourseName(tL.at(4))) {
							cL.add(Course(tL.at(1), tL.at(2), tL.at(3), tL.at(4)));
							cout << "build course " << tL.at(1) << " " << tL.at(2) << " " << tL.at(3) << " "<< tL.at(4) << endl;
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
				if (cL.remove(tL.at(1))) {
					cout << "Success: cancelled course " << tL.at(1) << endl;
				}
				else {
					; // fail, CRN exists
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 2);
	}
	else if (tL.at(0) == "enroll") {
		checkExtraArguments(tL.size(), 5);
		if (tL.size() >= 5) {
			if (checkBNumber(tL.at(1))) {
				if (checkUserID(tL.at(2))) {
					if (checkFirst(tL.at(3))) {
						if (checkLast(tL.at(4))) {
							if (sL.add(Student(tL.at(1), tL.at(2), tL.at(3), tL.at(4)))) {
								cout << "enroll student " << tL.at(1) << " (" << tL.at(2) << ") " << tL.at(4) << ", " << tL.at(3) << endl;
							}
							else {
								; // fail, B number exists
							}
						}
					}
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 5);
	}
	else if (tL.at(0) == "add") {
		checkExtraArguments(tL.size(), 3);
		if (tL.size() == 3) {
			if (checkBNumber(tL.at(1))) {
				if (checkCRN(tL.at(2))) {
					cL.getCourse(tL.at(2))->addStudent(tL.at(1));
					cout << "add student " << tL.at(1) << " into course " << tL.at(2) << endl;
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 3);
	}
	else if (tL.at(0) == "drop") {
		checkExtraArguments(tL.size(), 3);
		if (tL.size() == 3) {
			if (checkBNumber(tL.at(1))) {
				if (checkCRN(tL.at(2))) {
					cL.getCourse(tL.at(2))->dropStudent(tL.at(1));
					cout << "remove student " << tL.at(1) << " from course " << tL.at(2) << endl;
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 3);
	}
	else if (tL.at(0) == "roster") {
		checkExtraArguments(tL.size(), 2);
		if (tL.size() == 2) {
			if (checkCRN(tL.at(1))) {
				if (cL.checkExists(tL.at(1))) {
					cL.getCourse(tL.at(1))->printRoster();
				}
				else {
					; //print crn not in courselist
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 2);
	}
	else if (tL.at(0) == "schedule") {
		checkExtraArguments(tL.size(), 2);
		if (tL.size() == 2) {
			if (checkBNumber(tL.at(1))) {
				if (sL.checkExists(tL.at(1))) {
					sL.getStudent(tL.at(1))->printSchedule();
				}
				else {
					; // print student not in studentlist
				}
			}
		}
		checkNotEnoughArguments(tL.size(), 2);
	}
}
