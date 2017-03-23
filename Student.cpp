//WLSGRA012
//Student object
#include <iostream>
#include <string>
#include <sstream>
#include "Student.h"

using namespace std;

//constructor
WLSGRA012::Student::Student(string name_, string surname_, string studentNumber_, string classRecord_){
	SetName(name_);
	SetSurname(surname_);
	SetStudentNumber(studentNumber_);
	SetClassRecord(classRecord_);
}

//setters
void WLSGRA012::Student::SetName(string name_){
	name = name_;
}

void WLSGRA012::Student::SetSurname(string surname_){
	surname = surname_;
}

void WLSGRA012::Student::SetStudentNumber(string studentNumber_){
	studentNumber = studentNumber_;
}

void WLSGRA012::Student::SetClassRecord(string classRecord_){
	classRecord = classRecord_;
}

bool WLSGRA012::Student::CompareTo(WLSGRA012::Student t){
	//will return true if the name, surname and the student number are the same
	return GetName() == t.GetName() && GetSurname() == t.GetSurname() && GetStudentNumber() == t.GetStudentNumber();
}

//getters
string WLSGRA012::Student::GetName(){
	return name;
}

string WLSGRA012::Student::GetSurname(){
	return surname;
}

string WLSGRA012::Student::GetStudentNumber(){
	return studentNumber;
}

string WLSGRA012::Student::GetClassRecord(){
	return classRecord;
}

string WLSGRA012::Student::GetInfo(){
	//to string of object values
	stringstream ss;
	ss << GetName() << " " << GetSurname() << " " << GetStudentNumber() << " " << GetClassRecord() << " .";
	return ss.str();
}
