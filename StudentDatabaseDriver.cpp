//Driver of the student database program
//WLSGRA012
#include <iostream>
#include "cstdlib"
#include "PrintManager.h"
#include "Student.h"

using namespace std;
void envokeFunction(string i);
bool inFunction;

int main()
{
	string answer;
	int i;

	WLSGRA012::PrintManager::PrintHelloMessage();

	for (;;){
		//prints out the users unteractive options
		WLSGRA012::PrintManager::PrintUI();

		//get user input
		WLSGRA012::PrintManager::PrintPrompt();
		getline(cin, answer);

		if (answer == "q"){
			break;
		}

		//print stub message
		WLSGRA012::PrintManager::PrintStubMessage(answer);

		//evoke action requested
		envokeFunction(answer);

	}

	return 0;
}

void envokeFunction(string i)
{
	//envokes query user specified
	if (i == "0"){ //compare strings, will equal 0 if true
		//Add a student ~ called
		//instantiate variables
		string name_;
		string surname_;
		string studentNumber_;
		string classRecord_;

		//prompt and get variables from the user
		cout << endl << endl << "Enter Student Name:" << endl;
		getline(cin, name_);

		cout << "Enter Student Surname:" << endl;
		getline(cin, surname_);

		cout << "Enter Student Number:" << endl;
		getline(cin, studentNumber_);

		cout << "Enter Class Record" << endl;
		getline(cin, classRecord_);

		//create student object
		WLSGRA012::Student s(name_, surname_, studentNumber_, classRecord_);
		system("clear");
		cout << "-----------------------------------------------------" << endl;
		cout << "Student:" << s.GetInfo() << " added" << endl;
		cout << "-----------------------------------------------------" << endl;
	} else {
		cout << "not called" << endl;
	}
	// } else if (i == '1'){
	// 	cout << "Function ReadDatabase() called." << endl;
	// } else if (i == '2'){
	// 	cout << "Function SaveDatabase() called." << endl;
	// } else if (i == '3'){
	// 	cout << "Function DisplayGivenStudent() called." << endl;
	// } else if (i == '4'){
	// 	cout << "Function GradeStudent() called." << endl;
	// } else if (i == 'q'){
	// 	cout << "Thank you for using student database version 1000203.1302.2.1." << endl << "Goodbye!" << endl;
	// } else{
	// 	//i does not equal 0,1,2,3, or 4. Throw an error
	// 	cout << "Error! No such query. Please try again." << endl;
	// }
}

