#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
class clsTeachersMenue:public clsHeaderScreen,public clsMenue {
private:
	enum enTeacherMenueOperation {
		ListTeachers= 1,
		AddNewTeacher,
		UpdateTeacherInfo,
		DeleteTeacher,
		FindSTeacher,
		UpdateTeacherSubjects,
		BackToMainMenue
	};

	static void _showListAllTeachers() {
		
		cout << " Show List All Teachers\n\n";
	}
	static void _showAddNewTeacher() {
		showMainHeader("      Add New Teacher Screen");
		cout << " Show Add New Teacher\n\n";
	}
	static void _showUpdateTeacher() {
		showMainHeader("   Update Teacher Info Screen");
		cout << " Show Update Teacher\n\n";
	}
	static void _showDeleteTeacher() {
		showMainHeader("      Delete Teacher Screen");
		cout << " Show Delete Teacher\n\n";
	}
	static void _showFindTeacher() {
		showMainHeader("       Find Teacher Screen");
		cout << " Show Find Teacher\n\n";
		return;
	}
	static void _showUpdateTeacherStatus() {
		showMainHeader(" Update Teacher Subjects Screen");
		cout << " Show Update Teacher Status\n\n";
		return;
	}

	static void _backToMenue() {
		cout << "\n\n Press Any Key To Back To The Teachers Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enTeacherMenueOperation _readTeacherMenueOption() {
		cout << " Please enter a choice [ 1 - 7 ] : ";
		return (enTeacherMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 7);
	}

	static void _performTeacherMenueOperation(enTeacherMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enTeacherMenueOperation::ListTeachers: {
			_showListAllTeachers();
			_backToMenue();
			break;
		}
		case enTeacherMenueOperation::AddNewTeacher: {
			_showAddNewTeacher();
			_backToMenue();
			break;
		}
		case enTeacherMenueOperation::UpdateTeacherInfo: {
			_showUpdateTeacher();
			_backToMenue();
			break;

		}
		case enTeacherMenueOperation::DeleteTeacher: {
			_showDeleteTeacher();
			_backToMenue();
			break;
		}
		case enTeacherMenueOperation::FindSTeacher: {
			_showFindTeacher();
			_backToMenue();
			return;
		}
		case enTeacherMenueOperation::UpdateTeacherSubjects: {
			_showUpdateTeacherStatus();
			_backToMenue();
			return;
		}
		case enTeacherMenueOperation::BackToMainMenue: {

			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "    ";

		showMainHeader(Tabs + " Teachers Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] List All Teachers.\n";
		cout << Tabs << "[02] Add New Teacher.\n";
		cout << Tabs << "[03] Update Teacher.\n";
		cout << Tabs << "[04] Delete Teacher.\n";
		cout << Tabs << "[05] Find Teacher.\n";
		cout << Tabs << "[06] Update Teacher Subjects.\n";
		cout << Tabs << "[07] Main Menue.\n";
		cout << LineSperator << "\n";

		_performTeacherMenueOperation(_readTeacherMenueOption());
	}

};

