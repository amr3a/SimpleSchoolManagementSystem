#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentNiegborhoodScreen :public clsHeaderScreen
{
public:
	static void showUpdateStudentNiegborhoodScreen() {

		showMainHeader("  Update Student`s Nieghborhood Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Nieghborhood Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.nieghborhoodName = clsSharedStudentsFunctions::_readStudentNiegborhood();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s nieghborhood name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s nieghborhood name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s nieghborhood name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

