#pragma once
#include "clsDate.h"
#include<ctime>
using namespace std;
class clsUtil {
	//* The utility library is about all functions 
	//  that are not belong to a specific library ..
public:

	enum enCharTayp {
		SmallLetter = 1, CapitalLetter = 2, SpecialCharacter =
		3, Digit = 4, MixChar = 5
	};


	static string EncryptText(string Text, short EncryptionKey)
	{
		// Text = Saeed 
		// EncryptionKey = 2  

		for (unsigned int i = 0; i <= Text.length(); i++)
		{

			Text[i] = char((int)Text[i] + EncryptionKey);
			// Text[i] == (int) Text[S] == Text[83] + 2 == (char) Text[85] << U[0]; 

		}
		return Text; // Ucggf 
	}
	static string DecryptionText(string Text, short EncryptionKey)
	{
		for (unsigned int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char((int)Text[i] - EncryptionKey);
			// Text[i] == (int) Text[U] == Text[85] - 2 == (char) Text[83] << S[0]; 

		}
		return Text;  // Saeed 
	}
	static void sRand() {

		srand((unsigned)time(NULL));
	}
	static int RandomNumber(int From, int To)
	{

		int RandNum = rand() % (To - From + 1) + From;
		// 87513 % "10" ( 10 - 1 +1 ) = 3 + 1 = 4 
		return RandNum; // 4 

	}
	static char GetRandomCharacter(enCharTayp CharType)
	{
		if (CharType == enCharTayp::MixChar) {

			CharType = (enCharTayp)RandomNumber(1, 4);

		}
		switch (CharType)
		{

		case enCharTayp::SmallLetter:
		{
			return char(RandomNumber(97, 122)); // char( 110 ) = n 
			break;
		}

		case enCharTayp::CapitalLetter:
		{
			return char(RandomNumber(65, 90));
			break;
		}

		case enCharTayp::SpecialCharacter:
		{
			return char(RandomNumber(33, 47));
			break;
		}

		case enCharTayp::Digit:
		{
			return char(RandomNumber(48, 57));
			break;
		}

		}
	}
	static string GenerateWord(enCharTayp CharType, short Length)
	{
		string Word;
		for (int i = 1; i <= Length; i++)  // 1 <= 4 ? | 2 <= 4 ... 
		{
			Word += GetRandomCharacter(CharType);
		}
		return Word;
	}
	static string GenerateKey(enCharTayp CharType, short Length)
	{
		string Key = "";
		Key = GenerateWord(CharType, Length) + "-";
		Key = Key + GenerateWord(CharType, Length) + "-";
		Key = Key + GenerateWord(CharType, Length) + "-";
		Key = Key + GenerateWord(CharType, Length);
		return Key;
	}
	static void GenerateKeys(short NumberOfKeys, enCharTayp CharType, short Length)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Kay [" << i << "] : " << GenerateKey(CharType, Length) << endl;
		}
	}
	static int CountRepeatedElementInArray(int Number, int arr[], int arrLength)
	{
		int Count = 0;
		for (int i = 0; i <= arrLength - 1; i++)
		{
			if (Number == arr[i])
				Count++;
		}
		return Count;
	}
	static void FillArrayWithRandomNumbers(int arr[], int arrLength, int From, int To)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = RandomNumber(From, To);
	}
	static void FillArrayWithRandomWords(string arr[], int arrLength, enCharTayp CharType, short Length)
	{
		for (int i = 0; i < arrLength; i++)
			arr[i] = GenerateWord(CharType, Length);
	}
	static int MaxNumberInArray(int arr[], int arrLength)
	{
		int Max = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > Max)
			{
				Max = arr[i];
			}
		}
		return Max;
	}
	static int MinNumberInArray(int arr[], int arrLength)
	{
		int Min = 0;
		Min = arr[0];

		for (int i = 1; i < arrLength; i++)
		{
			if (arr[i] < Min)
			{
				Min = arr[i];
			}
		}
		return Min;
	}
	static int SumArray(int arr[], int arrLength)
	{
		int Sum = 0;

		for (int i = 1; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}
	static float ArrayAverage(int arr[], int arrLength)
	{
		return (float)SumArray(arr, arrLength) / arrLength;
	}
	static void CopyArray(int arrSource[], int arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[i];
	}
	static void Swap(int& A, int& B)
	{
		int Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(float& A, float& B)
	{
		float Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static  void Swap(bool& A, bool& B)
	{
		bool Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(char& A, char& B)
	{
		char Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(double& A, double& B)
	{
		double Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(string& A, string& B)
	{
		string Temp;

		Temp = A;
		A = B;
		B = Temp;
	}
	static void Swap(clsDate& Date1, clsDate& Date2) {
		clsDate::SwapDates(Date1, Date2);
	}
	static void ShuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1,
				arrLength) - 1]);
		}
	}
	static void ShuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1,
				arrLength) - 1]);
		}
	}
	static void CopyArrayInReverseOrder(int arrSource[], int arrDestination[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
			arrDestination[i] = arrSource[arrLength - 1 - i];
		// arrDestination[0] = arrSource[5] | arrDestination[1] = arrSource[4] 

	}
	static void FillArrayWithKeys(string arr[], int arrLength, enCharTayp CharType, short Length)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey(CharType, Length);
		}
	}
	static short FindNumberPositionInArray(int Number, int arr[], int arrLength)
	{

		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == Number)
				return i;
		}
		return -1;
	}
	static void AddArrayElement(int Number, int arr[], int& arrLength)
	{ //its a new element so we need to add the length by 1 
		arrLength++;
		arr[arrLength - 1] = Number;
	}
	static bool IsNumberInArray(int Number, int arr[], int arrLength)
	{
		return FindNumberPositionInArray(Number, arr, arrLength) != -1;
	}
	static void CopyDistinactNumbersToArray(int arrSource[], int arrDestination[], int arrLength, int& arrDestinationLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			if (!IsNumberInArray(arrSource[i], arrDestination, arrLength))
			{
				AddArrayElement(arrSource[i], arrDestination,
					arrDestinationLength);
			}
		}
	}
	static bool IsPalindromeArray(int arr[100], int Length)
	{
		for (int i = 0; i < Length; i++)
		{
			if (arr[i] != arr[Length - i - 1])
			{
				return false;
			}
		}
		return true;
	}
	static string Tabs(short NumberOfTabs) {
		string sTab = "";
		for (short i = 1; i <= NumberOfTabs; i++) {
			sTab += "\t";
		}

		return sTab;
	}
	static string UnderScore(short NumberOfTabs) {
		string sTab = "";
		for (short i = 1; i <= NumberOfTabs; i++) {
			sTab += "_____";
		}

		return sTab;
	}
	static string NumberToText(long long Number) {

		if (Number == 0) {
			return "";
		}
		if (Number >= 1 && Number <= 19) {
			string aNumberInText[] = {
				"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve"
				,"Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
			};

			return aNumberInText[Number] + " ";
		}
		if (Number >= 20 && Number <= 99) {
			string aNumberInText[] = {
				"","","Twenty","Thrirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
			};

			return aNumberInText[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199) {
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999) {
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999) {
			return "One Thousnd " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999) {
			return NumberToText(Number / 1000) + "Thousnds " + NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999) {
			return "One Million " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 99999999) {
			return NumberToText(Number / 1000000) + "Milions " + NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999) {
			return "One Billion " + NumberToText(Number % 1000000000);
		}
		else {
			return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}
	}


};

