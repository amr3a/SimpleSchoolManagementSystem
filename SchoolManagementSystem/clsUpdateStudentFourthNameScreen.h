#pragma once
#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentFourthNameScreen : public clsHeaderScreen
{
public:
	static void showUpdateStudentFourthNameScreen() {

		showMainHeader("     Update Student`s Fourth Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Fourth Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.fourthName = clsSharedStudentsFunctions::_readStudentFourthName();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s fourth name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s fourth name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s fourth name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};



