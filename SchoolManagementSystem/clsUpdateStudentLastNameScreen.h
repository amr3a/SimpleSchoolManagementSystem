#pragma once
#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentLastNameScreen : public clsHeaderScreen
{
public:
	static void showUpdateStudentLastNameScreen() {

		showMainHeader("      Update Student`s Last Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Last Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.lastName = clsSharedStudentsFunctions::_readStudentLastName();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s last name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s last name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s last name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};



