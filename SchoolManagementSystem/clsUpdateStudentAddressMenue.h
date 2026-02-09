#pragma once
#pragma once
#include "clsHeaderScreen.h"
#include "clsMenue.h"
#include "clsInputValidate.h"
#include "clsUpdateStudentNiegborhoodScreen.h"
#include "clsUpdateStudentDistrictScreen.h"
#include "clsUpdateStudentAddressScreen.h"
class clsUpdateStudentAddressMenue :public clsHeaderScreen, public clsMenue
{
private:
	enum enUpdateStudentAddressMenueOperation {
		UpdateStudentNieghborhood = 1,
		UpdateStudentDistrict,
		UpdateStudentAddress,
		BackToUpdateStudentMenue,

	};
	static void showUpdateStudentNieghborhoodScreen() {
		clsUpdateStudentNiegborhoodScreen::showUpdateStudentNiegborhoodScreen();
	}
	static void showUpdateStudentDistrictScreen() {
		clsUpdateStudentDistrictScreen::showUpdateStudentDistrictScreen();
		return;
	}
	static void _showUpdateStudentAddressScreen() {
		clsUpdateStudentAddressScreen::showUpdateStudentAddressScreen();
		return;
	}
	static void _backToMenue() {
		cout << "\n\nPress Any Key To Back To The Update Student`s Address Menue\n";
		system(" pause>0");
		showMenue();
	}
	static enUpdateStudentAddressMenueOperation _readUpdateStudentAddressMenueOption() {
		cout << "Please enter a choice [ 1 - 7 ] : ";
		return (enUpdateStudentAddressMenueOperation)clsInputValidate::ReadNumberBetween<short>(1, 7);
	}

	static void _performUpdateStudentAddressMenueOperation(enUpdateStudentAddressMenueOperation UserOption) {
		system("cls");
		switch (UserOption) {
		case enUpdateStudentAddressMenueOperation::UpdateStudentNieghborhood: {
			showUpdateStudentNieghborhoodScreen();
			_backToMenue();
			break;
		}
		case enUpdateStudentAddressMenueOperation::UpdateStudentDistrict: {
			showUpdateStudentDistrictScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentAddressMenueOperation::UpdateStudentAddress: {
			_showUpdateStudentAddressScreen();
			_backToMenue();
			return;
		}
		case enUpdateStudentAddressMenueOperation::BackToUpdateStudentMenue: {

			return;
		}
		}

	}
public:
	static void showMenue() {
		system("cls");
		string Tabs = "   ";

		showMainHeader(Tabs + " Update Student`s Address Menue Screen");

		string LineSperator = "=============================================";
		cout << LineSperator << "\n";
		cout << Tabs << "[01] Update Student`s Niegborhood Name.\n";
		cout << Tabs << "[02] Update Student`s District Name.\n";
		cout << Tabs << "[03] Update Student`s Address.\n";
		cout << Tabs << "[04] Back To Update Student Menue.\n";

		cout << LineSperator << "\n";

		_performUpdateStudentAddressMenueOperation(_readUpdateStudentAddressMenueOption());
	}
};



