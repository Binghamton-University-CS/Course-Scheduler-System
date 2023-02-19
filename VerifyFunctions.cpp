#include <regex>
#include <string>

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
