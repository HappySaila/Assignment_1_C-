//WLSGRA012
//Student object
#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;

//constructor
Student::Student(string name_, string surname_, string studentNumber_, string classRecord_){
	SetName(name_);
	SetSurname(surname_);
	SetStudentNumber(studentNumber_);
	SetClassRecord(classRecord_);
	cout << GetName() << endl << GetSurname() << endl << GetStudentNumber() << endl << GetClassRecord() << endl; 
}

//setters
void Student::SetName(string name_){
	name = name_;
}

void Student::SetSurname(string surname_){
	surname = surname_;
}

void Student::SetStudentNumber(string studentNumber_){
	studentNumber = studentNumber_;
}

void Student::SetClassRecord(string classRecord_){
	classRecord = classRecord_;
}

//getters
string Student::GetName(){
	return name;
}

string Student::GetSurname(){
	return surname;
}

string Student::GetStudentNumber(){
	return studentNumber;
}

string Student::GetClassRecord(){
	return classRecord;
}

string Student::GetInfo(){
	//to string of object values
	stringstream ss;
	ss << "<" << GetName() << ", " << GetSurname() << ", " << GetStudentNumber() << ", " << GetClassRecord() << ">";
	return ss.str();
}
