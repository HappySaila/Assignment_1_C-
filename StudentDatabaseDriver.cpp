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
void ClearDatabase();
void gradeStudent(WLSGRA012::Student);
WLSGRA012::Student findStudent(string studentNumber);

//variables
vector<WLSGRA012::Student> temporyStudents;
vector<WLSGRA012::Student> savedStudents;
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
	writeDataToFile();
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
	} else if (i == "3"){
		//promt the user for the first name and last name of the pupil
		//only saved students will be searched
		string firstName;
		int counter = 0;
		cout << "Enter the first name of the student you want to find: " << endl;
		getline(cin, firstName);
		system("clear");
		printUILine();
		for (int i = 0; i < savedStudents.size(); i++){
			if (savedStudents[i].GetName() == firstName){
				cout << counter+1 << ") " << savedStudents[i].GetInfo() << endl;
				counter++;
			}

		}
		if (counter == 0){
			cout << firstName << " was not found in the database." << endl;
			printUILine();
		} else {
			printUILine();
		}

	} else if (i == "4"){
	 	cout << "Enter the student number you want to grade: " << endl;
	 	string studentNumberToGrade;
	 	getline(cin, studentNumberToGrade);
	 	WLSGRA012::Student s = findStudent(studentNumberToGrade);
	 	if (s.GetStudentNumber() == ""){
	 		//student was not found
	 		system("clear");
	 		printUILine();
	 		cout << "Student was not found with the student number <" << studentNumberToGrade << ">." <<endl;
	 		printUILine();
	 		return;
	 	} else {
	 		//student was found. Grade the student
	 		gradeStudent(s);
	 	}
	} else if (i == "5"){
		ClearDatabase();
	} 
	//else if (i == 'q'){
	// 	cout << "Thank you for using student database version 1000203.1302.2.1." << endl << "Goodbye!" << endl;
	// } else{
	// 	//i does not equal 0,1,2,3, or 4. Throw an error
	// 	cout << "Error! No such query. Please try again." << endl;
	// }
}

WLSGRA012::Student findStudent(string studentNumber){
	WLSGRA012::Student s("", "", "", "");
	for (int i = 0; i < savedStudents.size(); i++){
		if (studentNumber == savedStudents[i].GetStudentNumber()){
			//student numbers match
			s = savedStudents[i];
			break;
		}
	}
	return s;
}

void gradeStudent(WLSGRA012::Student s){
	//will print the average of the student record
	//convert string to char array
	char val[1024];
	strcpy(val, s.GetClassRecord().c_str());

	//convert char array to vector<int>
	vector<int> values;
	int i = 0;
	int counter = 0;
	char* point;
	point = strtok(val, " ");

	while (point != NULL){
		// cout << atoi(point) << endl;
		i+=atoi(point);
		counter++;
		point = strtok(NULL, " ");
	}

	cout << i << endl;

	system("clear");
	printUILine();
	cout << s.GetStudentNumber() << " was graded averaging: " << i/counter << endl;
	printUILine();
}

void addRecordToVector(WLSGRA012::Student s){
	for (int i = 0; i < savedStudents.size(); i++){
		WLSGRA012::Student t = savedStudents[i];
		if (s.GetStudentNumber() == t.GetStudentNumber()){
			system("clear");
			printUILine();
			cout << "Student:" << s.GetInfo() << "was not added! Duplicate found." << endl;
			printUILine();
			return;
		}
	}
	temporyStudents.push_back(s);
	system("clear");
	printUILine();
	cout << "Student:" << s.GetInfo() << " added" << endl;
	printUILine();
}

void ClearDatabase(){
	//will remove all data in the database
	outFile.open("StudentDatabase.txt", std::ofstream::out | std::ofstream::trunc);
	outFile.close();
	writeDataToFile();
}


void printUILine(){
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

	inFile.open("StudentDatabase.txt");
	if (inFile.fail()){
		cout << "Error opening file at the current time." << endl;
	}

	//update the savedStudent list to contain a list of students
	string line;
	vector<string> subLine;
	savedStudents.clear();
	while (!inFile.eof()){

		while(!inFile.eof()){
			inFile >> line;
			if (line == "."){
				break;
			}
			if (line != ","){
				subLine.push_back(line);
			}
		}

		string classRecord;
		// cout << "line: " << subLine[0];
		for (int i = 3; i < subLine.size(); i++){
			classRecord += subLine[i] + " ";
		}
		//create the student object
		WLSGRA012::Student s(subLine[0], subLine[1], subLine[2], classRecord);

		//add student to savedStudents
		savedStudents.push_back(s);
			
		subLine.clear();

	}

	savedStudents.pop_back();

	inFile.close();

}
