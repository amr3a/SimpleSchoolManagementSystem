#pragma once
#include"clsDate.h"
class clsInputValidate {

public:

	 template <class T> static T ReadNumber(string Message, string alternativeMessage) {

		T num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	 template <class T> static T ReadNumber(string alternativeMessage = "InValid input, Enter again :") {

		 T num = 0;


		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static bool ReadBoolen(string Message, string alternativeMessage) {

		bool num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	static bool ReadBoolen(string alternativeMessage = "InValid input, Enter again :") {

		bool num = 0;


		cin >> num;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static char ReadCharacter(string Message, string alternativeMessage) {

		char Char = ' ';

		cout << Message;
		cin >> Char;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}
	static char ReadCharacter(string alternativeMessage = "InValid input, Enter again :") {

		char Char = ' ';


		cin >> Char;

		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}

	static string ReadString(string Message) {

		string sString = "";

		cout << Message;
		getline(cin >> ws, sString);

		return sString;
	}
	static string ReadString() {

		string sString = "";
		getline(cin >> ws, sString);

		return sString;
	}

	static string ReadOneWord(string Message) {
		string sString = "";

		cout << Message;
		cin >> sString;

		return sString;
	}
	static string ReadOneWord() {
		string sString = "";
		cin >> sString;

		return sString;
	}

	template <class T> static T ReadNumberBetween(string Message, string alternativeMessage, int From, int To) {

		T num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || !(num >= From && num <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	template <class T> static T ReadNumberBetween(int From, int To, string alternativeMessage = "InValid input, Enter again :") {

		T num = 0;
		cin >> num;

		while (cin.fail() || !(num >= From && num <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}

	static char ReadCharacterBetween(string Message, string alternativeMessage, char From, char To) {

		char Char = 0;

		cout << Message;
		cin >> Char;

		while (cin.fail() || !(Char >= From && Char <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}
	static char ReadCharacterBetween(char From, char To, string alternativeMessage = "InValid input, Enter again :") {

		char Char = 0;
		cin >> Char;

		while (cin.fail() || !(Char >= From && Char <= To)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> Char;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return Char;
	}

	template <class T> static T ReadPositiveNumber(string Message, string alternativeMessage = "InValid Input, Please enter valid input :") {


		T num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num <= 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	template <class T> static T ReadPositiveNumber() {

		T num = 0;

		string alternativeMessage = "InValid Input, Please enter valid input :";

		cin >> num;

		while (cin.fail() || (num <= 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}


	template <class T> static T ReadNegtiveNumber(string Message, string alternativeMessage = "InValid Input, Please enter valid input :") {


		T num = 0;

		cout << Message;
		cin >> num;

		while (cin.fail() || (num > 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}
	template <class T> static T ReadNegtiveNumber( ) {

		T num = 0;

		string alternativeMessage = "InValid Input, Please enter valid input :";

		cin >> num;

		while (cin.fail() || (num > 0)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << alternativeMessage;
			cin >> num;
		}

		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		return num;
	}



	static bool IsNumberBetween(int Num, int From, int To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(float Num, float From, float To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(short Num, short From, short To) {
		return (Num >= From && Num <= To);
	}
	static bool IsNumberBetween(double Num, double From, double To) {
		return (Num >= From && Num <= To);
	}
	static bool IsCharacterBetween(char Char, char From, char To) {
		return (Char >= From && Char <= To);
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To) {
		if (Date >= From && Date <= To) {
			return true;
		}
		if (Date >= To && Date <= From) {
			return true;
		}
		return false;
	}
	static bool IsValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}
	static bool CheckAnswer(string Message) {
		char YourAnswer = ReadCharacter(Message, "Invalid Input, Please valid input : ");
		return (toupper(YourAnswer) == 'Y');
	}
	static clsDate ReadDate() {

		clsDate Date;
		string alternativeMassage = "InValid Input, Please enter valid input : ";

		Date.year = ReadPositiveNumber<short>("Enter year : ", alternativeMassage);
		Date.month = ReadPositiveNumber<short>("Enter month : ", alternativeMassage);
		while (!Date.isMonth()) {
			Date.month = ReadPositiveNumber<short>("Enter a valid month : ", alternativeMassage);
		}
		Date.day = ReadPositiveNumber<short>("Enter day : ");
		while (!Date.isDayWithInMonth()) {
			Date.day = ReadPositiveNumber<short>("Enter a valid day : ", alternativeMassage);
		}

		return Date;
	}
	static clsDate ReadDateBetween(clsDate From, clsDate To, string AlternativeMessage = "The Date you entered is not allowed ..") {
		clsDate Date = clsInputValidate::ReadDate();
		while (!clsInputValidate::IsDateBetween(Date, From, To)) {
			cout << AlternativeMessage << "\n";
			Date = clsInputValidate::ReadDate();
		}

		return Date;
	}

};

