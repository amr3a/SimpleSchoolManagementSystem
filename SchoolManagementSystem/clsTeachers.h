#pragma once
#include "clsPerson.h"
#include "clsClasses.h"
#include "clsSubjects.h"
#include <string>
class clsTeachers:public clsPerson {

public:
	enum enEducationLevel;
private:
	enum enMode {
		EmptyMode,
		UpdateMode,
		AddNewMode,
		DeleteMode
	};
	enum enIsSave {
		DataIsSaved = 0,
		DataISUnSaved
	};
	

	enMode _mode;
	enIsSave _isSave;

	string _teacherID;
	enEducationLevel _educationLevel;
	vector<clsClasses> _vClassesTaught;
	clsSubjects _subjectTaught;
	clsDate _hireDate;
	string _teacherNote;

	static short _teachersNumbers() {
		short count = 0;
		fstream file;
		file.open(TeachersFile, ios::in);
		if (file.is_open()) {
			string Line = "";
			while (getline(file, Line)) {
				count++;
			}
			file.close();

			return count;
		}
		file.close();
		return -1;
	}
	string _getTeacherNumberInString() {
		short teacherNumbers = _teachersNumbers() + 1;
		if (teacherNumbers < 10) {
			return  "0" + to_string(teacherNumbers);
		}

		return  to_string(teacherNumbers);
	}
	string _getEducationLevelNumberInString() {
		switch (_educationLevel) {
		case enEducationLevel::BachelorQuranicSciences:
			return "01";
		case enEducationLevel::BachelorIslamicStudies:
			return "02";
		case enEducationLevel::BachelorArabicLanguage:
			return "03";
		case enEducationLevel::BachelorEnglishLiterature:
			return "04";
		case enEducationLevel::BachelorMathematics:
			return "05";
		case enEducationLevel::BachelorGeneralScience:
			return "06";
		case enEducationLevel::BachelorSocialScience:
			return "07 .";
		case enEducationLevel::BachelorHistory:
			return "08";
		case enEducationLevel::BachelorGeography:
			return "09";
		case enEducationLevel::BachelorSocialStudies:
			return "10";
		case enEducationLevel::BachelorPhysics:
			return "11";
		case enEducationLevel::BachelorBiology:
			return "12";
		case enEducationLevel::BachelorChemistry:
			return "13";
		default:
			return "00";
		}

	}
	string _getEducationLevelInString() const {
		switch (_educationLevel) {
		case enEducationLevel::BachelorQuranicSciences:
			return "Bachelor of Quranic Sciences";
		case enEducationLevel::BachelorIslamicStudies:
			return "Bachelor of Islamic Studies";
		case enEducationLevel::BachelorArabicLanguage:
			return "Bachelor of Arabic Language";
		case enEducationLevel::BachelorEnglishLiterature:
			return "Bachelor of English Literature";
		case enEducationLevel::BachelorMathematics:
			return "Bachelor of Mathematics";
		case enEducationLevel::BachelorGeneralScience:
			return "Bachelor of General Science";
		case enEducationLevel::BachelorSocialScience:
			return "Bachelor of Social Science";
		case enEducationLevel::BachelorHistory:
			return "Bachelor of History";
		case enEducationLevel::BachelorGeography:
			return "Bachelor of Geography";
		case enEducationLevel::BachelorSocialStudies:
			return "Bachelor of Social Studies";
		case enEducationLevel::BachelorPhysics:
			return "Bachelor of Physics";
		case enEducationLevel::BachelorBiology:
			return "Bachelor of Biology";
		case enEducationLevel::BachelorChemistry:
			return "Bachelor of Chemistry";
		default:
			return "Not Qualified";
		}
		
	}
	static enEducationLevel _stringToEducationLevel(string educationLevel) {

		if (educationLevel == "Bachelor of Quranic Sciences") {
			return enEducationLevel::BachelorQuranicSciences;
		}
		else if (educationLevel == "Bachelor of Islamic Studies") {
			return enEducationLevel::BachelorIslamicStudies;
		}
		else if (educationLevel == "Bachelor of Arabic Language") {
			return enEducationLevel::BachelorArabicLanguage;
		}
		else if (educationLevel == "Bachelor of English Literature") {
			return enEducationLevel::BachelorEnglishLiterature;
		}
		else if (educationLevel == "Bachelor of Mathematics") {
			return enEducationLevel::BachelorMathematics;
		}
		else if (educationLevel == "Bachelor of General Science") {
			return enEducationLevel::BachelorGeneralScience;
		}
		else if (educationLevel == "Bachelor of Social Science") {
			return enEducationLevel::BachelorSocialScience;
		}
		else if (educationLevel == "Bachelor of History") {
			return  enEducationLevel::BachelorHistory;
		}
		else if (educationLevel == "Bachelor of Geography") {
			return  enEducationLevel::BachelorGeography;
		}
		else if (educationLevel == "Bachelor of Social Studies") {
			return  enEducationLevel::BachelorSocialStudies;
		}
		else if (educationLevel == "Bachelor of Physics") {
			return  enEducationLevel::BachelorPhysics;
		}
		else if (educationLevel == "Bachelor of Biology") {
			return  enEducationLevel::BachelorBiology;
		}
		else if (educationLevel == "Bachelor of Chemistry") {
			return  enEducationLevel::BachelorChemistry;
		}
		return enEducationLevel::NotQualified;
	}
	string _setTeacherID() {

		if (_mode == enMode::EmptyMode) {
			return "000000000000";
		}

		return "THD" + _hireDate.getYearNumberInString() + _hireDate.getMonthNumberInStrig()  +
			_getEducationLevelNumberInString() + _getTeacherNumberInString();
	}

