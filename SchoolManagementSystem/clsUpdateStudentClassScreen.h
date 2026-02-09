#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentClassScreen :public clsHeaderScreen
{
public:
	static void showUpdateStudentClassScreen() {

		showMainHeader("        Update Student`s Class Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Class !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.studentClass = clsSharedStudentsFunctions::_readStudentClass();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s class [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s class updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s class .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

