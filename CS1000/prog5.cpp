/*
    Prog5

    This program reads an unknown number of records from an input file.
    Each record contains a student ID# (string), the student's semester
    average (double), and the letter grade earned (char). The program will
    determine how many students passed, how many failed and how many of
    each letter grade was assigned. It will then write to an output file
    the input values in tabular form followed by the 'calculated' values.
    Refer to the sample file output below.

    This program uses those functions described below. No arrays, structures,
    classes, or global variables were used in the solution of this problem.

    Input(file - prog5_25?inp.txt): student_id   (string)
                                    semester_avg (double)
                                    semester_grd (char)
    Constants: PASSING_MIN_AVG (double)

    Output(console):  (Sample Console Output)

    Authors' Names
    C.S.1428.25?
    --/--/--
       <blank line>
       <blank line>
    The student information has been processed and saved to prog5_25?out.txt.

    Output (file - prog5_25?out.txt):

    Sample file output:

    Authors' Names
    C.S.1428.25?
    --/--/--
       <blank line>
       <blank line>
    ID#        Average   Grade
    ---------------------------
    A12345678    47.50      F
    A98765432    69.50      C
    A00000000    74.80      W
    A01020304    19.75      I
    A10203040    91.00      A
    ...
       <blank line>
    22 student(s) received a passing grade.
    3 student(s) received a failing grade.
       <blank line>
    A B C D F W I
    7 6 5 4 3 2 1

    ======================================================================

    The program is processed as follows:

    * A void function printIdInfo is called to write the authors' personal
      information (name, class/section number, due date) on the first,
      second and third lines of the output file.
    * A void function printColumnHeaders is called to write to the output
      file two blank lines followed by underlined column headers for the
      table:
      ID#    Average    Grade
    * A void function getData is called to read from the input file the
      student ID#, the semester average, and the semester grade in this
      order.
	* As long as the student ID# is not "A0", the current record is
      processed as follows:
         * A void function passFailCount is called to determine how many
           students passed and how many failed.
              e.g. If the student did not withdraw or take an incomplete,
                      If the semester average is passing,
                         - pass_count is incremented
                      otherwise (else)
                         - fail_count is incremented

         Note: A grade of 59.5 or higher passes the class.

         * A void function gradeCount is called. gradeCount uses a switch
           statement to determine how many of each letter grade was assigned.
           (A's, B's, C's, D's, F's, W's, & I's)
         * A void function printStudentData is called to write to the
           output file the student ID#, the semester average, and the
           uppercase semester grade under the appropriate column headers.
           toupper and type casting are used.
         * The void function getData is called to read the next student ID#,
           semester average, and semester grade.
    * A void function printPassFailCount is called to write to the output
      file one blank line followed by the number of students who passed
      the course and the number of students who failed the course...in
      sentence form.
    * A void function printGradeCount is called to write to the output file
      one blank line followed by the column headers:
          A   B   C   D   F   W   I   under which are written the number
          (count) of each letter grade assigned.
    * The function printIdInfo is called to write the authors' personal
      information (name, class/section number, due date) to the console.
    * A void function printOutputFileNotice is called to write to the
      console two blank lines followed by a notice to users that the
      student information has been processed and stored to an output file.
      The name of the output file is indicated.

    ======================================================================

    Notes:
    - Logical tests allow for upper or lower case letter grades.
    - Semester averages are formatted to two decimal places.
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

void printIdInfo ( ostream &out );
void printColumnHeaders ( ofstream &fout );
void getData ( string &student_id, double &semester_avg,
               char &semester_grd, ifstream &fin );
void passFailCount ( int &pass_count, int &fail_count, double semester_avg,
                     char semester_grd, const double PASSING_MIN_AVG );
void gradeCount ( char semester_grd, int &grade_a, int &grade_b, int &grade_c,
                  int &grade_d, int &grade_f, int &grade_i, int &grade_w );
void printStudentData ( string student_id, double semester_avg,
                        char semester_grd, ofstream &fout );
void printPassFailCount ( int pass_count, int fail_count, ofstream &fout );
void printGradeCount ( int grade_a, int grade_b, int grade_c, int grade_d,
                       int grade_f, int grade_i, int grade_w, ofstream &fout );
void printOutputFileNotice( );


int main ()
{
    const double PASSING_MIN_AVG = 59.5;

    string student_id;

    double semester_avg;

    char semester_grd;

    int grade_a = 0,
        grade_b = 0,
        grade_c = 0,
        grade_d = 0,
        grade_f = 0,
        grade_w = 0,
        grade_i = 0,
        pass_count = 0,
        fail_count = 0;

    ifstream fin;
    fin.open ( "prog5_253inp.txt");

    if ( !fin )
    {
        cout << "Input file failed to open" << endl
             << "Program Terminated" << endl << endl;

        fin.close();

        return 1;
    }

    ofstream fout;
    fout.open ("prog5_253out.txt");

    if ( !fout )
    {
        cout << "Output File Failed to open" << endl
             << "Program Terminated" << endl << endl;

        fin.close ();
        fout.close();

        return 2;
    }

    printIdInfo ( fout );
    printColumnHeaders( fout );
    getData ( student_id, semester_avg, semester_grd, fin );

    while ( student_id != "A0" )
    {
        passFailCount ( pass_count, fail_count, semester_avg,
                        semester_grd, PASSING_MIN_AVG );
        gradeCount ( semester_grd, grade_a, grade_b, grade_c,
                     grade_d, grade_f, grade_i, grade_w );
        printStudentData ( student_id, semester_avg, semester_grd, fout );
        getData ( student_id, semester_avg, semester_grd, fin );
    }

    printPassFailCount ( pass_count, fail_count, PASSING_MIN_AVG, fout );
    printGradeCount ( grade_a, grade_b, grade_c, grade_d,
                      grade_f, grade_i, grade_w, fout );
    printIdInfo ( cout );
    printOutputFileNotice ( );

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}

/*
     Description: printIdInfo writes the authors' personal information
                  (name, class/section number, due date) on the first,
                  second, and third lines of the output file or the console as below:

                  Betty Boop
                  C.S.1428.25?
                  --/--/--

     Receives: ostream &out
     Constants: none
     Returns: none
*/
// Redacted Personal Info
void printIdInfo ( ostream &out )
{
     out << "" << endl
         << "" << endl
         << "" << endl;
}

