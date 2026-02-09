#pragma once
#include<string>
#include "clsDate.h"
using namespace std;
class clsPerson
{
private:

	string _firstName;
	string _secondName;
	string _thirdName;
	string _fourthName;
	string _lastName;
	clsDate _brithdate;
	string _nieghborhoodName;
	string _districtName;
	string _phoneNumber;

public:
	clsPerson(string firstName, string secondName, string thirdName, string fourthName, string lastName, 
		clsDate brithdate, string nieghboorhodName, string districtName, string phoneNumber) {
		this->_firstName = firstName;
		this->_secondName = secondName;
		this->_thirdName = thirdName;
		this->_fourthName = fourthName;
		this->_lastName = lastName;
		this->_brithdate = brithdate;
		this->_nieghborhoodName = nieghboorhodName;
		this->_districtName = districtName;
		this->_phoneNumber = phoneNumber;
	}

	void setFristNumber(string firstName) {
		this->_firstName = firstName;
	}
	string getFristNumber() const {
		return this->_firstName;
	}
	__declspec(property(put = setFristNumber,get = getFristNumber)) string firstName;

	void setSecondName(string secondName) {
		this->_secondName = secondName;
	}
	string getSecondName() const {
		return this->_secondName;
	}
	__declspec(property(put = setSecondName, get = getSecondName)) string secondName;

	void setThirdName(string thirdName) {
		this->_thirdName = thirdName;
	}
	string getThirdName() const {
		return this->_thirdName;
	}
	__declspec(property(put = setThirdName, get = getThirdName)) string thirdName;

	void setFourthName(string fourthName) {
		this->_fourthName = fourthName;
	}
	string getFourthName() const {
		return this->_fourthName;
	}
	__declspec(property(put = setFourthName, get = getFourthName)) string fourthName;

	void setLastName(string lastName) {
		this->_lastName = lastName;
	}
	string getLastName() const {
		return this->_lastName;
	}
	__declspec(property(put = setLastName, get = getLastName)) string lastName;

	string getFullName() const {
		return this->_firstName + " " + this->_secondName + " " + this->_thirdName + " " + this->_fourthName + " " + this->_lastName;
	}
	__declspec(property(get = getFullName)) string fullName;

	void setBrithdate(clsDate brithdate) {
		this->_brithdate = brithdate;
	}
	clsDate getBrithdate() const {
		return this->_brithdate;
	}
	__declspec(property(put = setBrithdate, get = getBrithdate)) clsDate brithdate;

	void setNieghboorhoodName(string nieghborhoodName) {
		this->_nieghborhoodName = nieghborhoodName;
	}
	string setNieghboorhoodName() const {
		return this->_nieghborhoodName;
	}
	__declspec(property(put = setNieghboorhoodName, get = setNieghboorhoodName)) string nieghborhoodName;

	void setDistrictName(string districtName) {
		this->_districtName = districtName;
	}
	string getDistrictName() const {
		return this->_districtName;
	}
	__declspec(property(put = setDistrictName, get = getDistrictName)) string districtName;

	string getAddress() const {
		return this->_nieghborhoodName + " - " + this->_districtName;
	}
	__declspec(property(get = getAddress)) string address;

	void setPhoneNumber(string phoneNumber) {
		this->_phoneNumber = phoneNumber;
	}
	string getPhoneNumber() const {
		return this->_phoneNumber;
	}
	__declspec(property(put = setPhoneNumber, get = getPhoneNumber)) string phoneNumber;
};


