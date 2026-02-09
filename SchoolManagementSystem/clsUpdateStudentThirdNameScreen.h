#pragma once
#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentThirdNameScreen : public clsHeaderScreen
{
public:
	static void showUpdateStudentThirdNameScreen() {

		showMainHeader("     Update Student`s Third Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Third Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.thirdName = clsSharedStudentsFunctions::_readStudentThirdName();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s third name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s Third name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s third name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};



