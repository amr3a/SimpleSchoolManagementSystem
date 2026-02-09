#pragma once
#include "clsPerson.h"
#include "clsClasses.h"
#include "clsString.h"
#include "clsClasses.h"
#include <fstream>
#include <vector>
#include <string>
class clsStudents: public clsPerson
{
public:
	enum enStudentStatus;
private:

	enum enMode {
		EmptyMode =0,
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

	string _studentID;
	clsClasses _studentClass;
	clsDate _regestrationDate;
	enStudentStatus _studentStatus;
	string _studentNote;



	string _StudentStatusToString() const {
		switch (_studentStatus) {
		case enStudentStatus::Enrolled:
			return "Enrolled";
		case enStudentStatus::Transfered:
			return "Transfered";
		case enStudentStatus::Absent:
			return "Absent";
		case enStudentStatus::TempararoryAbsent:
			return "Tempararory Absent";
		case enStudentStatus::Suspended:
			return "Suspended";
		case enStudentStatus::Passed:
			return "Passed";
		case enStudentStatus::Failed:
			return "Failed";
		case enStudentStatus::InCompleted:
			return "InCompleted";
		case enStudentStatus::Graduated:
			return "Graduated";
		default:
			return "UnEnrolled";
		}
	}
	static enStudentStatus _stringToStudentStatus(string studentStatus) {

		if (studentStatus == "Enrolled") {
			return enStudentStatus::Enrolled;
		}
		else if (studentStatus == "Transfered") {
			return enStudentStatus::Transfered;
		}
		else if (studentStatus == "Absent") {
			return enStudentStatus::Absent;
		}
		else if (studentStatus == "Tempararory Absent") {
			return enStudentStatus::TempararoryAbsent;
		}
		else if (studentStatus == "Suspended") {
			return enStudentStatus::Suspended;
		}
		else if (studentStatus == "Passed") {
			return enStudentStatus::Passed;
		}
		else if (studentStatus == "Failed") {
			return enStudentStatus::Failed;
		}
		else if (studentStatus == "InCompleted") {
			return  enStudentStatus::InCompleted;
		}
		else if (studentStatus == "Graduated") {
			return  enStudentStatus::Graduated;
		}
	
		return enStudentStatus::UnEnrolled;
	}
	static short _studentsNumbers() {
		short count = 0;
		fstream file;
		file.open(Studentfile, ios::in);
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
	string getStudentNumberInString()  {
		short numberOfStudents = _studentsNumbers() + 1;
		if (numberOfStudents < 10) {
			return  "0" + to_string(numberOfStudents);
		}

		return  to_string(numberOfStudents);
	}

	string _setStudentID()  {

		if (_mode == enMode::EmptyMode) {
			return "000000000000";
		}

		return _regestrationDate.getYearNumberInString() + _regestrationDate.getMonthNumberInStrig() + "00" +
			_studentClass.getClassNumber() + getStudentNumberInString();
	}

	string _convertStudentDataToLine() {
		string StudentData = this->_studentID + "#//#" + this->fullName + "#//#" +
			this->brithdate.DateToString() + "#//#" + this->address + "#//#" +
			this->phoneNumber + "#//#" + this->_studentClass.classID + "#//#" + this->_regestrationDate.DateToString() + "#//#" + _StudentStatusToString() + "#//#" + _studentNote;
			

		return StudentData;
	}
	void _addStudentToFile() {
		fstream file;
		file.open(Studentfile,ios::app);

		if (file.is_open()) {
			this->_studentID = _setStudentID();
			file << _convertStudentDataToLine() << endl;
			_isSave = enIsSave::DataIsSaved;
		}
		else {
			_isSave = enIsSave::DataISUnSaved;
			cout << "the file is not open";
		}
		file.close();
	}

	static clsStudents _convertDataLineToStudentSObject(string line, string sperator = "#//#") {
		vector<string> studentRecords = clsString::SpilitString(line, sperator);
		vector<string> fullName = clsString::SpilitString(studentRecords[1], " ");
		vector<string> address = clsString::SpilitString(studentRecords[3], " - ");

		clsStudents tempStudent(enMode::UpdateMode, fullName[0], fullName[1], fullName[2], fullName[3], fullName[4], clsDate::StringToDate(studentRecords[2]), address[0], address[1], studentRecords[4],
			clsClasses::findClassByClassID(studentRecords[5]), clsDate::StringToDate(studentRecords[6]), _stringToStudentStatus(studentRecords[7]), studentRecords[8]);

		tempStudent._studentID = studentRecords[0];

		return tempStudent;
	}
	static void _saveStudentsDataToFile(vector<clsStudents>& vStudents) {
		fstream file;
		file.open(Studentfile, ios::out);
		if (file.is_open()) {
			for (clsStudents& student: vStudents) {
				if (student._mode == enMode::UpdateMode) {
					file << student._convertStudentDataToLine() << endl;
				}
			}
		}
	}
	static vector<clsStudents> _loadStudentsDataFromFile() {
		vector<clsStudents> vStudents;
		fstream file;
		file.open(Studentfile, ios::in);
		if(file.is_open()) {
			string DataLine = "";
			while (getline(file, DataLine)) {
				clsStudents student = _convertDataLineToStudentSObject(DataLine);
				vStudents.push_back(student);
			}

		}
		file.close();

		return vStudents;
	}

	void _updateStudentData() {

		if (this->_mode == enMode::EmptyMode) {
			_isSave = enIsSave::DataISUnSaved;
			return;
		}

		vector<clsStudents> vStudents = _loadStudentsDataFromFile();
		for (clsStudents& student : vStudents) {
			if (_studentID == student._studentID) {
				_isSave = enIsSave::DataIsSaved;
				student = *this;
				break;
			}
			else {
				_isSave = enIsSave::DataISUnSaved;
			}
		}
		_saveStudentsDataToFile(vStudents);
	}
	void _deleteStudent() {

		if (this->_mode == enMode::EmptyMode) {
			_isSave = enIsSave::DataISUnSaved;
			return;
		}
		vector<clsStudents> vStudents = _loadStudentsDataFromFile();
		for (clsStudents& student: vStudents) {
			if (this->_studentID == student._studentID) {
				student._mode = enMode::DeleteMode;
				_isSave = enIsSave::DataIsSaved;
			}
			else {
				_isSave = enIsSave::DataISUnSaved;
			}
		}

		_saveStudentsDataToFile(vStudents);
	}

public:
	enum enStudentStatus {
		UnEnrolled = 0,
		Enrolled =1,
		Transfered,
		Absent,
		TempararoryAbsent,
		Suspended,
		Graduated,
		Passed,
		Failed,
		InCompleted
	};
	
	clsStudents(enMode mode,string firstName, string secondName, string thirdName, string fourthName, string lastName,
		clsDate brithdate, string nieghboorhodName, string districtName, string phoneNumber, clsClasses studentClass,
		clsDate regestrationDate, enStudentStatus studentStatus, string StudentNote):
		clsPerson(firstName, secondName, thirdName, fourthName, lastName, brithdate, nieghboorhodName, districtName, phoneNumber){

		this->_mode = mode;
		this->_studentClass = studentClass;
		this->_regestrationDate = regestrationDate;
		this->_studentStatus = studentStatus;
		this->_studentNote = StudentNote;	

		this->_studentID = "000000000000";
	}



	string getStudentID() const {
		return this->_studentID;


	}
	__declspec(property(get = getStudentID)) 	string studentID;

	void setStudentClass(clsClasses studentClass) {
		this->_studentClass = studentClass;
	}
	clsClasses getStudentClass() const {
		return this->_studentClass;
	}
	__declspec(property(put = setStudentClass, get = getStudentClass)) clsClasses studentClass;

	void setRegestrationDate(clsDate regestrationDate) {
		this->_regestrationDate = regestrationDate;
	}
	clsDate getRegestrationDate() const {
		return this->_regestrationDate;
	}
	__declspec(property(put = setRegestrationDate, get = getRegestrationDate)) clsDate regestrationDate;


	void setStudentStatus(enStudentStatus studentStatus) {
		switch (studentStatus) {
		case enStudentStatus::Enrolled:
			this->_studentStatus = Enrolled;
			break;
		case enStudentStatus::Transfered:
			this->_studentStatus = Transfered;
			break;
		case enStudentStatus::Absent:
			this->_studentStatus = Absent;
			break;
		case enStudentStatus::TempararoryAbsent:
			this->_studentStatus = TempararoryAbsent;
			break;
		case enStudentStatus::Suspended:
			this->_studentStatus = Suspended;
			break;
		case enStudentStatus::Passed:
			this->_studentStatus = Passed;
			break;
		case enStudentStatus::Failed:
			this->_studentStatus = Failed;
			break;
		case enStudentStatus::InCompleted:
			this->_studentStatus = InCompleted;
			break;
		case enStudentStatus::Graduated:
			this->_studentStatus = Graduated;
			break;
		default:
			this->_studentStatus = UnEnrolled;
		}	
	}
	string getStudentStatus() const {
		return this->_StudentStatusToString();
	}
	__declspec(property(put = setStudentStatus)) enStudentStatus studentStatus;
	__declspec(property(get = getStudentStatus)) string StudentStatus;
	
	void setStudentNote(string studentNote) {
	
			this->_studentNote = studentNote;
		
	}
	string getStudentNote() const {
		return this->_studentNote;
	}
	__declspec(property(put = setStudentNote, get = getStudentNote)) string studentNote;
	

	static short getStudentNumbers() {
		return _studentsNumbers();
	}
	__declspec(property(get = getStudentNumbers)) short studentNumbers;

	bool isEmpty() {
		return _mode == enMode::EmptyMode;
	}

	static clsStudents getEmptyObject() {
		return clsStudents(enMode::EmptyMode, "", "", "", "", "",
			clsDate(), "", "", "", clsClasses(), clsDate(),
			enStudentStatus::UnEnrolled, "");
	}
	static clsStudents getNewStudentObject() {
		return clsStudents(enMode::AddNewMode, "", "", "", "", "",
			clsDate(), "", "", "", clsClasses(), clsDate(),
			enStudentStatus::UnEnrolled,"");
	}
	static vector<clsStudents> GetAllStudents() {
		return _loadStudentsDataFromFile();
	}
	static clsStudents findStudentByID(const string studentID) {
		vector<clsStudents> vStudents = _loadStudentsDataFromFile();
		for (clsStudents& student : vStudents) {
			if (studentID == student._studentID) {
				return student;
			}
		}
		return getEmptyObject();
	}
	static bool isStudentExists(const string studentID) {
		clsStudents tempStudent = findStudentByID(studentID);

		return !tempStudent.isEmpty();
	}
	bool isStudentExists() {
		clsStudents tempStudent = findStudentByID(this->_studentID);
		return !tempStudent.isEmpty();
	}
	static bool isStudentFileEmpty() {
		return _studentsNumbers() == 0;
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
			_addStudentToFile();
			if (_isSave == enIsSave::DataIsSaved) {
				_mode = enMode::UpdateMode;
				return true;
			}
			return false;
		}
		case enMode::UpdateMode: {
			_updateStudentData();
			if (_isSave == enIsSave::DataIsSaved) {
				return true;
			}
			return false;
		}
		
		case enMode::DeleteMode: {
			_deleteStudent();
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