#pragma once
#include"clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
#include "clsStudentsMenue.h"
#include "clsTeachersMenue.h"
#include "clsClassesMenue.h"
#include "clsGradesMenue.h"
class clsMainMenue: public clsHeaderScreen , public clsMenue {
private:
	enum enMainMenueOperation {
		StudentsMenue = 1,
		TeachersMenue,
		ClassesMenue,
		GradesMenue,
		LogOut
	};

	static void _showStudentsMenue() {
		clsStudentsMenue::showMenue();
	}
	static void _showTeachersMenue() {
		clsTeachersMenue::showMenue();
	}
	static void _showClassesMenue() {
		clsClassesMenue::showMenue();
	}
	static void _showGradesMenue() {
		clsGradesMenue::showMenue();
	}
	static void _logOut() {
		cout << " Log Out From The System\n\n";
		return;
	}

	static void _backToMenue() {
		cout << "\n\n Press Any Key To Back To The Main menue\n";
		system(" pause>0");
		showMenue();
	}
	static enMainMenueOperation _readMainMenueOption() {
		cout << " Please enter a choice [ 1 - 5 ] : ";
		return (enMainMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 5);
	}

	static void _performMainMenueOperation(enMainMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enMainMenueOperation::StudentsMenue: {
			_showStudentsMenue();
			showMenue();
			break;
		}
		case enMainMenueOperation::TeachersMenue: {
			_showTeachersMenue();
			showMenue();
			break;
		}
		case enMainMenueOperation::ClassesMenue: {
			_showClassesMenue();
			showMenue();
			break;

		}
		case enMainMenueOperation::GradesMenue: {
			_showGradesMenue();
			showMenue();
			break;
		}
		case enMainMenueOperation::LogOut: {
			_logOut();
			return;
		}
		}
		
	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "       ";

		showMainHeader(Tabs + "       Main Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] Students Menue.\n";
		cout << Tabs << "[02] Teachers Menue.\n";
		cout << Tabs << "[03] Classes Menue.\n";
		cout << Tabs << "[04] Grades Menue.\n";
		cout << Tabs << "[05] Log out.\n";
		cout << LineSperator <<"\n";

		_performMainMenueOperation(_readMainMenueOption());
	}
};

