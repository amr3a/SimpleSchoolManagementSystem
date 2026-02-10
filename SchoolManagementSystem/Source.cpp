#include<iostream>
#include "clsMainMenue.h"
#include "clsAddTeacherMenueScreen.h"
#include "clsShowTeachersListScreen.h"
#include "clsSharedTeachersFunctions.h"
#include "clsClasses.h"
#include "iomanip"
#include "clsStudents.h"
#include <string>
using namespace std;
int main() {

	//clsMainMenue::showMenue();
	//clsAddTeacherMenueScreen::showMenue();
	clsSharedTeachersFunctions::_readEducationLevel();
	return 0;
}
 