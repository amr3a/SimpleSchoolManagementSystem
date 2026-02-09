#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
class clsClassesMenue:public clsHeaderScreen,public clsMenue
{
private:
	enum enClassMenueOperation {
		FristClass = 1,
		SecondClass,
		ThirdClass,
		FourthClass,
		FifthClass,
		SixthClass,
		SeventhClass,
		EighthClass,
		NinthClass,
		FristSecondaryClass,
		SecondSecondaryClass,
		ThirdSecondaryClass,
		BackToMainMenue
	};

	static void _showFristClass() {
		showMainHeader("\tFrist Class Screen");
		cout << " Show Frist Class\n\n";
	}
	static void _showSecondClass() {
		showMainHeader("\tSecond Class Screen");
		cout << " Show Second Class\n\n";
	}
	static void _showThirdClass() {
		showMainHeader("\tThird Class Screen");
		cout << " Show Third Class\n\n";
	}
	static void _showFourthClass() {
		showMainHeader("\tFourth Class Screen");
		cout << " Show Fourth Class\n\n";
	}
	static void _showFifthClass() {
		showMainHeader("\tFifth Class Screen");
		cout << " Show Fifth Class\n\n";
	}
	static void _showSixthClass() {
		showMainHeader("\tSixth Class Screen");
		cout << " Show Sixth Class\n\n";
	}
	static void _showSeventhClass() {
		showMainHeader("\tSeventh Class Screen");
		cout << " Show Seventh Class\n\n";
	}
	static void _showEighththClass() {
		showMainHeader("\tEighth Class Screen");
		cout << " Show Eighth Class\n\n";
	}
	static void _showNinthClass() {
		showMainHeader("\tNinth Class Screen");
		cout << " Show Ninth Class\n\n";
	}
	static void _showFristSecondaryClass() {
		showMainHeader("  Frist Secondary Class Screen");
		cout << " Show Frist Secondary Class\n\n";
	}
	static void _showSecondSecondaryClass() {
		showMainHeader("  Second Secondary Class Screen");
		cout << " Show Second Secondary Class\n\n";
	}
	static void _showThirdSecondaryClass() {
		showMainHeader("  Third Secondary Class Screen");
		cout << " Show Third Secondary Class\n\n";
	}

	static void _backToMenue() {
		cout << "\n\n Press Any Key To Back To The Classes Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enClassMenueOperation _readClassMenueOption() {
		cout << " Please enter a choice [ 1 - 13 ] : ";
		return (enClassMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 13);
	}

	static void _performClassMenueOperation(enClassMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enClassMenueOperation::FristClass: {
			_showFristClass();
			_backToMenue();
			break;
		}
		case enClassMenueOperation::SecondClass: {
			_showSecondClass();
			_backToMenue();
			break;
		}
		case enClassMenueOperation::ThirdClass: {
			_showThirdClass();
			_backToMenue();
			break;

		}
		case enClassMenueOperation::FourthClass: {
			_showFourthClass();
			_backToMenue();
			break;
		}
		case enClassMenueOperation::FifthClass: {
			_showFifthClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::SixthClass: {
			_showSixthClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::SeventhClass: {
			_showSeventhClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::EighthClass: {
			_showEighththClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::NinthClass: {
			_showNinthClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::FristSecondaryClass: {
			_showFristSecondaryClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::SecondSecondaryClass: {
			_showSecondSecondaryClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::ThirdSecondaryClass: {
			_showThirdSecondaryClass();
			_backToMenue();
			return;
		}
		case enClassMenueOperation::BackToMainMenue: {

			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "     ";

		showMainHeader(Tabs + " Classes Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] Frist Class.\n";
		cout << Tabs << "[02] Second Class.\n";
		cout << Tabs << "[03] Third Class.\n";
		cout << Tabs << "[04] Fourth Class.\n";
		cout << Tabs << "[05] Fifth Class.\n";
		cout << Tabs << "[06] Sixth Class.\n";
		cout << Tabs << "[07] Seventh Class.\n";
		cout << Tabs << "[08] Eighth Class.\n";
		cout << Tabs << "[09] Nineth Class.\n";
		cout << Tabs << "[10] Frist Secondary Class.\n";
		cout << Tabs << "[11] Second Secondary Class.\n";
		cout << Tabs << "[12] Third Secondary Class.\n";
		cout << Tabs << "[13] Main Menue.\n";
		cout << LineSperator << "\n";

		_performClassMenueOperation(_readClassMenueOption());
	}
};

