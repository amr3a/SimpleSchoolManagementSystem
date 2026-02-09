#pragma once
#include<string>
#include<vector>
#include<fstream>
#include "FilesName.h"
#include "clsString.h"
using namespace std;
class clsSubjects {
public:
	enum enSubjects;
private:
	string _subjcetID;
	string _subjectName;

	string _setSubjectID(enSubjects subjectName) {
		switch (subjectName) {
		case enSubjects::HolyQuran:
			return "GRD01";
		case enSubjects::IslamicStudies:
			return "SUB02";
		case enSubjects::EducationLiteracy:
			return "SUB03";
		case enSubjects::EnglishLanguage:
			return "SUB04";
		case enSubjects::Mathematics:
			return "SUB05";
		case enSubjects::Science:
			return "SUB06";
		case enSubjects::SocialScience:
			return "SUB07";
		case enSubjects::ArabicLanguage:
			return "SUB08";
		case enSubjects::History:
			return "SUB09";
		case enSubjects::Geography:
			return "SUB10";
		case enSubjects::SocialStudies:
			return "SUB11";
		case enSubjects::Physics:
			return "SUB12";
		case enSubjects::Biology:
			return "SUB13";
		case enSubjects::Chemistry:
			return "SUB14";
		default:
			return "SUB00";
		}
	}
	static clsSubjects _convertLineToSubjectesObject(string line, string sperator = "#//#") {
		vector<string> vLine = clsString::SpilitString(line, sperator);
		clsSubjects tempSubject;
		tempSubject._subjcetID = vLine[0];
		tempSubject._subjectName = vLine[1];
		return tempSubject;
	}
	static vector<clsSubjects> _loadSubjectesDataFromFile() {
		vector<clsSubjects> vSubjects;
		fstream file;
		file.open(SubjectsFile, ios::in);
		if (file.is_open()) {
			string line = "";
			while (getline(file, line)) {
				clsSubjects tempSubject = _convertLineToSubjectesObject(line);
				vSubjects.push_back(tempSubject);
			}
		}
		return vSubjects;
	}
	void setSubjectName(string SubjectID) {
		this->_subjectName = findSubjectBySubjectID(SubjectID)._subjectName;
	}
public:
	enum enSubjects {
		HolyQuran = 1,
		IslamicStudies,
		EducationLiteracy,
		EnglishLanguage,
		Mathematics,
		Science,
		SocialScience,
		ArabicLanguage,
		History,
		Geography,
		SocialStudies,
		Physics,
		Biology,
		Chemistry
	};
	clsSubjects() {
		this->_subjcetID = "SUB00";
		this->_subjectName = "With Out Subject";
	}
	clsSubjects(enSubjects enSubjectName) {
		this->_subjcetID = _setSubjectID(enSubjectName);
		setSubjectName(_subjcetID);
	}
	
	string getSubjectID() const {
		return this->_subjcetID;
	}
	_declspec(property(get = getSubjectID)) string subjcetID;

	string getSubjectName() const {
		return this->_subjectName;
	}
	_declspec(property(get = getSubjectName)) string subjectName;

	static clsSubjects findSubjectBySubjectID(string SubjectID) {
		vector<clsSubjects> vSubjects = _loadSubjectesDataFromFile();
		for (clsSubjects tempSubject : vSubjects) {
			if (SubjectID == tempSubject._subjcetID) {
				return tempSubject;
			}
		}

		return clsSubjects();
	}
};