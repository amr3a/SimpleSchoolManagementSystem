#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
#include "clsUpdateStudentFullNameMenue.h"
#include "clsUpdateStudentBrithdateScreen.h"
#include "clsUpdateStudentStatusScreen.h"
#include "clsUpdateStudentAddressMenue.h"
#include "clsUpdateStudentPhoneNumberScreen.h"
#include "clsUpdateStudentClassScreen.h"
#include "clsUpdateStudentRegestrationDateScreen.h"
#include "clsUpdateStudentNoteScreen.h"

class clsUpdateStudentMenue:public clsHeaderScreen , public clsMenue
{
private:
	enum enUpdateStudentMenueOperation {
		UpdateStudentFullName = 1,
		UpdateStudentBrithdate,
		UpdateStudentAddress,
		UpdateStudentPhoneNumber,
		UpdateStudentClass,
		UpdateStudentRegestraionDate,
		UpdateStudentStatus,
		UpdateStudentNote,
		BackToStudentsMenue
	};

	static void _showUpdateStudentFullNameScreen() {
		clsUpdateStudentFullNameMenue::showMenue();
	}
	static void _showUpdateStudentBrithdateScreen() {
		clsUpdateStudentBrithdateScreen::showUpdateStudentBrithdateScreen();
	}
	static void _showUpdateStudentAddressScreen() {
		clsUpdateStudentAddressMenue::showMenue();
	}
	static void _showUpdateStudentPhoneNumberScreen() {
		clsUpdateStudentPhoneNumberScreen::showUpdateStudentPhoneNumberScreen();
	}
	static void _showUpdateStudentClassScreen() {
		clsUpdateStudentClassScreen::showUpdateStudentClassScreen();
		return;
	}
	static void _showUpdateStudentRegestraionDate() {
		clsUpdateStudentRegestrationDateScreen::showUpdateStudentRegestrationDateScreen();
		return;
	}
	static void _showUpdateUpdateStudentStatusScreen() {
		
		clsUpdateStudentStatusScreen::showUpdateStudentStatusScreen();
		return;
	}
	static void _showUpdateStudentNoteScreen() {
		clsUpdateStudentNoteScreen::showUpdateStudentNoteScreen();
		return;
	}
	static void _backToMenue() {
		cout << "\n\nPress Any Key To Back To The Update Student Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enUpdateStudentMenueOperation _readUpdateStudentMenueOption() {
		cout << "Please enter a choice [ 1 - 9 ] : ";
		return (enUpdateStudentMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 9);
	}

	static void _performUpdateStudentMenueOperation(enUpdateStudentMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enUpdateStudentMenueOperation::UpdateStudentFullName: {
			_showUpdateStudentFullNameScreen();
			showMenue();
			break;
		}
		case enUpdateStudentMenueOperation::UpdateStudentBrithdate: {
			_showUpdateStudentBrithdateScreen();
			_backToMenue();
			break;
		}
		case enUpdateStudentMenueOperation::UpdateStudentAddress: {
			_showUpdateStudentAddressScreen();
			showMenue();
			break;

		}
		case enUpdateStudentMenueOperation::UpdateStudentPhoneNumber: {
			_showUpdateStudentPhoneNumberScreen();
			_backToMenue();
			break;
		}
		case enUpdateStudentMenueOperation::UpdateStudentClass: {
			_showUpdateStudentClassScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentMenueOperation::UpdateStudentRegestraionDate: {
			_showUpdateStudentRegestraionDate();
			_backToMenue();
			return;
		}

		case enUpdateStudentMenueOperation::UpdateStudentStatus: {
			_showUpdateUpdateStudentStatusScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentMenueOperation::UpdateStudentNote: {
			_showUpdateStudentNoteScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentMenueOperation::BackToStudentsMenue: {

			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "     ";

		showMainHeader(Tabs + "   Update Student Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] Update Student`s Full Name.\n";
		cout << Tabs << "[02] Update Student`s Brithdate.\n";
		cout << Tabs << "[03] Update Student`s Address.\n";
		cout << Tabs << "[04] Update Student`s Phone Number.\n";
		cout << Tabs << "[05] Update Student`s Class.\n";
		cout << Tabs << "[06] Update Student`s Regestration Date.\n";
		cout << Tabs << "[07] Update Student`s Status.\n";
		cout << Tabs << "[08] Update Student`s Note.\n";
		cout << Tabs << "[09] Students Menue.\n";
		cout << LineSperator << "\n";

		_performUpdateStudentMenueOperation(_readUpdateStudentMenueOption());
	}
};

