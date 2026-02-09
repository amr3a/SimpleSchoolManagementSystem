#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
#include "clsAddNewStudentScreen.h"
#include "clsShowAllStudentsScreen.h"
#include "clsUpdateStudentMenue.h"
#include "clsDeleteStudentScreen.h"
#include "clsFindStudentScreen.h"

class clsStudentsMenue:public clsHeaderScreen , public clsMenue {
private:
	enum enStudentMenueOperation {
		ListStudents = 1,
		AddNewStudent,
		UpdateStudentInfo,
		DeleteStudent,
		FindStudent,
		BackToMainMenue
	};

	static void _showListAllStudents() {
		clsShowAllStudentsScreen::showAllStudents();
	}
	static void _showAddStudent() {
		clsAddNewStudentScreen::_addStudentScreen();
	}
	static void _showUpdateStudent() {
		clsUpdateStudentMenue::showMenue();
	}
	static void _showDeleteStudent() {
	
		clsDeleteStudentScreen::showDeleteStudentScreen();
	}
	static void _showFindStudent() {
		clsFindStudentScreen::showFindStudentScreen();
		return;
	}


	static void _backToMenue() {
		cout << "\n\nPress Any Key To Back To The Students Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enStudentMenueOperation _readStudentMenueOption() {
		cout << "Please enter a choice [ 1 - 6 ] : ";
		return (enStudentMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 6);
	}

	static void _performStudentMenueOperation(enStudentMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enStudentMenueOperation::ListStudents: {
			_showListAllStudents();
			_backToMenue();
			break;
		}
		case enStudentMenueOperation::AddNewStudent: {
			_showAddStudent();
			_backToMenue();
			break;
		}
		case enStudentMenueOperation::UpdateStudentInfo: {
			_showUpdateStudent();
			showMenue();
			break;

		}
		case enStudentMenueOperation::DeleteStudent: {
			_showDeleteStudent();
			_backToMenue();
			break;
		}
		case enStudentMenueOperation::FindStudent: {
			_showFindStudent();
			_backToMenue();
			return;
		}
		case enStudentMenueOperation::BackToMainMenue: {
			
			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "    ";

		showMainHeader(Tabs + "       Students Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] List All Students.\n";
		cout << Tabs << "[02] Add Student.\n";
		cout << Tabs << "[03] Update Student.\n";
		cout << Tabs << "[04] Delete Student.\n";
		cout << Tabs << "[05] Find Student.\n";
		cout << Tabs << "[06] Main Menue.\n";
		cout << LineSperator << "\n";

		_performStudentMenueOperation(_readStudentMenueOption());
	}


};

