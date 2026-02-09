#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsFindStudentScreen:public clsHeaderScreen
{

public :
	static void showFindStudentScreen() {
		showMainHeader("\t     Find Student Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Find !! ";
			return;
		}
		string studentID = clsInputValidate::ReadOneWord("\nEnter student ID : ");
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID(studentID);
		if (student.isEmpty()) {
			cout << "Student with ID [" << studentID << "] is not exists\n";
		}
		else {
			clsSharedStudentsFunctions::_printStudentInfoCard(student);
		}
	}
};

