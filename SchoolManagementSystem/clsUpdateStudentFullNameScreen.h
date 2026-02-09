#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentFullNameScreen : public clsHeaderScreen
{
private:
	static void _readStudentFullName(clsStudents& tempObj) {
		if (clsInputValidate::CheckAnswer("Do you want to update student`s first Name [Y/N] : ")) {
			tempObj.firstName = clsSharedStudentsFunctions::_readStudentFirstName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s second Name [Y/N] : ")) {
			tempObj.secondName = clsSharedStudentsFunctions::_readStudentSecondName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s third Name [Y/N] : ")) {
			tempObj.thirdName = clsSharedStudentsFunctions::_readStudentThirdName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s fourth Name [Y/N] : ")) {
			tempObj.fourthName = clsSharedStudentsFunctions::_readStudentFourthName();
		}
		if (clsInputValidate::CheckAnswer("Do you want to update student`s last Name [Y/N] : ")) {
			tempObj.lastName = clsSharedStudentsFunctions::_readStudentLastName();
		}
	}
public:
	static void showUpdateStudentFullNameScreen() {

		showMainHeader("      Update Student`s Full Name Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Full Name !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		_readStudentFullName(student);

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s full name [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s full name updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s full name .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};





