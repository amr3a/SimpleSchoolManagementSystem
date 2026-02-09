#pragma once
#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
#include "clsUpdateStudentFirstNameScreen.h"
#include "clsUpdateStudentSecondNameScreen.h"
#include "clsUpdateStudentThirdNameScreen.h"
#include "clsUpdateStudentFourthNameScreen.h"
#include "clsUpdateStudentLastNameScreen.h"
#include "clsUpdateStudentFullNameScreen.h"
class clsUpdateStudentFullNameMenue:public clsHeaderScreen,public clsMenue
{
private:
	enum enUpdateStudentFullNameMenueOperation {
		UpdateStudentFirstName = 1,
		UpdateStudentSecondName,
		UpdateStudentThirdName,
		UpdateStudentFourthName,
		UpdateStudentLastName,
		UpdateStudentFullName,
		BackToUpdateStudentMenue,

	};
	static void _showUpdateStudentFirstNameScreen() {
		clsUpdateStudentFirstNameScreen::showUpdateStudentFirstNameScreen();
	}
	static void _showUpdateStudentSecondNameScreen() {
	
		clsUpdateStudentSecondNameScreen::showUpdateStudentSecondNameScreen();
		return;
	}
	static void _showUpdateStudentThirdNameScreen() {
		
		clsUpdateStudentThirdNameScreen::showUpdateStudentThirdNameScreen();
		return;
	}
	static void _showUpdateStudentFourthNameScreen() {
		clsUpdateStudentFourthNameScreen::showUpdateStudentFourthNameScreen();
		return;
	}
	static void _showUpdateStudentLastNameScreen() {
		clsUpdateStudentLastNameScreen::showUpdateStudentLastNameScreen();
		return;
	}
	static void _showUpdateStudentFullNameScreen() {
		
		clsUpdateStudentFullNameScreen::showUpdateStudentFullNameScreen();
		return;
	}
	static void _backToMenue() {
		cout << "\n\nPress Any Key To Back To The Update Student`s Full Name Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enUpdateStudentFullNameMenueOperation _readUpdateStudentFullNameMenueOption() {
		cout << "Please enter a choice [ 1 - 7 ] : ";
		return (enUpdateStudentFullNameMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 7);
	}

	static void _performUpdateStudentFullNameMenueOperation(enUpdateStudentFullNameMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enUpdateStudentFullNameMenueOperation::UpdateStudentFirstName: {
			_showUpdateStudentFirstNameScreen();
			_backToMenue();
			break;
		}
		case enUpdateStudentFullNameMenueOperation::UpdateStudentSecondName: {
			_showUpdateStudentSecondNameScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentFullNameMenueOperation::UpdateStudentThirdName: {
			_showUpdateStudentThirdNameScreen();
			_backToMenue();
			return;
		}

		case enUpdateStudentFullNameMenueOperation::UpdateStudentFourthName: {
			_showUpdateStudentFourthNameScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentFullNameMenueOperation::UpdateStudentLastName: {
			_showUpdateStudentLastNameScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentFullNameMenueOperation::UpdateStudentFullName: {
			_showUpdateStudentFullNameScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentFullNameMenueOperation::BackToUpdateStudentMenue: {

			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "     ";

		showMainHeader("   Update Student`s Full Name Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] Update Student`s Frist Name.\n";
		cout << Tabs << "[02] Update Student`s Second Name.\n";
		cout << Tabs << "[03] Update Student`s Third Name.\n";
		cout << Tabs << "[04] Update Student`s Fourth Name.\n";
		cout << Tabs << "[05] Update Student`s Last Name.\n";
		cout << Tabs << "[06] Update Student`s Full Name.\n";
		cout << Tabs << "[07] Back To Update Student Menue.\n";

		cout << LineSperator << "\n";

		_performUpdateStudentFullNameMenueOperation(_readUpdateStudentFullNameMenueOption());
	}
};



