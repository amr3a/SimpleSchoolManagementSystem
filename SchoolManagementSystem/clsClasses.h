#pragma once
#include "FilesName.h"
#include "clsString.h"
#include <fstream>
#include <vector>
class clsClasses
{
public:
	enum enClasses;
private:
	string _classID;
	string _className;
	string _setClassID(enClasses ClassName) {
		switch (ClassName) {
		case enClasses::FristGrade:
			return "GRD01";
		case enClasses::SecondGrade:
			return "GRD02";
		case enClasses::ThirdGrade:
			return "GRD03";
		case enClasses::FourthGrade:
			return "GRD04";
		case enClasses::FifthGrade:
			return "GRD05";
		case enClasses::SixthGrade:
			return "GRD06";
		case enClasses::SeventhGrade:
			return "GRD07";
		case enClasses::EighthGrade:
			return "GRD08";
		case enClasses::NinthGrade:
			return "GRD09";
		case enClasses::FristSecondaryGrade:
			return "GRD10";
		case enClasses::SecondSecondaryGrade:
			return "GRD11";
		case enClasses::ThirdSecondaryGrade:
			return "GRD12";
		default:
			return "GRD00";
		}
	}
	static clsClasses convertLineToClassesObject(string line, string sperator = "#//#") {
		vector<string> vLine = clsString::SpilitString(line, sperator);
		clsClasses tempClass;
		tempClass._classID = vLine[0];
		tempClass._className = vLine[1];
		return tempClass;
	}
	static vector<clsClasses> _loadClassesDataFromFile() {
		vector<clsClasses> vClasses;
		fstream file;
		file.open(ClassesFile, ios::in);
		if (file.is_open()) {
			string line = "";
			while (getline(file,line)) {
				clsClasses tempClass = convertLineToClassesObject(line);
				vClasses.push_back(tempClass);
			}
		}
		return vClasses;
	}
	void setClassName(string classID) {
		this->_className = findClassByClassID(classID)._className;
	}
public:
	clsClasses() {
		this->_classID = "GRD00";
		this->_className = "With Out Class";
	}
	clsClasses(enClasses enClassName) {
		this->_classID = _setClassID(enClassName);
		setClassName(_classID);
	}
	
	enum enClasses {
		FristGrade = 1,
		SecondGrade = 2,
		ThirdGrade = 3,
		FourthGrade = 4,
		FifthGrade = 5,
		SixthGrade = 6,
		SeventhGrade = 7,
		EighthGrade = 8,
		NinthGrade = 9,
		FristSecondaryGrade = 10,
		SecondSecondaryGrade = 11,
		ThirdSecondaryGrade = 12
	};
	
	string getClassID() const {
		return this->_classID;
	}
	__declspec(property(get = getClassID)) string classID;

	string getClassName() const {
		return this->_className;
	}
	
	__declspec(property(get = getClassName)) string className;

	string getClassNumber() const {
		if (_className == "Frist Grade") {
			return "01";
		}
		else if (_className == "Second Grade") {
			return "02";
		}
		else if (_className == "Third Grade") {
			return "03";
		}
		else if (_className == "Fourth Grade") {
			return "04";
		}
		else if (_className == "Fifth Grade") {
			return "05";
		}
		else if (_className == "Sixth Grade") {
			return "06";
		}
		else if (_className == "Seventh Grade") {
			return "07";
		}
		else if (_className == "Eighth Grade") {
			return "08";
		}
		else if (_className == "Ninth Grade") {
			return "09";
		}
		else if (_className == "Frist Secondary Grade") {
			return "10";
		}
		else if (_className == "Second Secondary Grade") {
			return "11";
		}
		else if (_className == "Third Secondary Grade") {
			return "12";
		}
		else {
			return "00";
		}
	}
	static clsClasses findClassByClassID(string classID) {
		vector<clsClasses> vClasses = _loadClassesDataFromFile();
		for (clsClasses tempClass : vClasses) {
			if (classID == tempClass._classID) {
				return tempClass;
			}
		}

		return clsClasses();
	}
};