	string _convertTeacherDataToLine() {
		string TeacherData = this->_teacherID + "#//#" + this->fullName + "#//#" +
			this->brithdate.DateToString() + "#//#" + this->address + "#//#" +
			this->phoneNumber + "#//#" + "#//#" + this->_hireDate.DateToString() + "#//#" + _getEducationLevelInString() + 
			"#//#" + this->_subjectTaught.subjcetID + "#//#" + this->_teacherNote;


		return TeacherData;
	}
	void _addTeacherDataToFile() {
		fstream file;
		file.open(TeachersFile, ios::app);

		if (file.is_open()) {
			this->_teacherID = _setTeacherID();
			file << _convertTeacherDataToLine() << endl;
			_isSave = enIsSave::DataIsSaved;
		}
		else {
			_isSave = enIsSave::DataISUnSaved;
			cout << "the file is not open";
		}
		file.close();
	}
	string _convertTeacherClassesDataToLine(string classID) {
		return this->_teacherID + "#//#" + classID;
	}
	void _addTeacherClassesDataToFile() {
		fstream file;
		file.open(TeachersFile, ios::app);
		if (file.is_open()) {
			for (clsClasses& tempClass : _vClassesTaught) {
				file << _convertTeacherClassesDataToLine(tempClass.classID) << "\n";
			}
		}
		file.close();
	}

	void _addTeacherToFile() {
		_addTeacherDataToFile();
		_addTeacherClassesDataToFile();
	}
	 
