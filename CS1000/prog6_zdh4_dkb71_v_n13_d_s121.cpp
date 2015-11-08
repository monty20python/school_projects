/*
    File: prog6_zdh4_dkb71_v_n13_d_s121.cpp

    Author: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter
    C.S.1428.253
    Program: #6
    Due Date: 04/26/13

    Listed on an input file is data for a class of 13 students. Each record
    contains a student's ID, daily average and exam average in this order.
    Two parallel arrays are used to store the input data, a string array
    to store the student IDs and a real array to store the daily and exam
    averages. After storing the input data into the respective arrays, the
    semester averages are calculated for each student and the results stored
    in the array of averages. The semester averages are then used to
    determine the associated letter grade for each student. The results
    are stored in a third parallel array. A grade report is generated and
    printed to an output file.

    This program uses those functions described below. Classes are not used
    in the solution. Array dimensions and column references are the only
    global variables used.

    Input(file - prog6_25?inp.txt):
          multiple records, three data items per record, in this order:
          student ID (string)   daily asg avg (double)    exam avg (double)

    Constants:
          GLOBAL constants:

          int STUDENTS = 13,   // number of students
              AVGS = 3;        // number of averages

          int DAILY_AVG = 0,   // col in which daily averages are stored
              EXAM_AVG = 1,    // col in which exam averages are stored
              SMST_AVG = 2;    // col in which semester averages are stored

          Constants LOCAL to main:

          double GRD_A = 89.5,
                 GRD_B = 79.5,
                 GRD_C = 69.5,
                 GRD_D = 59.5;

          int DAILY_ASG_PERCENTAGE = 3;    // daily avg on a 10 pt scale
          double EXAM_AVG_PERCENTAGE = .7; // exam avg on a 100 pt scale

    Output(console):  (Sample Console Output)

    Authors' Names
    C.S.1428.025?
    --/--/--
       <blank line>
    The student grade report has been processed and saved to prog6_25?out.txt.

    Output (file - prog6_25?out.txt):

    Sample file output:

    Authors' Names
    C.S.1428.?
    Due date: --/--/--
       <blank line>
         SEMESTER GRADE REPORT

     Student     Semester   Letter
       ID        Average    Grade
    -------------------------------
     A00123456     90.39       A
     A00234567     86.92       B
       ...

    ======================================================================

    The program is processed as follows:

    * A void function, readData, reads the input data into two parallel
      arrays, one that holds the student IDs and one that holds the daily
      assignment and exam averages.
      Note: The 'averages' array will eventually hold the semester averages
      as well.
    * A void function, calcSemesterAvg, calculates the semester averages,
      storing the results in the array of averages previously created.

      The semester average is calculated as follows:
          Daily assignment average 30%
          Exam average 70%
      Note: The semester average calculation allows for the fact that the
            daily assignment averages are posted on a 10% scale and the
            exam averages on a 100% scale.
	* A void function, determineLtrGrd, determines the letter grades that
      will be assigned for the semester, and stores the results in a
      character array. The letter grade is determined based on the following:
      'A' -- 89.5 or higher
      'B' -- 79.5 or greater but less than 89.5
       etc.
    * A void function, printGradeReportHeadings, prints to the output file
      an appropriate title and column headers for a semester grade report.
    * A typed function, getPrecision, prompts the user for the number of
      decimal places he/she wishes to display on the student grade report.
      The user's response is returned to the calling routine. getPrecision
      leaves two blank lines after the prompt/keyboard response is displayed.
    * A void function, printGradeReport, prints IDs, semester averages and
      assigned letter grades under the appropriate column headers.
    * A void function, printIdInfo, prints the authors' personal information
      (name, class/section number, due date) on the first, second and third
      lines. The fourth line is left blank. (The calling routine determines
      the output stream to which the information is directed.)
    * A void function, printOutputFileNotice, writes to the console one
      blank line followed by a notice to users that the student information
      has been processed and stored to an output file. The name of the
      output file is included in the console notification.

    ======================================================================

    Notes:
    - The user determines the number of decimal places to which the averages
      are displayed. Semester averages are formatted to two decimal
      places for the final report run.
    - Student records are single-spaced on the output file.
    - All functions are fully documented.

    =======================================================================

   <Output will vary based on actual input.>
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

const int STUDENTS = 13,   // number of students
          AVGS = 3;        // number of averages

const int DAILY_AVG = 0,   // column in which daily averages are stored
          EXAM_AVG = 1,    // column in which exam averages are stored
          SMST_AVG = 2;    // column in which semester averages are stored

void readData( ifstream &fin, string student_ids[], double averages[][AVGS] );
void calcSemesterAvg( double averages[][AVGS], const double DAILY_ASG_PERCENTAGE,
		              const double EXAM_AVG_PERCENTAGE );
void determineLtrGrd ( const double averages[][AVGS], char ltr_grd[], const double GRD_A,
		               const double GRD_B, const double GRD_C, const double GRD_D );
void printGradeReportHeadings( ofstream &fout );
int getPrecision();
void printGradeReport( ofstream &fout, int places, const string student_ids[],
		               double averages[][AVGS], const char ltr_grds[] );
void printIdInfo( ostream &out, string authors_name, int sec_num, string date );
void printOutputFileNotice();

int main()
{
   const double GRD_A = 89.5,
                GRD_B = 79.5,
                GRD_C = 69.5,
                GRD_D = 59.5;

   const int DAILY_ASG_PERCENTAGE = 3;  // daily asg avg on a 10 pt scale
   const double EXAM_AVG_PERCENTAGE = .7;  // exam avg on a 100 pt scale

   string student_ids[STUDENTS];
   double averages[STUDENTS][AVGS];
   char ltr_grds[STUDENTS];

   int places;

   ifstream fin;
   fin.open("prog6_253inp.txt");

    if ( !fin )
    {
    	cout << "**Input File Failed to Open**" << endl
    		 << "**Program Terminated**" << endl;

    	fin.close();

    	return 1;
    }

   ofstream fout;
   fout.open("prog6_253out.txt");

    if ( !fout )
    {
    	cout << "**Output File Failed To Open**" << endl
    		 << "**Program Terminated**" << endl;

    	fin.close();
    	fout.close();

    	return 2;
    }

   readData ( fin, student_ids, averages );
   calcSemesterAvg ( averages, DAILY_ASG_PERCENTAGE, EXAM_AVG_PERCENTAGE );
   determineLtrGrd ( averages, ltr_grds, GRD_A, GRD_B, GRD_C, GRD_D );
   printIdInfo ( fout, "Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter",
		         253, "04/26/13" );
   printGradeReportHeadings ( fout );
   places = getPrecision ( );
   printGradeReport ( fout, places, student_ids, averages, ltr_grds );
   printIdInfo ( cout, "Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter",
		         253, "04/26/13");
   printOutputFileNotice ( );

    fin.close();
    fout.close();

   return EXIT_SUCCESS;
}

/*
    Function: readData

    Authors: William Whatley, Joseph Lavizzo, Sierra Tyler, John Hood
    C.S.1428.253
    Program 6 Function
    04/19/13
    As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

    Description: The void function readData reads the input data from the file
                 "prog6_253inp.txt" into two parallel arrays, one that holds the
                 student IDs and one that holds both the daily and exam averages.

    Receives: &fin ( ifstream ) student_ids[] ( string ), averages[][AVGS] ( double )
    Constants: none
    Returns: nothing, reads data from the input file
*/

