#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentRegestrationDateScreen :public clsHeaderScreen
{
public:
	static void showUpdateStudentRegestrationDateScreen() {

		showMainHeader("  Update Student`s Regestration Date Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Regestration Date !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.regestrationDate = clsSharedStudentsFunctions::_readStudentRegestrationDate();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s regestration date [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s regestration date updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s regestration date .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