	static vector<clsClasses> _loadTeacherClassesData(string teacherID) {
		fstream file;
		vector<clsClasses> vClasses;
		file.open(TeachersFile, ios::in);
		if (file.is_open()) {
			string line = "";
			while (getline(file, line)) {
				if (clsString::isWordExistsInString(line, teacherID)) {
					vector<string> vLine = clsString::SpilitString(line, "#//#");
					vClasses.push_back(clsClasses::findClassByClassID(vLine[1]));
				}
			}
			
		}
		file.close();

		return vClasses;
	}
	static clsTeachers _convertDataLineToTeacherSObject(string line, string sperator = "#//#") {
		vector<string> teacherRecords = clsString::SpilitString(line, sperator);
		vector<string> fullName = clsString::SpilitString(teacherRecords[1], " ");
		vector<string> address = clsString::SpilitString(teacherRecords[3], " - ");
	

		clsTeachers tempteacher(enMode::UpdateMode, fullName[0], fullName[1], fullName[2], fullName[3], fullName[4],
			clsDate::StringToDate(teacherRecords[2]), address[0], address[1], teacherRecords[4], clsDate::StringToDate(teacherRecords[5]),
			_stringToEducationLevel(teacherRecords[6]), clsSubjects::findSubjectBySubjectID(teacherRecords[7]), teacherRecords[8]);

		tempteacher._teacherID = teacherRecords[0];

		return tempteacher;
	}
	static vector<clsTeachers> _loadTeachersDataFromFile() {
		vector<clsTeachers> vTeachers;
		fstream file;
		file.open(TeachersFile, ios::in);
		if (file.is_open()) {
			string DataLine = "";
			while (getline(file, DataLine)) {
				clsTeachers teacher = _convertDataLineToTeacherSObject(DataLine);
				teacher._vClassesTaught = _loadTeacherClassesData(teacher._teacherID);
				vTeachers.push_back(teacher);
			}

		}
		file.close();

		return vTeachers;
	}
	static void _saveTeachersDataToTeachersFile(vector<clsTeachers>& vTeachers) {

		fstream file;
		file.open(TeachersFile, ios::out);
		if (file.is_open()) {
			for (clsTeachers& Teacher : vTeachers) {
				if (Teacher._mode == enMode::UpdateMode) {
					file << Teacher._convertTeacherDataToLine() << endl;
				}
			}
		}
	}
	static void _saveTeacherClassesDataToFile(vector<clsTeachers>& vTeachers) {
		fstream file;
		file.open(TeachersClassesFile,ios::out);
		if (file.is_open()) {
			for (clsTeachers& teacher : vTeachers) {
				for (clsClasses& tempClass : teacher._vClassesTaught) {
					file << teacher._convertTeacherClassesDataToLine(tempClass.classID) << "\n";
				}
			}
		}
		file.close();

	}
	static void _saveTeachersData(vector<clsTeachers>& vTeachers) {
		_saveTeachersDataToTeachersFile(vTeachers);
		_saveTeacherClassesDataToFile(vTeachers);

	}

	void _updateTeacherData() {

		if (this->_mode == enMode::EmptyMode) {
			_isSave = enIsSave::DataISUnSaved;
			return;
		}

		vector<clsTeachers> vTeachers = _loadTeachersDataFromFile();
		for (clsTeachers& teacher : vTeachers) {
			if (this->_teacherID == teacher._teacherID) {
				_isSave = enIsSave::DataIsSaved;
				teacher = *this;
				break;
			}
			else {
				_isSave = enIsSave::DataISUnSaved;
			}
		}
		_saveTeachersData(vTeachers);
	}
	void _deleteTeacher() {

		if (this->_mode == enMode::EmptyMode) {
			_isSave = enIsSave::DataISUnSaved;
			return;
		}
		vector<clsTeachers> vTeachers = _loadTeachersDataFromFile();
		for (clsTeachers& student : vTeachers) {
			if (this->_teacherID == student._teacherID) {
				student._mode = enMode::DeleteMode;
				_isSave = enIsSave::DataIsSaved;
			}
			else {
				_isSave = enIsSave::DataISUnSaved;
			}
		}

		_saveTeachersData(vTeachers);
	}
public:
	enum enEducationLevel {
		NotQualified = 0,
		BachelorQuranicSciences =1,
		BachelorIslamicStudies,
		BachelorEnglishLiterature,
		BachelorMathematics,
		BachelorGeneralScience,
		BachelorSocialScience,
		BachelorArabicLanguage,
		BachelorPhysics,
		BachelorHistory,
		BachelorGeography,
		BachelorSocialStudies,
		BachelorBiology,
		BachelorChemistry
	};

	clsTeachers(enMode mode, string firstName, string secondName, string thirdName, string fourthName, string lastName,
		clsDate brithdate, string nieghboorhodName, string districtName, string phoneNumber, clsDate hireDate,
		enEducationLevel educationLevel, clsSubjects subjectTaught, string teacherNote) :
		clsPerson(firstName, secondName, thirdName, fourthName, lastName, brithdate, nieghboorhodName, districtName, phoneNumber) {

		this->_mode = mode;
		this->_educationLevel = educationLevel;
		this->_subjectTaught = subjectTaught;
		this->_hireDate = hireDate;

		this->_teacherNote = teacherNote;

		this->_teacherID = "THD0000000000";
	}

	clsTeachers(enMode mode, string firstName, string secondName, string thirdName, string fourthName, string lastName,
		clsDate brithdate, string nieghboorhodName, string districtName, string phoneNumber, clsDate hireDate, 
		enEducationLevel educationLevel, clsSubjects subjectTaught, vector<clsClasses>  classesTaught,  string teacherNote) :
		clsPerson(firstName, secondName, thirdName, fourthName, lastName, brithdate, nieghboorhodName, districtName, phoneNumber) {

		this->_mode = mode;
		this->_educationLevel = educationLevel;
		this->_subjectTaught = subjectTaught;
		this->_vClassesTaught = classesTaught;
		
		this->_hireDate = hireDate;

		this->_teacherNote = teacherNote;

		this->_teacherID = "THD0000000000";
	}