/*
     Description: printColumnHeaders writes to the output file two blank lines
                  followed by underlined column headers for the table:
                  <blank line>
                  <blank line>
                    ID#    Average    Grade
                  --------------------------

     Receives: ofstream &fout
     Constants: none
     Returns: none
*/

void printColumnHeaders ( ofstream &fout )
{
    fout << endl << endl
         << "  ID#" << "      Average" << "    Grade" << endl
         << "---------------------------" << endl;
}

/*
     Description: getData reads student id#, semester average, and the semester grade
                  in this order from the input file.

     Receives: string student_id, double semester_avg, char semester_grd, ifstream &fin
     Constants: none
     Returns: none
*/

void getData ( string &student_id, double &semester_avg,
		       char &semester_grd, ifstream &fin )
{
    fin >> student_id >> semester_avg >> semester_grd;
}

/*
     Description: passFailCount determines how many students and how many failed.
                  If the student did not withdraw or take an incomplete, then if the
                  semester average is passing ( above 59.5 = PASSING_MIN_AVG ) increment
                  a count of students who received a passing grade, otherwise increment
                  the amount of students who received a failing grade.

     Receives: int &pass_count, int &fail_count, double semester_avg,
               char semester_grd, double PASSING_MIN_AVG
     Constants: double PASSING_MIN_AVG
     Returns: none
*/

