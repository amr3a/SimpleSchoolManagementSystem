#pragma once
#pragma warning(disable : 4996)
#include "clsString.h"
class clsDate {
private:
	short _day;
	short _month;
	short _year;
public:
	enum enDateCompare {
		Before = -1, Equal = 0, After
		= 1
	};
	clsDate() {
		clsDate Date = GetSystemDate();
		_day = Date._day;
		_month = Date._month;
		_year = Date._year;
	}
	clsDate(string DateString) {
		clsDate Date = StringToDate(DateString);
		_day = Date._day;
		_month = Date._month;
		_year = Date._year;
	}
	clsDate(short day, short month, short year) {
		_day = day;
		_month = month;
		_year = year;
	}
	clsDate(short days, short year) {
		_year = year;
		this->GetDateFromDayOrderInYear(days);

	}
	clsDate(const clsDate& copyDate) {
		_day = copyDate._day;
		_month = copyDate._month;
		_year = copyDate._year;
	}

	void setDay(short day) {
		_day = day;
	}
	short getDay() const {
		return _day;
	}

	void setMonth(short month) {
		_month = month;
	}
	short getMonth() const {
		return _month;
	}

	void setYear(short year) {
		_year = year;
	}
	short getYear() const {
		
		return _year;
	}

	string getMonthNumberInStrig() {
		if (this->month < 10) {
			return "0" + to_string(this->month);
		}
		return to_string(this->month);
	}
	string getYearNumberInString() {
		return  to_string(this->year);
	}

	void setDate(short day, short month, short year) {
		_day = day;
		_month = month;
		_year = year;
	}

	__declspec(property(get = getDay, put = setDay)) short day;
	__declspec(property(get = getMonth, put = setMonth)) short month;
	__declspec(property(get = getYear, put = setYear)) short year;

	static bool isMonth(short month) {
		if (month >= 1 && month <= 12) {
			return true;
		}
		return false;
	}
	 bool isMonth() {
		 if (this->month >= 1 && this->month <= 12) {
			 return true;
		 }
		 return false;
	}
	static bool IsLeapYear(short Year) {
		// if year is divisible by 4 AND not 
		// divisible by 100
		// OR if year is divisible by 400 
		// then it is a leap year 

		return (Year % 4 == 0 && Year % 100 != 0) ||
			(Year % 400 == 0);
	}
	bool IsLeapYear() {
		return IsLeapYear(_year);
	}

	static short NumberOfDaysInAYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear() {
		return NumberOfDaysInAYear(_year);
	}

	static int NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	int NumberOfHoursInAYear() {
		return NumberOfHoursInAYear(_year);
	}

	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinutesInAYear() {
		return NumberOfMinutesInAYear(_year);
	}

