//Driver of the student database program
//WLSGRA012
#include <iostream>
#include <fstream>
#include <vector>
#include "cstdlib"
#include "PrintManager.h"
#include "Student.h"

using namespace std;
//prototype methods
void envokeFunction(string i);
void addRecordToVector(WLSGRA012::Student s);
void printUILine();
vector<string> getDatabaseContent();
void writeDataToFile();

//variables
vector<WLSGRA012::Student> temporyStudents;
vector<string> oldDataContent;
ifstream inFile;
ofstream outFile;

int main()
{
	string answer;
	int i;
	//vector containing all students that have not been added to the database.
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
		addRecordToVector(s);
		system("clear");
		printUILine();
		cout << "Student:" << s.GetInfo() << " added" << endl;
		printUILine();
	} else if (i == "1"){
		//will print out all the records in the database as well as all the records that are not saved in the database
		//read records not in the database
		cout << "New students created (Not saved): " << endl;
		for (int i = 0 ; i < temporyStudents.size(); i++){
			cout << temporyStudents[i].GetInfo() << endl;
		}
		printUILine();
		//read the records already saved to database
		cout << "Students already in database: " << endl;
		oldDataContent = getDatabaseContent();
		for (int i = 0; i < oldDataContent.size(); i++){
			cout << oldDataContent[i] << endl;
		}
		printUILine();
	} else if (i == "2"){
		//will save all the student records of temporyStudents to the file studentDatabase.txt
		writeDataToFile();
	} else if (i == '3'){
		
	}	
	 // } else if (i == '4'){
	// 	cout << "Function GradeStudent() called." << endl;
	// } else if (i == 'q'){
	// 	cout << "Thank you for using student database version 1000203.1302.2.1." << endl << "Goodbye!" << endl;
	// } else{
	// 	//i does not equal 0,1,2,3, or 4. Throw an error
	// 	cout << "Error! No such query. Please try again." << endl;
	// }
}

void addRecordToVector(WLSGRA012::Student s){
	temporyStudents.push_back(s);
}

void printUILine()
{
	cout << "-----------------------------------------------------" << endl;
}

vector<string> getDatabaseContent(){
	//declare vector string that will be returned
	vector<string> dataToReturn;
	inFile.open("StudentDatabase.txt");
	//check if the file is error free
	if (inFile.fail()){
		cout << "Error opening file at the current time." << endl;
		return dataToReturn;
	}
	string line;
	string body;
	while (getline(inFile, line)){
		//rebuild student object here
		body += line + "\n";

		//save data to keep track of content in files.
		//this data will be rewritten to the file before a new write
		dataToReturn.push_back(line);
	}
	//cout << body << endl;
	inFile.close();
	return dataToReturn;
}

void writeDataToFile(){
	//get old content
	vector<string> oldContent = getDatabaseContent();
	//get new content in a vector<string> form
	vector<string> newContent;
	for (int i = 0 ; i < temporyStudents.size(); i++){
		newContent.push_back(temporyStudents[i].GetInfo());
	}
	//write all content to file. Write old content first and then the new content

	//open the file to write to
	outFile.open("StudentDatabase.txt");
	//write the old data back into the file
	for (int i = 0; i < oldContent.size(); i++){
		outFile << oldContent[i] << endl;
	}
	//write the new data back into the file
	for (int i = 0; i < newContent.size(); i++){
		outFile << newContent[i] << endl;
	}

	//clear all the data in the vectors
	temporyStudents.clear();

	outFile.close();






















}
