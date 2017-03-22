//Driver of the student database program
//WLSGRA012
#include <iostream>
#include "PrintManager.h"
#include "Student.h"

using namespace std;
void envokeFunction(int i);
bool inFunction;

int main()
{
	char answer[100];
	int i;
	
	PrintManager::PrintHelloMessage();
	
	for (;;){
		//prints out the users unteractive options
		PrintManager::PrintUI(); 

		//get user input
		PrintManager::PrintPrompt();
		cin.getline(answer, 10);
		if (answer == "q"){
			break;
		}
		
		//print stub message
		PrintManager::PrintStubMessage(answer);

		//evoke action requested
		//envokeFunction(answer);
		
	}
		
	return 0;
}

void envokeFunction(int i)
{
	//envokes query user specified
	if (i == '0'){
		//Add a student ~ called
		//instantiate variables
		string name_;
		string surname_;
		string studentNumber_;
		string classRecord_;

		//prompt and get variables from the user
		cout << endl << endl << "Enter Student Name:" << endl;
		cin >> name_;

		cout << "Enter Student Surname:" << endl;
		cin >> surname_;

		cout << "Enter Student Number:" << endl;
		cin >> studentNumber_;

		cout << "Enter Class Record" << endl;
		cin >> classRecord_;

		//create student object
		Student s(name_, surname_, studentNumber_, classRecord_);
		cout << endl << "Student:" << s.GetInfo() << " added" << endl; 
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
	
