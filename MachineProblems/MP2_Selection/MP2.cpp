//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************
//
//																				Machine Problem 2 - Selection
//
//																						By: Matt Hole
//
//																					Created February 2nd, 2020
//
//
//													This program was created to sort through a list of students applying to a university, and select 
//													which students are accepted based off of certain critera.  There are two schools to the university,
//													Liberal arts, and music.  The criteria for acceptance are as follows:
//
//														Liberal Arts:
//									
//																1. No more than five people accepted.
//																2. If a parent is an alumnus, the GPA must be at least 3.0, but if no parents
//																are alumni the GPA must be at least 3.5.
//																3. If a parent is an alumnus, the combined SAT score must be at least 1000, but
//																if no parents are alumni the SAT must be at least 1200.
//
//														Music - No preferences for alumni here.
//
//																1. No more than three people accepted.
//																2. Math and verbal SAT's must be at least 500.
//
//
//************************************************************************************************************************************************************************************************
//************************************************************************************************************************************************************************************************

#include <iostream>;	// Links cin and cout statements in object code to library.
#include <iomanip>;		// Links setw and set precision in object code to library.
#include <fstream>;		// Links file I/O instructions in object code to library.
#include <strings>;		// Links object code to library to allow for the user defined string data type.

using namespace std;

const int MAXIMUM_NUMBER_OF_STUDENTS_ACCEPTED_TO_LIBERAL_ARTS = 5;
const double LIBERAL_ARTS_ALUMNI_GPA = 3.0;
const double LIBERAL_ARTS_ALUMNI_SAT_SCORE = 1000;
const double LIBERAL_ARTS_NON_ALUMNI_GPA = 3.5;
const double LIBERAL_ARTS_NON_ALUMNI_SAT_SCORE = 1200;
const int MAXIMUM_NUMBER_OF_STUDENTS_ACCEPTED_TO_MUSIC = 3;
const double MUSIC_MATH_SAT_SCORE = 500;
const double MUSIC_VERBAL_SAT_SCORE = 500;
const string LIBERAL_ARTS = "Liberal Arts";
const string Music = "Music";
const string ACCEPTED = "Accepted to ";
const string REJECTED = "Rejected - ";
const string GPA_TOO_LOW = "GPA too low";
const string COMBINED_SAT_TOO_LOW = "Combined SAT too low";
const string MATH_SAT_TOO_LOW = "Math SAT too low";
const string VERBAL_SAT_TOO_LOW = "Verbal SAT too low";


int main()
{
	ifstream inData;
	ofstream outData;

	char currentStudentSchoolChoice;
	double currentStudentHighSchoolGPA;
	int currentStudentMathSATScores;
	int currentStudentVerbalSATScores;
	char currentStudentAlumni;
	int currentApplicantNumber;
	string currentStudentSchoolChoice;




	cout << "Acceptance to College by Matt Hole" << endl << endl;

	cout << "Applicant #: " << currentApplicantNumber << endl;
	
	cout << "School = " << currentStudentSchoolChoice << "GPA = " << currentStudentHighSchoolGPA
		<< "math = " << currentStudentMathSATScores << "verbal = " << currentStudentVerbalSATScores
		<< "alumnus = " << currentStudentAlumni << endl;
	
	cout << "Applying to " << "Liberal Arts" << endl;
	cout << ""


}






