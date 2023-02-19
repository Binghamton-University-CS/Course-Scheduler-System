#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>
#include "Student.cpp"
#include "Course.cpp"
#include "ExtraFunctions.cpp"

using namespace std;

void showPrompt();
vector<string> getTokenListFromString(string input);
void processInputAndPrint(vector<string>);

int main() {
	string input;
	while (true){
		showPrompt();
		getline(cin, input);
		processInputAndPrint(getTokenListFromString(input));
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
		checkExtraArguments(tokenList.size(), 1);
		exit(0);	
	}
	else if (tokenList.at(0) == "build") {
		checkExtraArguments(tokenList.size(), 5);
		if (tokenList.size() >= 5) {
			if (checkCRN(tokenList.at(1)) {
				if (checkDepartment(tokenList.at(2)) {
					if (checkNumber(tokenList.at(3)) {
						cout << "build course " << tokenList.at(1) << " " << tokenList.at(2) << " " << tokenList.at(3) << " "<< tokenList.at(4) << endl;
					}
				}
			}
		}
		checkNotEnoughArguments(tokenList.size(), 5);
	}
	else if (tokenList.at(0) == "cancel") {
		checkExtraArguments(tokenList.size(), 2);
		if (tokenList.size() >= 2) {
			if (checkCRN(tokenList.at(1)) {
				cout << "Success: cancelled course " << tokenList.at(1) << endl;
			}
		}
		checkNotEnoughArguments(tokenList.size(), 2);
	}
	else if (tokenList.at(0) == "enroll") {
		checkExtraArguments(tokenList.size(), 5);
		if (tokenList.size() >= 5) {
			if (checkBNumber(tokenList.at(1))) {
				if (checkUserID(tokenList.at(2))) {
					if (checkFirst(tokenList.at(3))) {
						if (checkLast(tokenList.at(4))) {
							cout << "enroll student " << tokenList.at(1) << " (" << tokenList.at(2) << ") " << tokenList.at(4) << ", " << tokenList.at(3) << endl;
						}
					}
				}
			}
		}
		checkNotEnoughArguments(tokenList.size(), 5);
	}
	else if (tokenList.at(0) == "add") {
		checkExtraArguments(tokenList.size(), 3);
		if (tokenList.size() == 3) {
			cout << "add student " << tokenList.at(1) << " into course " << tokenList.at(2) << endl;
		}
		checkNotEnoughArguments(tokenList.size(), 3);
	}
	else if (tokenList.at(0) == "drop") {
		checkExtraArguments(tokenList.size(), 3);
		if (tokenList.size() == 3) {
			cout << "remove student " << tokenList.at(1) << " from course " << tokenList.at(2) << endl;	
		}
		checkNotEnoughArguments(tokenList.size(), 3);
	}
	else if (tokenList.at(0) == "roster") {
		checkExtraArguments(tokenList.size(), 2);
		if (tokenList.size() == 2) {
			cout << "roster of course " << tokenList.at(1) << endl;
		}
		checkNotEnoughArguments(tokenList.size(), 2);
	}
	else if (tokenList.at(0) == "schedule") {
		checkExtraArguments(tokenList.size(), 2);
		if (tokenList.size() == 2) {
			cout << "schedule of student " << tokenList.at(1) << endl;
		}
		checkNotEnoughArguments(tokenList.size(), 2);
	}
}
