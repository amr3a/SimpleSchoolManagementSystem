#pragma once
#include "clsTeachers.h"
#include "clsInputValidate.h"
#include <iomanip>
class clsSharedTeachersFunctions
{
public:
	static string _readTeacherFirstName() {
		return clsInputValidate::ReadOneWord("Enter teacher`s first Name : ");
	}
	static string _readTeacherSecondName() {
		return clsInputValidate::ReadOneWord("Enter teacher`s Second Name : ");
	}
	static string _readTeacherThirdName() {
		return clsInputValidate::ReadOneWord("Enter teacher`s Third Name : ");
	}
	static string _readTeacherFourthName() {
		return clsInputValidate::ReadOneWord("Enter teacher`s Fourth Name : ");
	}
	static string _readTeacherLastName() {
		return clsInputValidate::ReadOneWord("Enter teacher`s Last Name : ");
	}

	static clsDate _readTeacherBrithdate() {
		cout << "Enter teacher`s brithdate :\n";
		return clsInputValidate::ReadDateBetween(clsDate(1, 1, 2000), clsDate(31, 12, 2021));
	}

	static string _readTeacherNiegborhood() {
		return clsInputValidate::ReadOneWord("Enter teacher`s nieghborhood : ");
	}
	static string _readTeacherDistrict() {
		return clsInputValidate::ReadOneWord("Enter teacher`s district Name : ");
	}
	static string _readTeacherPhoneNumber() {
		return clsInputValidate::ReadString("Enter teacher`s phone number : ");
	}
	static clsDate _readTeacherHireDate() {
		cout << "Enter teacher`s hire Date :\n";
		return clsInputValidate::ReadDateBetween(clsDate(1, 1, 2000), clsDate());
	}
	static string _readTeacherNote() {
		return clsInputValidate::ReadString("Enter Note for the teacher : ");
	}
	static clsTeachers::enEducationLevel _readEducationLevel() {
		cout << "\nChoose student`s class : \n\n";
		string Spaces = "    ";
		short Column1 = 37,
			Column2 = 34,
			Column3 = 27;


		cout << Spaces << setw(Column1) << left << "[01] Bachelor of Quranic Sciences" << setw(Column2) << left << "[02] Bachelor of Islamic Studies" 
			<< setw(Column3) << left << "[03] Bachelor of Arabic Language" << "\n";

		cout << Spaces << setw(Column1)  << left << "[04] Bachelor of English Literature" << setw(Column2) << left << "[05] Bachelor of Mathematics"
			<< setw(Column3) << left << "[06] Bachelor of General Science" << "\n";

		cout << Spaces << setw(Column1) << left << "[07] Bachelor of Social Science" << setw(Column2) << left << "[08] Bachelor of History"
			<< setw(Column3) << left << "[09] Bachelor of Geography" << "\n";

		cout << Spaces << setw(Column1) << left << "[07] Bachelor of Social Science" << setw(Column2) << left << "[08] Bachelor of History"
			<< setw(Column3) << left << "[09] Bachelor of Geography" << "\n";

		cout << Spaces << setw(Column1) << left << "[10] Bachelor of Social Studies" << setw(Column2) << left << "[11] Bachelor of Physics" 
			<< setw(Column3) << left << "[12] Bachelor of Biology" << "\n";

		cout << Spaces << setw(Column1) << left << "[13] Bachelor of Chemistry\n";

		string Message = "\nEnter your choice : ";
		string AlternativeMassage = "InValid Input, Please enter valid input : ";
		return (clsTeachers::enEducationLevel)clsInputValidate::ReadNumberBetween<short>(Message, AlternativeMassage, 1, 12);
	}
	
	
	
};

