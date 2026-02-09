#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentDistrictScreen :public clsHeaderScreen
{
public:
	static void showUpdateStudentDistrictScreen() {

		showMainHeader("    Update Student`s District Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s District Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.districtName = clsSharedStudentsFunctions::_readStudentDistrict();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s district name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s district name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s district name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

