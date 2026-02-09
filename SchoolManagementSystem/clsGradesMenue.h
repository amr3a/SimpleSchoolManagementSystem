#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
class clsGradesMenue: public clsHeaderScreen, public clsMenue {

private:
	enum enGradesMenueOperation {
		AddingGradesForClass = 1,
		UpdateGradesForClass,
		DeleteGradesForClass,
		ShowGradesForClass,
		AddingGradesForStudent,
		UpdateGradesForStudent,
		DeleteGradesForStudent,
		ShowGradesForStudent,
		BackToMainMenue
	};

	static void _showAddingGradesForClass() {
		showMainHeader("  Adding Class`s Grades Screen");
		cout << " Show Adding Class`s Grades\n\n";
	}
	static void _showUpdateGradesForClass() {
		showMainHeader("   Update Class`s Grades Screen");
		cout << " Show Delete Class`s Grades\n\n";
	}
	static void _showDeleteGradesForClass() {
		showMainHeader("   Delete Class`s Grades Screen");
		cout << " Show Update Class`s Grades\n\n";
	}
	static void _showShowGradesForClass() {
		showMainHeader("    Show Class`s Grades Screen");
		cout << " Show Class`s Grades\n\n";
	}
	static void _showAddingGradesForStudent() {
		showMainHeader(" Adding Student`s Grades Screen");
		cout << " Show Adding Student Grades\n\n";
		return;
	}
	static void _showUpdateGradesForStudent() {
		showMainHeader(" Update Student`s Grades Screen");
		cout << " Show Update Student Grades\n\n";
		return;
	}
	static void _showDeleteGradesForStudent() {
		showMainHeader("  Delete Student`s Grades Screen");
		cout << " Show Delete Student Grades\n\n";
		return;
	}
	static void __showShowGradesForStudent() {
		showMainHeader("  Show Student`s Grades Screen");
		cout << " Show Student Grades\n\n";
		return;
	}

	static void _backToMenue() {
		cout << "\n\n Press Any Key To Back To The Grades Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enGradesMenueOperation _readGradesMenueOption() {
		cout << " Please enter a choice [ 1 - 9 ] : ";
		return (enGradesMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 9);
	}

	static void _performGradesMenueOperation(enGradesMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enGradesMenueOperation::AddingGradesForClass: {
			_showAddingGradesForClass();
			_backToMenue();
			break;
		}
		case enGradesMenueOperation::UpdateGradesForClass: {
			_showUpdateGradesForClass();
			_backToMenue();
			break;
		}
		case enGradesMenueOperation::DeleteGradesForClass: {
			_showDeleteGradesForClass();
			_backToMenue();
			break;

		}
		case enGradesMenueOperation::ShowGradesForClass: {
			_showShowGradesForClass();
			_backToMenue();
			break;
		}
		case enGradesMenueOperation::AddingGradesForStudent: {
			_showAddingGradesForStudent();
			_backToMenue();
			return;
		}
		case enGradesMenueOperation::UpdateGradesForStudent: {
			_showUpdateGradesForStudent();
			_backToMenue();
			return;
		}
		case enGradesMenueOperation::DeleteGradesForStudent: {
			_showDeleteGradesForStudent();
			_backToMenue();
			return;
		}
		case enGradesMenueOperation::ShowGradesForStudent: {
			__showShowGradesForStudent();
			_backToMenue();
			return;
		}
		case enGradesMenueOperation::BackToMainMenue: {

			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "    ";

		showMainHeader(Tabs + " Grades Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] Adding Class`sGrades.\n";
		cout << Tabs << "[02] Update Class`s Grades.\n";
		cout << Tabs << "[03] Delete Class`s Grades.\n";
		cout << Tabs << "[04] Show Class`s Grades.\n";
		cout << Tabs << "[05] Adding Student`s Grades.\n";
		cout << Tabs << "[06] Update Student`s Grades.\n";
		cout << Tabs << "[07] Delete Student`s Grades.\n";
		cout << Tabs << "[08] Show Student`s Grades.\n";
		cout << Tabs << "[09] Main Menue.\n";
		cout << LineSperator << "\n";

		_performGradesMenueOperation(_readGradesMenueOption());
	}
};

