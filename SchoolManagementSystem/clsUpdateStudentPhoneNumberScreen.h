#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentPhoneNumberScreen :public clsHeaderScreen
{
public:
	static void showUpdateStudentPhoneNumberScreen() {

		showMainHeader("    Update Student`s Phone Number Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Phone Number !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.phoneNumber = clsSharedStudentsFunctions::_readStudentPhoneNumber();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s phone number [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s phone number updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s phone number .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

