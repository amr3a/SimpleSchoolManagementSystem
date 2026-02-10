#pragma once
#include "clsStudents.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsSharedStudentsFunctions
{

public :
	static clsStudents _readStudentByID() {
		string studentID = clsInputValidate::ReadOneWord("\nEnter student ID : ");
		clsStudents student = clsStudents::findStudentByID(studentID);
		while (student.isEmpty()) {
			studentID = clsInputValidate::ReadOneWord("Student with ID [" + studentID + "] is not exists, Please enter an existing ID :");
			student = clsStudents::findStudentByID(studentID);
		}

		return student;
	}
	static clsClasses::enClasses _readStudentenClass() {

		cout << "\nChoose student`s class : \n\n";
		string Spaces = "    ";
		short Column1 = 18,
			Column2 = 28,
			Column3 = 29,
			Column4 = 28;


		cout << Spaces << setw(Column1) << left << "[01] Frist Grade" << setw(Column2) << left << "[02] Second Grade" << setw(Column3) << left << "[03] Third Grade" << setw(Column4) << left << "[04] Fourth Grade" << "\n";
		cout << Spaces << setw(Column1) << left << "[05] Fifth Grade" << setw(Column2) << left << "[06] Sixth Grade" << setw(Column3) << left << "[07] Seventh Grade" << setw(Column4) << left << "[08] Eighth Grade" << "\n";
		cout << Spaces << setw(Column1) << left << "[09] Ninth Grade" << setw(Column2) << left << "[10] Frist Secondary Grade" << setw(Column3) << left << "[11] Second Secondary Grade" << setw(Column4) << left << "[12] Third Secondary Grade" << "\n";

		string Message = "\nEnter your choice : ";
		string AlternativeMassage = "InValid Input, Please enter valid input : ";
		return (clsClasses::enClasses)clsInputValidate::ReadNumberBetween<short>(Message, AlternativeMassage, 1, 12);
	}
	static clsStudents::enStudentStatus _readStudentStatus() {


		cout << "\nChoose student`s status : \n\n";

		string Spaces = "    ";
		short Column1 = 15,
			Column2 = 17,
			Column3 = 13,
			Column4 = 25;


		cout << Spaces << setw(Column1) << left << "[01] Enrolled" << setw(Column2) << left << "[02] Transfered" << setw(Column3) << left << "[03] Absent" << setw(Column4) << left << "[04] Tempararory Absent" << "\n";
		cout << Spaces << setw(Column1) << left << "[05] Suspended" << setw(Column2) << left << "[06] Passed" << setw(Column3) << left << "[07] Failed" << setw(Column4) << left << "[08] InCompleted" << "\n";


		string Message = "\nEnter your choice : ";
		string AlternativeMassage = "InValid Input, Please enter valid input : ";
		return (clsStudents::enStudentStatus)clsInputValidate::ReadNumberBetween<short>(Message, AlternativeMassage, 1, 8);
	}
	static string _readStudentFirstName() {
		return clsInputValidate::ReadOneWord("Enter student`s first Name : ");
	}
	static string _readStudentSecondName() {
		return clsInputValidate::ReadOneWord("Enter student`s Second Name : ");
	}
	static string _readStudentThirdName() {
		return clsInputValidate::ReadOneWord("Enter student`s Third Name : ");
	}
	static string _readStudentFourthName() {
		return clsInputValidate::ReadOneWord("Enter student`s Fourth Name : ");
	}
	static string _readStudentLastName() {
		return clsInputValidate::ReadOneWord("Enter student`s Last Name : ");
	}

	static clsDate _readStudentBrithdate() {
		cout << "Enter student`s brithdate :\n";
		return clsInputValidate::ReadDateBetween(clsDate(1, 1, 2000), clsDate(31, 12, 2021));
	}

	static string _readStudentNiegborhood() {
		return clsInputValidate::ReadOneWord("Enter student`s nieghborhood : ");
	}
	static string _readStudentDistrict() {
		return clsInputValidate::ReadOneWord("Enter student`s district Name : ");
	}

	static string _readStudentPhoneNumber() {
		return clsInputValidate::ReadString("Enter student`s phone number : ");
	}
	static clsClasses _readStudentClass() {
		return clsClasses(_readStudentenClass());
	}
	static clsDate _readStudentRegestrationDate() {
		cout << "Enter student`s regestration Date :\n";
		return clsInputValidate::ReadDateBetween(clsDate(1, 1, 2000), clsDate());
	}
	static string _readStudentNote() {
		return clsInputValidate::ReadString("Enter Note for the Student : ");
	}

	static void _readStudentData(clsStudents& tempObj) {

		cout << "\nPlease enter student`s Data that you want to update : \n\n";
		if (clsInputValidate::CheckAnswer("Do you want to update student`s first Name [Y/N] : ")) {
			tempObj.firstName = _readStudentFirstName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s second Name [Y/N] : ")) {
			tempObj.secondName = _readStudentSecondName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s third Name [Y/N] : ")) {
			tempObj.thirdName = _readStudentThirdName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s fourth Name [Y/N] : ")) {
			tempObj.fourthName = _readStudentFourthName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s last Name [Y/N] : ")) {
			tempObj.lastName = _readStudentLastName();
		}


		if (clsInputValidate::CheckAnswer("Do you want to update student`s brithdate [Y/N] : ")) {
		
			tempObj.brithdate = _readStudentBrithdate();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s nieghborhood [Y/N] : ")) {
			tempObj.nieghborhoodName = _readStudentNiegborhood();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s district [Y/N] : ")) {
			tempObj.districtName = _readStudentDistrict();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s phone number [Y/N] : ")) {
			tempObj.phoneNumber = _readStudentPhoneNumber();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s Class Name [Y/N] : ")) {
			tempObj.studentClass = _readStudentClass();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s Regestration Date [Y/N] : ")) {
			
			tempObj.regestrationDate = _readStudentRegestrationDate();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s status [Y/N] : ")) {
			tempObj.studentStatus = _readStudentStatus();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s note [Y/N] : ")) {
			tempObj.studentNote = _readStudentNote();
		}

	}
	static void _readStudentData(clsStudents& tempObj, const bool isOldStudent) {
		cout << "\nPlease enter student`s Data : \n\n";
		tempObj.firstName = _readStudentFirstName();
		tempObj.secondName = _readStudentSecondName();
		tempObj.thirdName = _readStudentThirdName();
		tempObj.fourthName = _readStudentFourthName();
		tempObj.lastName = _readStudentLastName();
		cout << endl;
		cout << "Enter student`s brithdate :\n";
		tempObj.brithdate = _readStudentBrithdate();


		tempObj.nieghborhoodName = _readStudentNiegborhood();
		tempObj.districtName = _readStudentDistrict();
		tempObj.phoneNumber = _readStudentPhoneNumber();
		tempObj.studentClass = _readStudentClass();
		if (isOldStudent) {
			cout << "Enter student`s RegestrationDate :\n";
			tempObj.regestrationDate = _readStudentRegestrationDate();
		}
		else {
			tempObj.regestrationDate = clsDate::GetSystemDate();
		}


		tempObj.studentStatus = _readStudentStatus();
		tempObj.studentNote = _readStudentNote();
	}
	static clsStudents _readStudentByID(string& studentID) {

		clsStudents student = clsStudents::findStudentByID(studentID);
		return student;
	}
	static void _printStudentInfoCard(clsStudents& student) {
		string LineSperator = clsUtil::UnderScore(15);
		short width = 29;
		cout << "\n\n Student`s Info Card : \n";
		cout << LineSperator << "\n\n";
		cout << setw(width) << left << " student`s ID" << ":  " << student.studentID << "\n";
		cout << setw(width) << left << " student`s Full Name" << ":  " << student.fullName << "\n";
		cout << setw(width) << left << " student`s Brithdate" << ":  " << student.brithdate.DateToString() << "\n";
		cout << setw(width) << left << " student`s Address" << ":  " << student.address << "\n";
		cout << setw(width) << left << " student`s Phone Number" << ":  " << student.phoneNumber << "\n";
		cout << setw(width) << left << " student`s Class" << ":  " << student.studentClass.className << "\n";
		cout << setw(width) << left << " student`s Regestration Date" << ":  " << student.regestrationDate.DateToString() << "\n";
		cout << setw(width) << left << " student`s Status" << ":  " << student.StudentStatus << "\n";
		cout << setw(width) << left << " student`s Note" << ":  " << student.studentNote << "\n";
		cout << LineSperator << "\n";
	}

};

