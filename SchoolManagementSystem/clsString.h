#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class clsString
{
private:
	enum enTypeOfCount {

		AllLetters = 0,
		Spaces = 1,
		Punctation = 2,
		LowerCase = 3,
		UpperCase = 4,
		Vowel = 5
	};

	string _value;

	

public:

	clsString() {
		this->_value = "";
	}
	clsString(string value) {
		this->_value = value;
	}
	void setValue(string value) {
		this->_value = value;
	}
	string getValue() const {
		return this->_value;
	}

	__declspec(property(get = getValue, put = setValue)) string value;

	static short Length(string s1) {
		return (short)s1.length();
	}
	short Length() {
		return (short)_value.length();
	}

	static void PrintFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;
		cout << "\nFirst letters of this string: \n";

		for (unsigned short i = 0; i < (unsigned short)S1.length(); i++) {
			if (S1[i] != ' ' && isFirstLetter) {
				cout << S1[i] << endl;
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}
	}
	 void PrintFirstLetterOfEachWord() {
		PrintFirstLetterOfEachWord(this->value);
	}

	 static string UpperFirstLetterOfEachWordTheRestIsSmall(string S1) {
		 bool isFirstLetter = true;

		 for (unsigned short i = 0; i < S1.length(); i++) {
			 if (S1[i] != ' ' && isFirstLetter) {
				 S1[i] = toupper(S1[i]);
			 }
			 else
				 S1[i] = tolower(S1[i]);

			 isFirstLetter = (S1[i] == ' ' ? true : false);
		 }

		 return S1;
	 }
	 void UpperFirstLetterOfEachWordTheRestIsSmall() {
		 _value = UpperFirstLetterOfEachWordTheRestIsSmall(_value);

	 }


	static string UpperFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;

		for (unsigned short i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ' && isFirstLetter) {
				S1[i] = toupper(S1[i]);
			}
			
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
	void UpperFirstLetterOfEachWord() {
		_value = UpperFirstLetterOfEachWord(_value);

	}

	static string LowerFirstLetterOfEachWord(string S1) {
		bool isFirstLetter = true;

		for (unsigned short i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ' && isFirstLetter) {
				S1[i] = tolower(S1[i]);
			}
			isFirstLetter = (S1[i] == ' ' ? true : false);
		}

		return S1;
	}
	 void LowerFirstLetterOfEachWord() {
		_value = LowerFirstLetterOfEachWord(_value);

	}

	static string UpperCaseString(string String) {
		for (short i = 0; i < (signed)String.length(); i++) {

			if ((String[i] >= 'A' && String[i] <= 'Z') || (String[i] >= 'a' && String[i] <= 'z'))
				String[i] = toupper(String[i]);
		}
		return String;
	}
	 void UpperCaseString() {
		_value = UpperCaseString(_value);
	}

	static string lowerCaseString(string String) {
		for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

			if ((String[i] >= 'A' && String[i] <= 'Z') || (String[i] >= 'a' && String[i] <= 'z'))
				String[i] = tolower(String[i]);
		}

		return String;
	}
	void lowerCaseString() {
		_value = lowerCaseString(_value);

	}

	static char  InvertLetterCase(char char1) {
		return isupper(char1) ? tolower(char1) : toupper(char1);
	}

	static string  InvertAllLettersCase(string S1) {
		for (unsigned short i = 0; i < S1.length(); i++)
		{
			S1[i] = InvertLetterCase(S1[i]);
		}
		return S1;
	}
	void  InvertAllLettersCase() {
		_value = InvertAllLettersCase(_value);

	}

	static short  NumberOfCapitalLettersInString(string String) {
		short NumberOfCapitalLetters = 0;
		for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {
			if (isupper(String[i])) {
				NumberOfCapitalLetters++;
			}
		}

		return NumberOfCapitalLetters;
	}
	short NumberOfCapitalLettersInString() {
		return this->NumberOfCapitalLettersInString(this->_value);
	}

	static short NumberOfSmallLettersInString(string String) {
		short NumberOfSmallLetters = 0;
		for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {
			if (islower(String[i])) {
				NumberOfSmallLetters++;
			}
		}

		return NumberOfSmallLetters;
	}
	short NumberOfSmallLettersInString() {
		return this->NumberOfSmallLettersInString(this->_value);
	}

	static short CountLetters(string String, enTypeOfCount TypeOfCount) {
		short counter = 0;

		switch (TypeOfCount) {

		case enTypeOfCount::Spaces:
			for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

				if (isspace(String[i])) {
					counter++;
				}
			} break;
		case enTypeOfCount::Punctation:
			for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

				if (ispunct(String[i])) {
					counter++;
				}
			}break;
		case enTypeOfCount::LowerCase:
			for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

				if (islower(String[i])) {
					counter++;
				}
			}break;
		case  enTypeOfCount::UpperCase:
			for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

				if (isupper(String[i])) {
					counter++;
				}
			}break;
		case  enTypeOfCount::Vowel:
			for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

				if (IsVowel(String[i])) {
					counter++;
				}
			}break;
		default: return (short)String.length();
		}


		return counter;

	}
	short CountLetters(short TypeOfCount) {

		if (TypeOfCount < 0 || TypeOfCount > 5) {
			return 0;
		}

		return this->CountLetters(this->value, enTypeOfCount(TypeOfCount));
	}

	static short CountLetter(string S1, char Letter, bool MatchCase) {
		short Counter = 0;

		for (unsigned short i = 0; i < S1.length(); i++) {
			if (MatchCase) {
				if (S1[i] == Letter)
					Counter++;
			}
			else {
				if (tolower(S1[i]) == tolower(Letter))
					Counter++;
			}
		}


		return Counter;
	}
	short CountLetter(char Letter, bool MatchCase) {
		return this->CountLetter(this->value, Letter, MatchCase);
	}

	static bool IsVowel(char Letter) {
		Letter = tolower(Letter);
		return (
			(Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u')
			);
	}

	static short  CountVowels(string S1) {
		short Counter = 0;

		for (unsigned short i = 0; i < S1.length(); i++) {
			if (IsVowel(S1[i]))
				Counter++;
		}

		return Counter;
	}
	short  CountVowels() {
		return this->CountVowels(this->value);
	}

	static void PrintVowels(string String) {
		cout << "\nThe Vowels Letters in String : ";
		for (unsigned short i = 0; i < (unsigned short)String.length(); i++) {

			if (IsVowel(String[i])) {
				cout << String[i] << " ";
			}
		}


	}
	void PrintVowels() {
		PrintVowels(value);
	}

	static void  PrintEachWordInString(string S1) {
		string delim = " "; // delimiter
		cout << "\nYour string words are: \n\n";

		size_t pos = 0;
		string sWord; // define a string variable

		// use find() function to get the position of the delimiters
		while ((pos = S1.find(delim)) != std::string::npos) {
			sWord = S1.substr(0, pos); // store the word

			if (sWord != "") {
				cout << sWord << endl;
			}

			S1.erase(0, pos + delim.length()); // erase() until position and move to next word
		}

		if (S1 != "") {
			cout << S1 << endl; // print the last word of the string
		}
	}
	void  PrintEachWordInString() {
		PrintEachWordInString(this->value);
	}

	static short CountWords(string sString, string sDelimeter) {
		string sWord = "";
		size_t index = 0;
		short Counter = 0;
		while ((index = sString.find(sDelimeter)) != sString.npos)
		{
			sWord = sString.substr(0, index);
			if (sWord != "") {
				Counter++;
			}
			sString.erase(0, index + sDelimeter.length());
		}
		if (sString != "") {
			Counter++;
		}

		return Counter;
	}
	short CountWords(string sDelimeter) {
		return this->CountWords(this->value, sDelimeter);
	}

	static vector<string> SpilitString(string sString, string sDelimeter) {
		vector<string> vWords;
		string sWords = "";
		size_t pos = 0;
		while ((pos = sString.find(sDelimeter)) != sString.npos) {

			sWords = sString.substr(0, pos);
			if (sWords != "") {
				vWords.push_back(sWords);
			}

			sString.erase(0, pos + sDelimeter.length());
		}
		if (sString != "")
			vWords.push_back(sString);

		return vWords;

	}
	vector<string> SpilitString(string sDelimeter) {

		return SpilitString(this->value, sDelimeter);
	}

	static string TrimLeft(string S1) {
		for (unsigned short i = 0; i < S1.length(); i++) {
			if (S1[i] != ' ') {
				return S1.substr(i, S1.length() - i);
			}
		}
		return "";
	}
	void TrimLeft() {
		_value = TrimLeft(_value);

	}

	static string TrimRight(string S1) {
		for (short i = (short)S1.length() - 1; i >= 0; i--) {
			if (S1[i] != ' ') {
				return S1.substr(0, i + 1);
			}
		}
		return "";
	}
	void TrimRight() {
		_value = TrimRight(_value);

	}

	static string Trim(string S1) {
		return TrimLeft(TrimRight(S1));
	}
	void Trim() {
		_value = Trim(_value);

	}

	static string JoinStringInReverse(vector<string> vWords, string sDelimeter) {
		string sString = "";
		vector<string>::iterator iter = vWords.end();
		while (iter != vWords.begin()) {
			--iter;
			sString += (*iter + sDelimeter);
		}

		return sString.substr(0, sString.length() - sDelimeter.length());
	}

	static string JoinString(vector<string> vWords, string sDelimeter) {
		string sString = "";
		vector<string>::iterator iter = vWords.begin();
		while (iter != vWords.end()) {

			sString += (*iter + sDelimeter);
			++iter;
		}

		return sString.substr(0, sString.length() - sDelimeter.length());

	}

	static string JoinString(string arrString[], short Length, string Delim) {
		string S1 = "";

		for (short i = 0; i < Length; i++) {
			S1 = S1 + arrString[i] + Delim;
		}

		return S1.substr(0, S1.length() - Delim.length());
	}

	static string ReverseWordsInString(string S1) {
		vector<string> vString;
		string S2 = "";

		vString = SpilitString(S1, " ");

		vector<string>::iterator iter = vString.end();

		while (iter != vString.begin()) {
			--iter;
			S2 += *iter + " ";
		}

		S2 = S2.substr(0, S2.length() - 1);

		return S2;
	}
	void ReverseWordsInString() {

		_value = ReverseWordsInString(_value);

	}

	static string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo, string Delimeter, bool MatchCase) {
		vector<string> vString = SpilitString(S1, Delimeter);

		for (string& s : vString) {
			if (MatchCase) {
				if (s == StringToReplace) {
					s = sRepalceTo;
				}
			}
			else {
				if (lowerCaseString(s) == lowerCaseString(StringToReplace)) {
					s = sRepalceTo;
				}
			}
		}

		return JoinString(vString, " ");

	}
	void ReplaceWordInString(string StringToReplace, string sRepalceTo, string Delimeter, bool MatchCase) {
		_value = ReplaceWordInString(_value, StringToReplace, sRepalceTo, Delimeter, MatchCase);

	}

	static string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
	{
		size_t pos = S1.find(StringToReplace);

		while (pos != std::string::npos)
		{
			S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);

			pos = S1.find(StringToReplace);//find next     
		}
		return S1;
	}
	void ReplaceWordInString(string StringToReplace, string sRepalceTo) {
		_value = ReplaceWordInString(_value, StringToReplace, sRepalceTo);

	}

	static string RemovePunctuationsFromString(string S1) {
		string S2 = "";

		for (unsigned short i = 0; i < S1.length(); i++) {
			if (!ispunct(S1[i])) {
				S2 += S1[i];
			}
		}

		return S2;
	}
	void RemovePunctuationsFromString() {
		_value = RemovePunctuationsFromString(_value);

	}
	static 	bool isWordExistsInString(string String,string word ) {
		return String.find(word) != string::npos;
	}
	bool isWordExistsInString(string word) {
		return isWordExistsInString(this->_value, word);
	}
};

