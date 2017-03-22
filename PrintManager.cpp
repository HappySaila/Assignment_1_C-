//responsible for all stub printing
//WLSGRA012
#include <iostream>
#include "PrintManager.h"

using namespace std;

void PrintManager::PrintUI()
{
	//will print all functions the user can access
	cout << "0: Add student" << endl;
	cout << "1: Read database" << endl;
	cout << "2: Save database" << endl;
	cout << "3: Display given student data" << endl;
	cout << "4: Grade Student" << endl;
	cout << "q: Quit" << endl;
}

void PrintManager::PrintHelloMessage()
{
	cout << "Welcome to student database version 1000203.1302.2.1." << endl;
}

void PrintManager::PrintPrompt()
{
	cout << "Enter a number (or q to quit) and press return..." << endl;
}

void PrintManager::PrintStubMessage(string i)
{
	//let the user know which function they have called
	if (i == "0"){
		cout << "Function AddStudent() called." << endl;
	} else if (i == "1"){
		cout << "Function ReadDatabase() called." << endl;
	} else if (i == "2"){
		cout << "Function SaveDatabase() called." << endl;
	} else if (i == "3"){
		cout << "Function DisplayGivenStudent() called." << endl;
	} else if (i == "4"){
		cout << "Function GradeStudent() called." << endl;
	} else if (i == "q"){
		cout << "Thank you for using student database version 1000203.1302.2.1." << endl << "Goodbye!" << endl;
	} else{
		//i does not equal 0,1,2,3, or 4. Throw an error
		cout << "Error! No such query. Please try again." << endl;
	}
}
	
