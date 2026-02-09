#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsUpdateStudentNoteScreen :public clsHeaderScreen
{
public:
	static void showUpdateStudentNoteScreen() {

		showMainHeader("         Update Student`s Note Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Update it`s Note !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);
		student.studentNote = clsSharedStudentsFunctions::_readStudentNote();

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to update student`s note [Y/N] : ")) {
			if (student.save()) {
				cout << "The student`s note updated successfully ..\n";
			}
			else {
				cout << "There was an issue to update student`s note .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}

};

