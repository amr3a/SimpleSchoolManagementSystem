#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentSecondNameScreen: public clsHeaderScreen
{
public:
	static void showUpdateStudentSecondNameScreen() {
		
		showMainHeader("     Update Student`s Second Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Second Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.secondName = clsSharedStudentsFunctions::_readStudentSecondName();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s Second name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s Second name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s Second name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};