void passFailCount( int &pass_count, int &fail_count, double semester_avg,
		            char semester_grd, const double PASSING_MIN_AVG )
{
	if ( ( semester_grd != 'I' && semester_grd != 'i' ) &&
         ( semester_grd != 'W' && semester_grd != 'w' ))
	{
         if ( semester_avg >= PASSING_MIN_AVG )
            ++pass_count;
         else
            ++fail_count;
	}
}

/*
     Description: gradeCount determines how many of each letter grade was assigned by
                  using a switch to increment counts for the following characters:
                   a, A, b, B, c, C, d, D, f, F, w, W, i, I

     Receives: char semester_grade, int grade_a, int grade_b, int grade_c,
               int grade_d, int grade_f, int grade_w, int grade_i
     Constants: none
     Returns: none
*/

void gradeCount ( char semester_grd, int &grade_a, int &grade_b, int &grade_c,
		          int &grade_d, int &grade_f, int &grade_w, int &grade_i)
{
    switch (semester_grd)
    {
        case 'a':
        case 'A': ++grade_a;
            break;
        case 'b':
        case 'B': ++grade_b;
            break;
        case 'c':
        case 'C': ++grade_c;
            break;
        case 'd':
        case 'D': ++grade_d;
            break;
        case 'f':
        case 'F': ++grade_f;
            break;
        case 'w':
        case 'W': ++grade_w;
            break;
        case 'i':
        case 'I': ++grade_i;
            break;
    }
}

/*
     Description: printStudentData writes to the output file the student id#, semester
     average to two decimal places, and the uppercase semester grade under the
     appropriate column headers as below:

                  A1???????    ??.??       A
                  A2???????    ??.??       B
                  ...
                  <blank line>

     Receives: string student_id, double semester_avg, char semester_grd, ofstream &fout
     Constants: none
     Returns: none
*/

void printStudentData ( string student_id, double semester_avg,
		                char semester_grd, ofstream &fout )
{
    fout << fixed << setprecision(2) << student_id
         << setw(8) << semester_avg << setw(8)
         << static_cast<char>(toupper( semester_grd )) << endl;
}

/*
     Description: printPassFailCount writes to the output file one blank line followed
                  by the number of students who passed the course and on the next line
                  the number of students who failed the course in sentence form as below:

                  <blank line>
                  ? students received a passing grade.
                  ? students received a failing grade.

     Receives: int pass_count, int fail_count, ofstream &fout, double PASSING_MIN_AVG
     Constants: double PASSING_MIN_AVG
     Returns: none
*/

void printPassFailCount ( int pass_count, int fail_count, ofstream &fout )
{
    fout << endl << endl
         << pass_count << " student(s) received a passing grade." << endl
         << fail_count << " student(s) received a failing grade." << endl;
}

/*
     Description: printGradeCount writes to the output file one blank line followed
                  by the column headers A B C D F W I under which should be written
                  the number (count) of each letter grade assigned as below:

                  <blank line>
                  A  B  C  D  E  F  W  I
                  0  0  0  0  0  0  0  0

     Receives: int grade_a, int grade_b, int grade_c, int grade_d,
               int grade_f, int grade_w, int grade_i, ofstream &fout
     Constants: none
     Returns: none
*/

void printGradeCount ( int grade_a, int grade_b, int grade_c, int grade_d, int grade_f,
		               int grade_w, int grade_i, ofstream &fout )
{
    fout << endl
         << "A  B  C  D  F  W  I" << endl
         << grade_a << "  " << grade_b << "  " << grade_c << "  " << grade_d
         << "  " << grade_f << "  " << grade_w << "  " << grade_i
         << endl;
}

/*
     Description: printOutputFileNotice writes to the console two blank lines
                  followed by a notice to the users that the student information
                  has been processed and stored in the output file "prog5_253out.txt"
                  Include the name of the file in the console output as below:

                  <blank line>
                  <blank line>
                  Student information has been processed and written to prog5_253out.txt.

     Receives: none
     Constants: none
     Returns: none
*/

void printOutputFileNotice ( )
{
    cout << endl << endl
         << "Student information has been processed and written to "
         << "prog5_253out.txt.";
}
