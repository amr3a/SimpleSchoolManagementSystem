#pragma once
#include "clsHeaderScreen.h"
#include "clsUtil.h"
#include "clsStudents.h"
#include <vector>
#include <iomanip>
class clsShowAllStudentsScreen :public clsHeaderScreen
{

private:
	
	
	class clsClomnsLenght {
		struct stSimpleStudentData {
			string FullName;
			string studentNote;
		};
		struct stCloumnLength {
			short MaxNumberOfFullName;
			short MaxNumberOfStudentNote;
		};
		vector<stSimpleStudentData> getSimpleStudentData(vector<clsStudents>& vStudents) {
			vector<stSimpleStudentData> vSimpleStudentData;
			stSimpleStudentData timpSimpleStudentData;
			for (clsStudents& student : vStudents) {
				timpSimpleStudentData.FullName = student.fullName;
				timpSimpleStudentData.studentNote = student.studentNote;
				vSimpleStudentData.push_back(timpSimpleStudentData);
			}

			return vSimpleStudentData;
		}
		stCloumnLength _getMaxNumberOfColumnsLength(vector<clsStudents>& vStudents) {
			vector<stSimpleStudentData> vSimpleStudentData = getSimpleStudentData(vStudents);
			stCloumnLength tempMaxNumbers;

			tempMaxNumbers.MaxNumberOfFullName = (short)vSimpleStudentData[0].FullName.length();
			tempMaxNumbers.MaxNumberOfStudentNote = (short)vSimpleStudentData[0].studentNote.length();

			for (stSimpleStudentData& tempData : vSimpleStudentData) {
				if ((short)tempData.FullName.length() > tempMaxNumbers.MaxNumberOfFullName) {
					tempMaxNumbers.MaxNumberOfFullName = (short)tempData.FullName.length();
				}
				if ((short)tempData.studentNote.length() > tempMaxNumbers.MaxNumberOfStudentNote) {
					tempMaxNumbers.MaxNumberOfStudentNote = (short)tempData.studentNote.length();
				}
			}

			return tempMaxNumbers;
		}
		stCloumnLength _getMaxFixedColumnLength() {
			stCloumnLength cloumnLength;
			cloumnLength.MaxNumberOfFullName = 30;
			cloumnLength.MaxNumberOfStudentNote = 17;

			return cloumnLength;
		}
	public:

		clsClomnsLenght(vector<clsStudents>& vStudents) {
			stCloumnLength cloumnLength;
			if (clsStudents::isStudentFileEmpty()) {
				 cloumnLength = _getMaxFixedColumnLength();
			}
			else {
				 cloumnLength = _getMaxNumberOfColumnsLength(vStudents);
			}
			this->fullNameLength = cloumnLength.MaxNumberOfFullName + 2;
			if (cloumnLength.MaxNumberOfStudentNote <= 17) {
				this->StudentNoteLength = 17;
			}
			else {
				this->StudentNoteLength = cloumnLength.MaxNumberOfStudentNote + 2;
			}
			
			this->studetIdLenght = 13;
			this->studentClassLength = 24;
			this->studentStatusLength = 20;

		}
		short studetIdLenght;
		short fullNameLength;
     	short studentClassLength;
		short studentStatusLength;
		short StudentNoteLength;
	};
	
	
	static void _drawTableHeader(string LineSprator, clsClomnsLenght& cloumnsLength) {
		cout << LineSprator << "\n\n";
		cout << "| " << setw(cloumnsLength.studetIdLenght) << left << "student`s ID" << "| ";
		cout << setw(cloumnsLength.fullNameLength) << left << "Student`s Full Name" << "| ";
		cout << setw(cloumnsLength.studentClassLength) << left << "Student`s Class" << "| ";
		cout << setw(cloumnsLength.studentStatusLength) << left << "Student`s Status" << "| ";
		cout << setw(cloumnsLength.StudentNoteLength) << left << "Student`s Note" << "|\n";
		cout << LineSprator << "\n\n";
	}
	static void _drawTableRaw(clsStudents& Student , clsClomnsLenght& cloumnsLength) {
		
		cout << "| " << setw(cloumnsLength.studetIdLenght) << left << Student.studentID << "| ";
		cout << setw(cloumnsLength.fullNameLength) << left << Student.fullName << "| ";
		cout << setw(cloumnsLength.studentClassLength) << left << Student.studentClass.className << "| ";
		cout << setw(cloumnsLength.studentStatusLength) << left << Student.StudentStatus << "| ";
		cout << setw(cloumnsLength.StudentNoteLength) << left << Student.studentNote << "|\n";
		
	}
	static void _drawTableBody(vector<clsStudents>& vStudents  ,string LineSprator, clsClomnsLenght& cloumnsLength) {
		if (clsStudents::isStudentFileEmpty()) {
			cout << clsUtil::Tabs(9) <<"   There is no regestered students in the system " << endl;
		}
		else {
			for (clsStudents& student : vStudents) {
				_drawTableRaw(student, cloumnsLength);
			}
		}
	
		cout << LineSprator << "\n\n";
	}
	static void _drawTable() {
		string LineSperator = clsUtil::UnderScore(24) + "___";
		vector<clsStudents> vStudents = clsStudents::GetAllStudents();
		clsClomnsLenght cloumnsLength(vStudents);

		_drawTableHeader(LineSperator, cloumnsLength);
		_drawTableBody(vStudents,LineSperator, cloumnsLength);
	}
public:


	static void showAllStudents() {
		
		string Tabs = clsUtil::Tabs(6);
		string MainHeader = Tabs + "  " + "Show All Students Screen";
		string SubHeader = Tabs + " " + "Student(s) List. Students(" + to_string(clsStudents::getStudentNumbers()) + ")";
		clsHeaderScreen::showMainHeader(MainHeader, SubHeader,5);
		Tabs = "";
		_drawTable();
	}
};

