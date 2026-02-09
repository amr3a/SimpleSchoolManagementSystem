#pragma once
#include "clsHeaderScreen.h"
#include "clsStudents.h"
#include "clsInputValidate.h"
#include "clsSharedStudentsFunctions.h"
#include "clsUtil.h"
#include <iomanip>
class clsUpdateStudentScreen:public clsHeaderScreen
{
public:
	static void showUpdateStudentScreen() {
		showMainHeader("     Update Student Info Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		clsSharedStudentsFunctions::_readStudentData(student);

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s data [Y/N] :")) {
			if (student.save()) {
				cout << "The student updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update studnet .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
	
};

