#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentBrithdateScreen :public clsHeaderScreen
{


public:
	static void showUpdateStudentBrithdateScreen() {

		showMainHeader("     Update Student`s Brithdate Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Brithdate !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.brithdate = clsSharedStudentsFunctions::_readStudentBrithdate();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s brithdate [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s brithdate updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s brithdate .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

