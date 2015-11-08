/*
   File: prog2_dkb71.cpp

   Author: monty20python 
   Program: #2
   

   The Dimmitt Company manufactures doodles which are then shipped to
   customers. Four sizes of shipping boxes are used: Huge, Large, Medium,
   and Small holding 50, 25, 10, and 1 doodle(s) respectively. (Named
   constants are used as needed to represent the number of doodles each
   size container can hold.)

   =======================================================================

   This program prompts the user to enter the number of doodles to be
   shipped then calculates the number of each size container needed for
   the shipment. After all calculations are performed, the program prints
   the author's identifying information followed by the results as shown
   below. The output is printed both to the console screen and to an output
   file.

   An appropriate message is displayed to the console screen if the output
   file fails to open.

   An appropriate message is written to the console screen informing the
   user of the output file name to which the results have been written.

   The mod operator is used to solve this problem.

   Shown below is a sample layout for console output. Two blank lines are
   left after the prompt before printing the author's personal identifying
   information. Two blank lines are left after the last table entry before
   a message is printed to the screen letting the user know the name of the
   file to which the output has also been directed. The output is displayed
   in tabular form with a 'title' and 'column headers'. The author's
   personal information is included for identifying purposes.

   A sample layout for file output is shown below as well. With the
   exception of the prompt and the message directing the user to the
   output file, file output echoes console output.

   Input (keyboard): number of doodles to be shipped (integer)

   Constants:        HUGE = 50
                     LARGE = 25
                     MEDIUM = 10
   (integer values representing the number of doodles that fit in each box)

   Output (console): Sample screen display:

           Enter the number of doodles to be shipped: 237
               <blank line>
               <blank line>
           Author's Name
           C.S.1428.025?
           --/--/--
               <blank line>
           For shipment of 237 doodles:
               <blank line>
           Container         Number
           ------------------------
           Huge                 4
           Large                1
           Medium               1
           Small                2
               <blank line>
               <blank line>
           Program results have also been written to prog2_25?out.txt.

    Output (file - prog2_25?out.txt): Sample file output:

           Author's Name
           C.S.1428.025?
           --/--/--
               <blank line>
           For shipment of 237 doodles:
               <blank line>
           Container         Number
           ------------------------
           Huge                 4
           Large                1
           Medium               1
           Small                2

   =======================================================================

   <Output will vary based on actual input.>
*/

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main ()
{
    const int HUGE = 50,
              LARGE = 25,
              MEDIUM = 10;

    int doodles_ordered,
        doodles_left,
        huge_box,
        large_box,
        medium_box;

    ofstream fout;
    fout.open ("prog2_253out.txt");

    if ( !fout )
    {
	    cout << endl << endl
		     << " ***Program Terminated.*** " << endl << endl
		     << "Output file failed to open." << endl;

		fout.close();

		return 1;
	}

    cout << "Enter number of doodles ordered:";
    cin >> doodles_ordered;
    cout << endl << endl;

    cout << "monty20python" << endl
         << "C.S.1000" << endl
         << "Date" << endl << endl;

    huge_box = doodles_ordered / HUGE;
    doodles_left = doodles_ordered % HUGE;

    large_box = doodles_left / LARGE;
    doodles_left = doodles_ordered % LARGE;

    medium_box = doodles_left / MEDIUM;
    doodles_left = doodles_left % MEDIUM;

    cout << "For shipment of " << doodles_ordered << " doodles:"
         << endl << endl
         << "Container" << setw(12) << "Number" << endl
         << "---------------------" << endl
         << "Huge  " << setw(12) << huge_box << endl
         << "Large " << setw(12) << large_box << endl
         << "Medium" << setw(12) << medium_box << endl
         << "Small " << setw(12) << doodles_left // doodles_left = small boxes
         << endl << endl << endl
         << "Program results have also been written to prog2_253out.txt.";

    fout << "David Bendel" << endl
         << "C.S.1428.253" << endl
         << "02/22/13" << endl << endl;

    fout << "For shipment of " << doodles_ordered << " doodles:"
       	 << endl << endl
       	 << "Container" << setw(12) << "Number" << endl
       	 << "---------------------" << endl
       	 << "Huge  " << setw(12) << huge_box << endl
       	 << "Large " << setw(12) << large_box << endl
       	 << "Medium" << setw(12) << medium_box << endl
       	 << "Small " << setw(12) << doodles_left << endl;

    fout.close();

    return EXIT_SUCCESS;
}
