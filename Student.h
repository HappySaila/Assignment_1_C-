#ifndef STUDENT_H
#define STUDENT_H
//WLSGRA012
#include <iostream>
#include <string>
namespace WLSGRA012 {

	using namespace std;

	class Student
	{
		public:
			Student(string name_, string surname_, string studentNumber_, string classRecord_);
			void SetName(string name_);
			void SetSurname(string surname_);
			void SetStudentNumber(string studentNumber_);
			void SetClassRecord(string classRecord_);

			string GetName();
			string GetSurname();
			string GetStudentNumber();
			string GetClassRecord();
			string GetInfo();
		private:
			string name;
			string surname;
			string studentNumber;
			string classRecord;
	};

}

#endif
