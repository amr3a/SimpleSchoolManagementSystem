#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentAddressScreen : public clsHeaderScreen
{
private:
	static void _readStudentAddress(clsStudents& tempObj) {
		if (clsInputValidate::CheckAnswer("Do you want to update student`s nieghborhood [Y/N] : ")) {
			tempObj.nieghborhoodName = clsSharedStudentsFunctions::_readStudentNiegborhood();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s district [Y/N] : ")) {
			tempObj.districtName = clsSharedStudentsFunctions::_readStudentDistrict();
		}
	}
public:
	static void showUpdateStudentAddressScreen() {

		showMainHeader("       Update Student`s Address Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Address !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		_readStudentAddress(student);

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s address [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s address updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s address .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};