void readData( ifstream &fin, string student_ids[], double averages[][AVGS] )
{
    for ( int student = 0; student < STUDENTS; ++student )
    {
    	fin >> student_ids[student] >> averages[student][DAILY_AVG]
    	    >> averages[student][EXAM_AVG];
    }
}

/*
    Function: calcSemesterAvg

    Author(s): John Walker, Jose Medina, Timothy Hoff, Rishabh Dewan
    C.S.1428.253
    Program 6 Function
    04/19/13
    As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

    Description: The void function calcSemesterAverage takes the daily average
                 and exam average and calculates semester averages. It then stores the
                 results in the array of averages previously created.

    Receives: averages[][AVGS] ( double )
    Constants: DAILY_ASG_PERCENTAGE ( const int ), EXAM_AVG_PERCENTAGE ( const double )
    Returns: nothing, calculates the semester average for each student
*/

void calcSemesterAvg( double averages[][AVGS], const double DAILY_ASG_PERCENTAGE,
		              const double EXAM_AVG_PERCENTAGE )
{
    for ( int student = 0; student < STUDENTS; ++student )
    {
    	averages[student][SMST_AVG] = ( averages[student][DAILY_AVG]
    	                                * DAILY_ASG_PERCENTAGE ) +
    	                                ( averages[student][EXAM_AVG] *
    	                                  EXAM_AVG_PERCENTAGE );
    }
}