	string getTeacherID() const {
		return _teacherID;
	}
	__declspec(property(get = getTeacherID))string teacherID;

	void setEducationLevel(enEducationLevel educationLevel) {
		this->_educationLevel = educationLevel;
	}
	string EducationLevel() const {
		return this->_getEducationLevelInString();
	}
	__declspec(property(put = setEducationLevel)) enEducationLevel educationLevel;
	__declspec(property(get = EducationLevel)) string educationLevel;

	void setClassesTaught(vector<clsClasses> vClassesTaught) {
		this->_vClassesTaught = vClassesTaught;
	}
	vector<clsClasses> getClassesTaught()  {
		return this->_vClassesTaught;
	}
	__declspec(property(put = setClassesTaught, get = getClassesTaught)) vector<clsClasses> subjectTaught;

	void setSubjectTaught(clsSubjects subjectTaught) {

	}
	clsSubjects getSubjectTaught() const {

	}
	__declspec(property(put = setSubjectTaught, get = getSubjectTaught)) clsSubjects subjectTaught;

	void setHireDate(clsDate hireDate) {
		this->_hireDate = hireDate;
	}
	clsDate getHireDate() const {
		return this->_hireDate;
	}
	__declspec(property(put = setHireDate,get = getHireDate)) clsDate hireDate;

	
	void setTeacherNote(string teacherNote) {
		this->_teacherNote = teacherNote;
	}
	string TeacherNote() const {
		return this->_teacherNote;
	}
	__declspec(property(put = setTeacherNote, get = TeacherNote)) string teacherNote;
	

	static short getTeacherNumbers() {
		return _teachersNumbers();
	}
	__declspec(property(get = getTeacherNumbers)) short teacherNumbers;

	bool isEmpty() {
		return _mode == enMode::EmptyMode;
	}
	static clsTeachers getEmptyObject() {
		return clsTeachers(enMode::EmptyMode, "", "", "", "", "",
			clsDate(), "", "", "", clsDate(),enEducationLevel::NotQualified, clsSubjects(), "");
	}
	static clsTeachers getNewStudentObject() {
		return clsTeachers(enMode::AddNewMode, "", "", "", "", "",
			clsDate(), "", "", "", clsDate(), enEducationLevel::NotQualified, clsSubjects(), "");
	}
	static vector<clsTeachers> GetAllTeachers() {
		return _loadTeachersDataFromFile();
	}

	static clsTeachers findTeacherByID(const string TeacherID) {

		vector<clsTeachers> vTeachers = _loadTeachersDataFromFile();
		for (clsTeachers& teacher : vTeachers) {
			if (TeacherID == teacher._teacherID) {
				return teacher;
			}
		}
		return getEmptyObject();
	}
	static bool isTeacherExists(const string teacherID) {
		clsTeachers tempTeacher = findTeacherByID(teacherID);

		return !tempTeacher.isEmpty();
	}
	bool isTeacherExists() {
		clsTeachers tempTeacher = findTeacherByID(this->_teacherID);
		return !tempTeacher.isEmpty();
	}
	static bool isTeacherFileEmpty() {
		return getTeacherNumbers() == 0;
	}
	bool save(const bool MarkForDelete = false) {
		if (MarkForDelete) {
			this->_mode = enMode::DeleteMode;
		}
		if (_mode == enMode::EmptyMode) {
			return false;
		}
		switch (_mode) {
		case enMode::AddNewMode: {
			_addTeacherToFile();
			if (_isSave == enIsSave::DataIsSaved) {
				_mode = enMode::UpdateMode;
				return true;
			}
			return false;
		}
		case enMode::UpdateMode: {
			_updateTeacherData();
			if (_isSave == enIsSave::DataIsSaved) {
				return true;
			}
			return false;
		}

		case enMode::DeleteMode: {
			_deleteTeacher();
			if (_isSave == enIsSave::DataIsSaved) {
				this->_mode = enMode::EmptyMode;
				*this = this->getEmptyObject();
				return true;
			}
			return false;
		}
		default:
			return false;
		}

	}
};

