#pragma once
#include "clsMenue.h"
#include "clsHeaderScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
class clsAddTeacherMenueScreen:protected clsHeaderScreen, public clsMenue
{
private:
	enum enAddTeacherMenueOperation {
		AddNewTeacher = 1,
		AddOldTeacher,
		BackToTeacherMenue
	};
	static enAddTeacherMenueOperation _readAddTeacherMenueOperation() {
		cout << " Please enter a choice [ 1 - 3 ] : ";
		return (enAddTeacherMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 3);
	}
	static void _backToMenue() {
		cout << "\n\nPress Any Key To Back To The Add Teacher Menue\n";
		system(" pause>0");
		showMenue();
	}
	static void _addNewTeacher() {

	}
	static void _addOldTeacher() {

	}

	static void _performAddTeacherMenueOperation(enAddTeacherMenueOperation userOption) {

		switch (userOption) {
		case enAddTeacherMenueOperation::AddNewTeacher: {
			_addNewTeacher();
			_backToMenue();
			break;
		}

		case enAddTeacherMenueOperation::AddOldTeacher: {
			_addOldTeacher();
			_backToMenue();
			break;
		}

		case enAddTeacherMenueOperation::BackToTeacherMenue:{
			return;
		}
		}
	}
public:
	static  void showMenue() {
		string Tabs = "     ";
		string LineSperator = "=============================================";
		showMainHeader("\tAdd New Teacher`s Menue Screen");
	
		cout << LineSperator << endl;
		cout << Tabs << "[01] Add New Teacher.\n";
		cout << Tabs << "[02] Add Old Teacher.\n";
		cout << Tabs << "[03] Back To Teachers Menue.\n";
		cout << LineSperator << endl;
		_performAddTeacherMenueOperation(_readAddTeacherMenueOperation());
	}
};

