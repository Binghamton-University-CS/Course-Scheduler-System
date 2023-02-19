#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "Student.cpp"
#include "Course.cpp"
#include "VerifyFunctions.cpp"

using namespace std;

vector<string> getTokenListFromString(string input);
void processInputAndPrint(vector<string>);
void showPrompt();
bool regexCheck(string s, string e);

int main() {
	string input;
	while (true){
		showPrompt();
		getline(cin, input);
		processInputAndPrint(getTokenListFromString(input));
	}
	return 0;
}

vector<string> getTokenListFromString(string input) {
	vector<string> tokenList = {};
	string currentToken;
	for (unsigned int i = 0; i < input.size(); i++) {
		if (isspace(input[i]) != 0) {
			tokenList.push_back(currentToken);
			currentToken = "";
		}
		else {
			currentToken += input[i];
		}
	}
	if (currentToken != "") {
		tokenList.push_back(currentToken);
	}
	return tokenList;
}

void processInputAndPrint(vector<string> tokenList) {
	if (tokenList.size() == 0) {
		cout << "Command not recognized, please try again." << endl;
	}
	else if (tokenList.at(0) == "quit") {
		exit(0);	
	}
	else if (tokenList.at(0) == "build") {
		if (tokenList.size() == 5) {
			if (checkCRN(tokenList.at(1)) {
				if (checkDepartment(tokenList.at(2)) {
					if (checkNumber(tokenList.at(3)) {
						cout << "build course " << tokenList.at(1) << " " << tokenList.at(2) << " " << tokenList.at(3) << " "<< tokenList.at(4) << endl;
					}
				}
			}
		}
	}
	else if (tokenList.at(0) == "cancel") {
		if (checkCRN(tokenList.at(1)) {
			if (tokenList.size() == 2) {
				cout << "Success: cancelled course " << tokenList.at(1) << endl;
			}
		}
	}
	else if (tokenList.at(0) == "enroll") {
		if (tokenList.size() == 5) {
			cout << "enroll student " << tokenList.at(1) << " (" << tokenList.at(2) << ") " << tokenList.at(4) << ", " << tokenList.at(3) << endl;
		}
	}
	else if (tokenList.at(0) == "add") {
		if (tokenList.size() == 3) {
			cout << "add student " << tokenList.at(1) << " into course " << tokenList.at(2) << endl;
		}
	}
	else if (tokenList.at(0) == "drop") {
		if (tokenList.size() == 3) {
			cout << "remove student " << tokenList.at(1) << " from course " << tokenList.at(2) << endl;	
		}
	}
	else if (tokenList.at(0) == "roster") {
		if (tokenList.size() == 2) {
			cout << "roster of course " << tokenList.at(1) << endl;
		}
	}
	else if (tokenList.at(0) == "schedule") {
		if (tokenList.size() == 2) {
			cout << "schedule of student " << tokenList.at(1) << endl;
		}
	}
	
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
