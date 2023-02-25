#include <regex>
#include <string>
#include <iostream>

#ifndef COURSE_H
#define COURSE_H
#include "Course.h"
#endif

#ifndef STUDENT_H
#define STUDENT_H
#include "Student.h"
#endif

using namespace std;

//void printCourseRoster(string CRN, Course* courseList, Student* studentList) {
//	Course course = courseList->find(CRN);
//	MichaelList<string> BNumbers = course.getStudents();
//	cout << "CRN: " << CRN << endl;
//	cout << "Students: " << BNumbers.getSize() << endl;
//	for (int i = 0; i < BNumbers.getSize(); i++) {
//		cout << BNumbers.at(i) << studentList->find(BNumbers.at(i)).getName() << endl;
//	}
//}

//void printStudentSchedule(string BNumber, Course* courseList, Student* studentList) {
//	Student student = studentList->find(BNumber);
//}

void checkExtraArguments(int val, int max) {
	if (val > max) {
		cout << "Warning: ignoring extra argument(s)" << endl;
	}
}

void checkNotEnoughArguments(int val, int min) {
	if (val < min) {
		cout << "Input Error: too few arguments" << endl;
	}
}

bool regexCheck(string s, string e) {
	if (regex_match(s, regex(e))) {
		return true;
	}
	return false;
}

bool checkCRN(string s) {
	if (!regexCheck(s, "^\d{6}$")) {
		cout << "Input Error: illegal CRN" << endl;
		return false;
	}
	return true;
}

bool checkDepartment(string s) {
	if (!regexCheck(s, "^[A-Z][A-Z][A-Z]?[A-Z]?$")) {
		cout << "Input Error: illegal department" << endl;
		return false;
	}
	return true;
}

bool checkNumber(string s) {
	if (!regexCheck(s, "^[1-6][0-9][0-9]$")) {
		cout << "Input Error: illegal course number" << endl;
		return false;
	}
	return true;
}

bool checkBNumber(string s) {
	if (!regexCheck(s, "^B[0-9]{8}$")) {
		cout << "Input Error: illegal B number" << endl;
		return false;
	}
	return true;
}

bool checkUserID(string s) {
	if (!regexCheck(s, "^[a-zA-Z][a-zA-Z0-9]*$")) {
		cout << "Input Error: illegal user ID" << endl;
	}
	return true;
}

bool checkFirst(string s) {
	return true;
}

bool checkLast(string s) {
	return true;
}
