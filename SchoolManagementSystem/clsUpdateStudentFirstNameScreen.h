#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentFirstNameScreen:public clsHeaderScreen
{
public:
	static void showUpdateStudentFirstNameScreen() {

		showMainHeader("     Update Student`s First Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s first Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.firstName = clsSharedStudentsFunctions::_readStudentFirstName();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s first name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s first name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s first name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

