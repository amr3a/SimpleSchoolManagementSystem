#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentStatusScreen:public clsHeaderScreen 
{


public:
	static void showUpdateStudentStatusScreen() {

		showMainHeader("        Update Student`s Status Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s status !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.studentStatus = clsSharedStudentsFunctions::_readStudentStatus();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s status [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s status updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s status .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
	
};

