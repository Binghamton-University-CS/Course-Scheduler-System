#include <regex>
#include <string>
#include <iostream>

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
	if (!regexCheck(s, "\d{6}")) {
		cout << "Input Error: illegal CRN" << endl;
		return false;
	}
	return true;
}

bool checkDepartment(string s) {
	if (!regexCheck(s, "[A-Z][A-Z][A-Z]?[A-Z]?") {
		cout << "Input Error: illegal department" << endl;
		return false;
	}
	return true;
}

bool checkNumber(string s) {
	if (!regexCheck(s, "[1-6][0-9][0-9]") {
		cout << "Input Error: illegal course number" << endl;
		return false;
	}
	return true;
}

bool checkBNumber(string s) {
	if (!regexCheck(s, "B[0-9]{8}") {
		cout << "Input Error: illegal B number" << endl;
		return false;
	}
	return true;
}