	static int NumberOfSecondsInAYear(short Year) {
		return NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear() {
		return NumberOfSecondsInAYear(_year);
	}

	static short NumberOfDaysInAMonth(short Month, short Year) {
		if (Month < 1 || Month > 12)
			return  0;

		int NumberOfDays[12] = {
	   31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (IsLeapYear(Year) ? 29
			: 28) : NumberOfDays[Month - 1];

	}
	 bool isDayWithInMonth() {
		 short DaysNumber = this->NumberOfDaysInAMonth();
		 if (this->_day >= 1 && this->_day <= DaysNumber) {
			 return true;
		 }
		 return false;
	 }
	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(_month, _year);
	}

	static short NumberOfHoursInAMonth(short Month, short Year) {
		return NumberOfDaysInAMonth(Month, Year) *
			24;
	}
	short NumberOfHoursInAMonth() {
		return NumberOfHoursInAMonth(_month, _year);
	}

	static int NumberOfMinutesInAMonth(short Month, short Year) {
		return NumberOfHoursInAMonth(Month, Year) *
			60;
	}
	int NumberOfMinutesInAMonth() {
		return NumberOfMinutesInAMonth(_month, _year);
	}

	static int NumberOfSecondsInAMonth(short Month, short Year) {
		return NumberOfMinutesInAMonth(Month, Year)
			* 60;
	}
	int NumberOfSecondsInAMonth() {
		return NumberOfSecondsInAMonth(_month, _year);
	}

	static short  DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;

		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;

		// Gregorian: 
		//0:sun, 1:Mon, 2:Tue...etc.  
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	static short DayOfWeekOrder(clsDate Date) {
		return DayOfWeekOrder(Date._day, Date._month, Date._year);
	}
	short  DayOfWeekOrder() {
		return DayOfWeekOrder(*this);
	}

	static string DayShortName(short DayOfWeekOrder)
	{
		if (DayOfWeekOrder >= 0 && DayOfWeekOrder <= 6) {
			string arrDayNames[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
			return arrDayNames[DayOfWeekOrder];
		}
		return "Invalid Day Name";
	}

	static string MonthShortName(short MonthNumber)
	{
		if (MonthNumber < 1 || MonthNumber > 12) {
			return "Invalid Month Name";
		}

		string Months[12] =
		{
		 "Jan", "Feb", "Mar",
		 "Apr", "May", "Jun",
		 "Jul", "Aug", "Sep",
		 "Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;

		// Index of the day from 0 to 6 
		int current = DayOfWeekOrder(1, Month, Year);

		NumberOfDays = NumberOfDaysInAMonth(Month, Year);

		// Print the current month name 
		printf("\n _______________%s__________________\n\n",
			MonthShortName(Month).c_str());

		// Print the columns 
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		// Print appropriate spaces 
		int i;
		for (i = 0; i < current; i++)
			printf("     ");

		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n ____________________________________\n");
	}
	void PrintMonthCalendar() {
		PrintMonthCalendar(_month, _year);
	}

	static void PrintYearCalendar(short Year)
	{
		printf("\n  _________________________________\n\n");
		printf("           Calendar - %d\n", Year);
		printf("  _________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}
	void PrintYearCalendar() {
		PrintYearCalendar(_year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;

		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOfTheYear() {
		return NumberOfDaysFromTheBeginingOfTheYear(_day, _month, _year);
	}

	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;

		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date._year = Year;

		Date._month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._month++;
			}
			else
			{
				Date._day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	void GetDateFromDayOrderInYear(short DateOrderInYear) {
		clsDate Date = GetDateFromDayOrderInYear(DateOrderInYear, _year);
		_day = Date._day;
		_month = Date._month;
		_year = Date._year;


	}

	static clsDate AddDaysToDate(short Days, clsDate& Date)
	{
		short RemainingDays = Days +
			NumberOfDaysFromTheBeginingOfTheYear(Date._day, Date._month,
				Date._year);
		short MonthDays = 0;
		Date._month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._month, Date._year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._month++;
				if (Date._month > 12)
				{
					Date._month = 1;
					Date._year++;
				}
			}
			else
			{
				Date._day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	void AddDaysToDate(short Days) {
		AddDaysToDate(Days, *this);
	}

	static bool IsDate1BeforeDate2(clsDate& Date1, clsDate& Date2)
	{
		return  (Date1._year < Date2._year) ? true :
			((Date1._year == Date2._year) ?
				(Date1._month < Date2._month ? true :
					(Date1._month == Date2._month ?
						Date1._day < Date2._day : false))
				: false);
	}
	bool IsDate1BeforeDate2(clsDate Date2) {
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate& Date1, clsDate& Date2)
	{
		return (Date1._year == Date2._year) ? ((
			Date1._month == Date2._month) ? ((Date1._day ==
				Date2._day) ? true : false) : false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._day == NumberOfDaysInAMonth(Date._month, Date._year));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool  IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool  IsLastMonthInYear() {
		return IsLastMonthInYear(_month);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool IncludeEndDay)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2, bool IncludeEndDay) {
		return GetDifferenceInDays(*this, Date2, IncludeEndDay);
	}
	static short getSystemYear() {
		time_t t = time(0);
		tm* now = localtime(&t);
		return now->tm_year + 1900;
	}
	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		return clsDate(now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
	}
	static clsDate getEmptyDate() {
		return clsDate(0, 0, 0);
	}
	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;

		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;

	}
	void SwapDates(clsDate& Date) {
		SwapDates(*this, Date);
	}

	static clsDate IncreaseDateByOneDay(clsDate& Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._month))
			{
				Date._month = 1;
				Date._day = 1;
				Date._year++;
			}
			else
			{
				Date._day = 1;
				Date._month++;
			}
		}
		else
		{
			Date._day++;
		}
		return Date;
	}
	void IncreaseDateByOneDay() {
		IncreaseDateByOneDay(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByXDays(short Days) {
		IncreaseDateByXDays(Days, *this);
	}

	static clsDate IncreaseDateByOneWeek(clsDate& Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	void IncreaseDateByOneWeek() {
		IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void IncreaseDateByXWeeks(short Days) {
		IncreaseDateByXWeeks(Days, *this);
	}

	static clsDate IncreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._month == 12)
		{
			Date._month = 1;
			Date._year++;
		}
		else
		{
			Date._month++;
		}
		//last check day in date should not exceed max days in the current month 
	   // example if date is 31/1/2022 increasing one month should not be 
		//31 / 2 / 2022, it should
		// be 28/2/2022 
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date._month, Date._year);
		if (Date._day > NumberOfDaysInCurrentMonth)
		{
			Date._day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void IncreaseDateByOneMonth() {
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void IncreaseDateByXMonths(short Days) {
		IncreaseDateByXMonths(Days, *this);
	}

	static clsDate IncreaseDateByOneYear(clsDate& Date)
	{
		Date._year++;
		return Date;
	}
	void IncreaseDateByOneYear() {
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate& Date)
	{
		Date._year += Years;
		return Date;

	}
	void IncreaseDateByXYears(short Days) {
		IncreaseDateByXYears(Days, *this);
	}

	static clsDate IncreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years 
		Date._year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade() {
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date._year += Decade * 10;
		return Date;
	}
	void IncreaseDateByXDecades(short Days) {
		IncreaseDateByXDecades(Days, *this);
	}

	static clsDate IncreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years 
		Date._year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury() {
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years 
		Date._year += 1000;
		return Date;
	}
	void IncreaseDateByOneMillennium() {
		IncreaseDateByOneMillennium(*this);
	}

	static clsDate DecreaseDateByOneDay(clsDate& Date)
	{

		if (Date._day == 1)
		{
			if (Date._month == 1)
			{
				Date._month = 12;
				Date._day = 31;
				Date._year--;
			}
			else
			{
				Date._month--;
				Date._day = NumberOfDaysInAMonth(Date._month, Date._year);
			}
		}
		else
		{
			Date._day--;
		}
		return Date;
	}
	void DecreaseDateByOneDay() {
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate& Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Days) {
		DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByOneWeek(clsDate& Date) {
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeek() {
		DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate& Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeeks(short Days) {
		DecreaseDateByXWeeks(Days, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate& Date)
	{
		if (Date._month == 1)
		{
			Date._month = 12;
			Date._year--;
		}
		else
		{
			Date._month--;
		}
		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date._month, Date._year);
		if (Date._day > NumberOfDaysInCurrentMonth)
		{
			Date._day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	void DecreaseDateByOneMonth() {
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate& Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Days) {
		DecreaseDateByXMonths(Days, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate& Date)
	{
		Date._year--;
		return Date;
	}
	void DecreaseDateByOneYear() {
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(short Years, clsDate& Date)
	{
		Date._year -= Years;
		return Date;
	}
	void DecreaseDateByXYears(short Days) {
		DecreaseDateByXYears(Days, *this);
	}

	static clsDate DecreaseDateByOneDecade(clsDate& Date)
	{
		//Period of 10 years 
		Date._year -= 10;
		return Date;
	}
	void DecreaseDateByOneDecade() {
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(short Decade, clsDate& Date)
	{
		Date._year -= Decade * 10;
		return Date;
	}
	void DecreaseDateByXDecades(short Days) {
		DecreaseDateByXDecades(Days, *this);
	}

	static clsDate DecreaseDateByOneCentury(clsDate& Date)
	{
		//Period of 100 years 
		Date._year -= 100;
		return Date;
	}
	void DecreaseDateByOneCentury() {
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate& Date)
	{
		//Period of 1000 years 
		Date._year -= 1000;
		return Date;
	}
	void DecreaseDateByOneMillennium() {
		DecreaseDateByOneMillennium(*this);
	}

	static bool IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}
	bool IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}

	static bool IsWeekend(clsDate Date)
	{
		// Weekends are Fri and Sat 
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 6 || DayIndex == 5);
	}
	bool IsWeekend() {
		return IsWeekend(*this);
	}

	static bool  IsBusinessDay(clsDate Date)
	{
		return !IsWeekend(Date);
	}
	bool  IsBusinessDay() {
		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}
	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}

	static short DaysUntilTheEndOfMonth(clsDate Date)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate._day = NumberOfDaysInAMonth(Date._month, Date._year);;
		EndOfMonthDate._month = Date._month;
		EndOfMonthDate._year = Date._year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}
	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}

	static short DaysUntilTheEndOfYear(clsDate Date)
	{
		clsDate EndOfMonthDate;

		EndOfMonthDate._day = 31;
		EndOfMonthDate._month = 12;
		EndOfMonthDate._year = Date._year;

		return GetDifferenceInDays(Date, EndOfMonthDate, true);
	}
	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}

	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);

		}

		return DaysCount;
	}
	short CalculateVacationDays(clsDate DateTo) {
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate& DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business 
		//day
			//we get rid of all weekends before the first business day 
		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//here we increase the vacation dates to add all weekends to it. 

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekend(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		//in case the return date is week end keep adding one day util you reach 
		//business day
		while (IsWeekend(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}
	clsDate CalculateVacationReturnDate(short VacationDays) {
		return CalculateVacationReturnDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2)
			&& !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date1) {
		return IsDate1AfterDate2(*this, Date1);
	}

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;
		/* if (IsDate1AfterDate2(Date1,Date2))
		return enDateCompare::After;*/
		//this is faster 
		return enDateCompare::After;
	}
	enDateCompare CompareDates(clsDate Date1) {
		return CompareDates(*this, Date1);
	}

	static bool IsValidDate(clsDate Date)
	{
		if (Date._day < 1 || Date._day > 31)
			return false;

		if (Date._month < 1 || Date._month>12)
			return false;

		if (Date._month == 2)
		{
			if
				(IsLeapYear(Date._year))
			{
				if (Date._day > 29)
					return false;
			}
			else
			{
				if (Date._day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInAMonth(Date._month, Date._year);

		if (Date._day > DaysInMonth)
			return false;

		return true;

	}
	bool IsValidDate() {
		return IsValidDate(*this);
	}

	static string DateToString(clsDate Date)
	{
		return  to_string(Date._day) + "/" +
			to_string(Date._month) + "/" +
			to_string(Date._year);
	}
	string DateToString() {
		return DateToString(*this);
	}

	static clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate;

		vDate = clsString::SpilitString(DateString, "/");

		Date._day = stoi(vDate[0]);
		Date._month = stoi(vDate[1]);
		Date._year = stoi(vDate[2]);

		return Date;
	}

	static string FormateDate(clsDate Date, string DateFormat)
	{
		string FormattedDateString = "";

		FormattedDateString = clsString::ReplaceWordInString(DateFormat, "dd",
			to_string(Date._day));
		FormattedDateString = clsString::ReplaceWordInString(FormattedDateString, "mm",
			to_string(Date._month));
		FormattedDateString = clsString::ReplaceWordInString(FormattedDateString, "yyyy",
			to_string(Date._year));

		return  FormattedDateString;
	}
	string FormateDate(string DateFormat) {
		return FormateDate(*this, DateFormat);
	}

	static int YourAgeInDays(clsDate Date1, clsDate Date) {
		return GetDifferenceInDays(Date1, GetSystemDate(), true);
	}
	int YourAgeInDays(clsDate Date) {
		return YourAgeInDays(*this, Date);
	}

	static void PrintFormateDate(clsDate Date, string DateFormat) {
		cout << FormateDate(Date, DateFormat) << endl;
	}
	void PrintFormateDate(string DateFormat) {
		PrintFormateDate(*this, DateFormat);
	}

	bool operator<  (const clsDate& Date2) {
		return  (this->_year < Date2._year) ? true :
			((this->_year == Date2._year) ?
				(this->_month < Date2._month ? true :
					(this->_month == Date2._month ?
						this->_day < Date2._day : false))
				: false);
	}
	bool operator<= (const clsDate& Date2) {
		if (this->operator<(Date2))
			return true;
		else if (this->operator==(Date2))
			return true;


		return false;

	}
	bool operator>= (const clsDate& Date2) {
		if (this->operator>(Date2))
			return true;
		else if (this->operator==(Date2))
			return true;


		return false;

	}
	bool operator>  (const clsDate& Date2) {
		return  (this->_year > Date2._year) ? true :
			((this->_year == Date2._year) ?
				(this->_month > Date2._month ? true :
					(this->_month == Date2._month ?
						this->_day > Date2._day : false))
				: false);
	}
	bool operator== (const clsDate& Date2) {
		return (this->_year == Date2._year) ? ((
			this->_month == Date2._month) ? ((this->_day ==
				Date2._day) ? true : false) : false) : false;
	}
	bool operator!= (const clsDate& Date2) {
		return this->operator==(Date2);
	}

	static string GetLocalDatetime(char Fromat[]) {

		time_t LocalTime = time(0);


		tm* DateTime = localtime(&LocalTime);

		char stringTime[50];

		strftime(stringTime, 50, Fromat, DateTime);//change the date time value into specific struct

		return stringTime;
	}
	static string GetLocalDatetime() {
		time_t t = time(0);
		tm* now = localtime(&t);


		string Date = to_string(now->tm_mday) + "/" + to_string(now->tm_mon + 1) + "/" + to_string(now->tm_year + 1900);
		string Time = to_string(now->tm_hour) + ":" + to_string(now->tm_min ) + ":" + to_string(now->tm_sec);

		return Date + " - " + Time;
	}
};