/*
    Function: determineLtrGrd

    Authors: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter
    C.S.1428.253
    Program 6 Function
    04/19/13

    Description: The void function determineLtrGrd determines the letter grades that will
                 be assigned for the semester; storing the results in the character array
                 ltr_grd[] using a multi-way branch (else if). The averages to test are
                 stored in the 2 dimensional array averages[STUDENTS][SMST_AVG]
                 (protected by declaring as a constant in the definition,
                  the third column of the array for each student)
                 The letter grade should be determined based on the following conditions:

                 'A' >= GRD_A (89.5)
                 'B' >= GRD_B (79.5)
                 'C' >= GRD_C (69.5)
                 'D' >= GRD_D (59.5)
                 'F' < GRD_D



    Receives: const double averages[STUDENTS][AVGS], char ltr_grd[STUDENTS]
              double GRD_A (local), double GRD_B (local), double GRD_C (local),
              double GRD_D (local), (global const int) STUDENTS,
              SMST_AVG (global const int), AVGS (global const int)

    Constants: GRD_A, GRD_B, GRD_C, GRD_D, STUDENTS, SMST_AVG, AVGS

    Returns: None. Stores appropriate letter grades in the array ltr_grd[]
*/

void determineLtrGrd ( const double averages[STUDENTS][AVGS], char ltr_grd[STUDENTS],
		               const double GRD_A, const double GRD_B, const double GRD_C,
		               const double GRD_D )
{
	for ( int student = 0; student < STUDENTS; ++student )
	{
		if ( averages[student][SMST_AVG] >= GRD_A)
			ltr_grd[student] = 'A';
		else if ( averages[student][SMST_AVG] >= GRD_B )
			ltr_grd[student] = 'B';
		else if ( averages[student][SMST_AVG] >= GRD_C )
			ltr_grd[student] = 'C';
		else if (averages[student][SMST_AVG] >= GRD_D)
			ltr_grd[student] = 'D';
		else
			ltr_grd[student] = 'F';
	}
}

/*
      Function: printGradeReportHeadings

      Author(s): Nadia Malik, Matthew Zuniga, Jason Villegas, Kaylie Orebough
      CS.1428.253
      Program 6 getPrecision
      04/19/13
      As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

      Description: The void function printGradeReportHeadings prints a title and column
                   headers for a semester grade report to the output file as shown below:


      	             SEMESTER GRADE REPORT
      	                 <blank line>
                    Student  Semester  Letter
                      ID     Average   Grade
                   ---------------------------

      Receives: &fout ( ofstream )
      Constants: none
      Returns: nothing, prints grade report headings to the file
*/

void printGradeReportHeadings( ofstream &fout )
{
    fout << "    SEMESTER GRADE REPORT         " << endl << endl
    	 << "  Student    Semester    Letter    " << endl
    	 << "    ID       Average     Grade     " << endl
    	 << "-------------------------------    " << endl;
}

