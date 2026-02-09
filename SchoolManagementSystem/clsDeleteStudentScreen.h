#pragma once
#include "clsHeaderScreen.h"
#include "clsSharedStudentsFunctions.h"
class clsDeleteStudentScreen: public clsHeaderScreen
{
private:

public:
	static void showDeleteStudentScreen() {
		showMainHeader("\t     Delete Student Screen");
		if (clsStudents::isStudentFileEmpty()) {
			cout << "\nSorry, there is no students to Delete !! ";
			return;
		}
		clsStudents student = clsSharedStudentsFunctions::_readStudentByID();
		clsSharedStudentsFunctions::_printStudentInfoCard(student);

		if (clsInputValidate::CheckAnswer("\n\nAre you sure that you want to delete student`s data [Y/N] :")) {
			if (student.save(true)) {
				cout << "The student deleted successfully ..\n";
			}
			else {
				cout << "There was an issue to delete studnet .. \n";
			}
		}
		else {
			cout << "\nThe operation was canceled ... \n";
		}
	}
};

