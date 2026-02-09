#pragma once
#include "clsHeaderScreen.h"
#include "clsStudents.h"
#include "clsInputValidate.h"
#include "clsSharedStudentsFunctions.h"
#include<iomanip>
class clsAddNewStudentScreen:public clsHeaderScreen {
private:

	enum enNewOrOldStudent {
		NewStudent = 1,
		OldStudent
	};
	
	static void _addNewOrOldStudentScreen(const bool isOldStudent = false) {

		

		clsStudents Student = clsStudents::getNewStudentObject();

		clsSharedStudentsFunctions::_readStudentData(Student, isOldStudent);

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to add the student [Y/N] : ")) {
			if (Student.save()) {
				cout << "The student added successfully ..\n";
			}
			else {
				cout << "There was an issue to add studnet .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
	static enNewOrOldStudent _readNewOrOldStudent() {
		string Message = " Enter your choice [1 - 2] : ";
		string AlternativeMassage = "InValid Input, Please enter valid input : ";
		return (enNewOrOldStudent)clsInputValidate::ReadNumberBetween<short>(Message, AlternativeMassage, 1, 2);
	}
	static void _performOption(enNewOrOldStudent UserOption) {
		string MainHeader = "      ";
		bool isOldStudent = false;
		switch (UserOption)
		{
		case clsAddNewStudentScreen::NewStudent:
			isOldStudent = false;
			MainHeader += "Add New Student Screen";
			break;
		case clsAddNewStudentScreen::OldStudent:
			isOldStudent = true;
			MainHeader += "Add Old Student Screen";
			break;
		default:
			MainHeader += "Add New Student Screen";
			break;
		}
		clsHeaderScreen::showMainHeader(MainHeader);
		_addNewOrOldStudentScreen(isOldStudent);
	}
public:
	static  void _addStudentScreen() {
		string MainHeader = "        ";
		
		MainHeader += "     Add Student Screen";
		clsHeaderScreen::showMainHeader(MainHeader);
		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << "    [01] Add New Student.\n";
		cout << "    [02] Add Old Student.\n";
		cout << LineSperator << "\n";
		
		_performOption(_readNewOrOldStudent());
		
	}
	
};