/*
    Function: getPrecision

    Author(s): James Rafferty, Charles Flori, Oscar Alcanatara, Zachary Coleman
    CS.1428.253
    Program 6 Function
    04/19/13
    As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

    Description: The typed function, getPrecision, prompts the user to enter the number of
                 decimal points to display when showing the student grade report.
                 The function displays the number of decimal places chosen followed
                 by two blank lines.

     Receives: none
     Constants: none
     Returns: places ( int )
*/

int getPrecision ()
{
	int places;

    cout << "Enter the number of decimal places you would like to"
    	 << " display on the grade report: ";
    cin >> places;
    cout << endl << endl;

    return places;
}

/*
    Function: printGradeReport

    Authors: Cory Cox, Dustin Hanks, Jaime Sandoval, Hammer Gibbens
    C.S.1428.253
    Program 6 Function
    04/19/13
    As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

    Description: The void function printGradeReport prints Id's, semester averages, and
                 assigned letter grades under the appropriate column headers. The
                 function header line is delivered five arguments: the output command,
                 the interger variable for the number of places, which is the number of
                 decimal places to which the averages are displayed, a string variable
                 for student ID's, a double value for grade averages, and a character
                 variable to represent the student's letter grade, in that order.
                 SMST is a constant variable for the student's semester average.
                 (student_ids[] and ltr_grds[] are declared as constants for protection)

    Receives: fout ( ofstream ), places ( int ), student_ids[] ( string ),
              averages[][AVGS] ( double ), ltr_grds[] ( char )
    Constants: AVGS (global int), SMST (global int), student_ids[], ltr_grds[]
    Returns: nothing, prints student Id's averages, and grades to an output file.
*/

void printGradeReport( ofstream &fout, int places, const string student_ids[],
		               double averages[][AVGS], const char ltr_grds[] )
{
	fout << fixed << setprecision(places);

    for ( int student = 0; student < STUDENTS; ++student)
    {
    	fout << student_ids[student] << "    " << averages[student][SMST_AVG]
    	     << "         " << ltr_grds[student] << endl;
    }
}

/*

    Function: printIdInfo

    Author(s): Dolores Enrique, Crystal Taylor, Billy Moody, & Lewis Stennis
    C.S. 1428.253
    Program 6 Function
    04/19/13
    As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

    Description: The void function, printIdInfo, prints the author(s) identifying
                 information (on separate lines) as shown below. The output is directed
                 to the screen or to an output file depending on the call.

                 Example output:
                 Betty Boop & Bugs Bunny  // Author(s) name(s)
                 C.S.1428.?               // Replace the "?" with the class section number
                  --/--/--                 // Date in this format MM/DD/YY
                 <blank line>

    Receives: &out ( ostream ), authors_name ( string ), sec_num ( int ), date ( string )
    Constants: none
    Returns:   nothing, prints author(s) identifying information.

*/

void printIdInfo ( ostream &out, string authors_name, int sec_num, string date )
{
    out << authors_name << endl
    	<< "C.S.1428." << sec_num << endl
    	<< date << endl << endl;
}

/*
    Function: printOutputFileNotice

    Authors: Kristen Kramer, Abigail Doucette, Bryan Zamora, Joseph Yates
    C.S.1428.253
    Program 6 Function
    04/19/13
    As edited by: Zaneta Hearst, David Bendel, Venancio Nunez, Daniel Slaughter

    Description: The void function printOutputFileNotice writes to the console one blank
                 line followed by a notice to users that the student information has
                 been processed and stored in the output file ("prog6_253out.txt").
                 The name of the output file is included in the console notification.

    Receives: none
    Constants: none
    Returns: nothing, prints notification to the console
*/

void printOutputFileNotice ()
{
    cout << "The student grade report has been processed and saved to prog6_253out.txt."
    	 << endl;
}

