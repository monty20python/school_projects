/*
    File: prog4_dkb71.cpp

    Author: David Bendel
    C.S.1428.253
    Program: #4
    Due Date: 03/29/13

   A bank charges $10.00 a month plus the following check fees for a commercial
   checking account.

            $ 0.10 each for 1-19 checks
            $ 0.08 each for 20-39 checks
            $ 0.06 each for 40-59 checks
            $ 0.04 each for 60 or more checks

   The bank also charges a low balance fee of $15.00 if the balance of the
   account falls below $400.00 (before any check fees are applied.)

   This program prompts the user for the beginning balance and the number
   of checks written. It then computes the bank's service charges for the
   month and directs the service fee report to an output file.

   The user is given the name of the data file to which the service charges
   have been reported when an appropriate sentence is displayed to the
   output screen.

   Input(keyboard):   double begin_balance;
                      int checks;

   Constants:
                  MIN_BAL = 400.00    // minimum balance
              MONTHLY_FEE =  10.00    // base monthly fee
             LOW_BAL_FEE  =  15.00    // low balance fee

               FEE_LEVEL1 = 0.10      // fee:  1-19 checks
               FEE_LEVEL2 = 0.08      // fee: 20-39 checks
               FEE_LEVEL3 = 0.06      // fee: 40-59 checks
               FEE_LEVEL4 = 0.04      // fee: 60 or more checks

               CHECK_LEVEL1 = 19      // 1-19 checks
               CHECK_LEVEL2 = 39      // 20-39 checks
               CHECK_LEVEL3 = 59      // 40-59 checks

   =======================================================================
   Output Samples:

   ** BELOW MINIMUM balance/POSITIVE number of checks written **

   Sample Console Output:

         Author's Name
         C.S.1428.25?
         --/--/--
               <blank line>
               <blank line>
         Enter the following information about your checking account.

         Beginning balance: $100

         Number of checks written: 10

         The bank's service fees have been written to prog4_?out.txt.


   Sample File Output(file - prog4_?out.txt):

         Author's Name
         C.S.1428.25?
         --/--/--
               <blank line>
               <blank line>
         Low balance fee applied:    ??.??
         Number of checks written:      ??
         Check fee applied:          ??.??
         Monthly fee applied:        ??.??

         Total banking fees:       $ ??.??

   =======================================================================

   Output Samples:

   ** BALANCE EXCEEDS MINIMUM requirement/POSITIVE number of checks written **

   Sample Console Output:

         Same Layout As Previous Example Screen Output


   Sample File Output(file - prog4_?out.txt):

         Author's Name
         C.S.1428.25?
         --/--/--
               <blank line>
               <blank line>
         Number of checks written:      ??
         Check fee applied:          ??.??
         Monthly fee applied:        ??.??

         Total banking fees:       $ ??.??

   =======================================================================

   Output Samples:

   ** NEGATIVE balance/POSITIVE number of checks written **

   Sample Console Output:

         Author's Name
         C.S.1428.25?
         --/--/--
               <blank line>
               <blank line>
         Enter the following information about your checking account.

         Beginning balance: $-10
              You entered a negative beginning balance.
              Your account is currently overdrawn!

         Number of checks written: 10

         The bank's service fees have been written to prog4_?out.txt.


   Sample File Output(file - prog4_?out.txt):

         Same Layout As First Example File Output

   =======================================================================

   Output Samples:

   ** BALANCE EXCEEDS MINIMUM requirement/NEGATIVE number of checks written **

         Author's Name
         C.S.1428.25?
         --/--/--
               <blank line>
               <blank line>
         Enter the following information about your checking account.

         Beginning balance: $550.50

         Number of checks written: -10
              Number of checks must be zero or more.
              Program terminated.
              Notification of termination has been written to prog4_?out.txt.


   Sample File Output(file - prog4_?out.txt):

         Author's Name
         C.S.1428.25?
         --/--/--
               <blank line>
               <blank line>
         Negative number of checks entered.
         Program terminated without generating fee report.

   =======================================================================

    The program is processed as follows:

    The user's personal information is written to the console.
	The user's personal information is written to a file.
    The user is prompted for his/her beginning bank balance.
	If a negative value is entered for the beginning balance,
         - an urgent message is written to the console indicating the
           account is overdrawn
    The user is prompted for the number of checks written.
    If a negative value is given for the number of checks,
         - a message is written to the console informing the user that the
           number of checks must be greater than or equal to zero. The user
           is warned that the 'program is terminating' and the name of the
           file to which the termination notice has been written is displayed.
         - a message is written to the output file informing the user that
           the number of checks entered was negative. The user is informed
           that the program was terminated and unable to calculate the
           bank's monthly service fees.
    otherwise (else)
         - calculate the check fee
         - if the account balance is less than the minimum monthly balance,
                  - the total monthly fees are calculated
                    (standard monthly fee + check fee + a low balance fee)
                  - the low balance fee along with an appropriate message is
                    written to the bank's monthly service fee report (file)
           otherwise (else)
                  - the total monthly fees are calculated
                    (standard monthly fee + check fee)
         - the bank's monthly service fee report is written to the file
         - a message is written to the console indicating the name of the
           file to which the bank's service fee report has been reported

   =======================================================================

   All monetary output values are displayed to two decimal places.

   =======================================================================

   <Output will vary based on actual input.>
*/

#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

int main()
{
	const double MIN_BAL = 400.00,
	             MONTHLY_FEE = 10.00,
	             LOW_BAL_FEE = 15.00,
	             FEE_LEVEL1 = 0.10,
	             FEE_LEVEL2 = 0.08,
	             FEE_LEVEL3 = 0.06,
	             FEE_LEVEL4 = 0.04;

	const int CHECK_LEVEL1 = 19,
	          CHECK_LEVEL2 = 39,
	          CHECK_LEVEL3 = 59;

	double begin_balance,
	       total_fee,
	       check_fee;

	int checks;

	ofstream fout;
    fout.open( "prog4_out.txt" );

    if( !fout )
    {
        cout << endl << endl
             << "***Program Terminated***" << endl << endl
             << "Output file failed to open!" << endl;

        fout.close();

		return 1;
    }

    cout << "David Bendel" << endl
         << "C.S.1428.253" << endl
         << "03/29/13" << endl << endl;

    fout << "David Bendel" << endl
         << "C.S.1428.253" << endl
         << "03/29/13" << endl << endl << endl;

    cout << "Enter the following information about your checking account." << endl
         << endl
         << "Beginning balance: $";
    cin >> begin_balance;

    if ( begin_balance < 0 )
    {
        cout << endl
             << "You entered a negative beginning balance." << endl
             << "Your account is currently overdrawn!";
    }

    cout << endl
         << "Enter number of checks written: ";
    cin >> checks;

    if ( checks < 0 )
    {
        cout << endl
             << "Number of checks must be zero or more." << endl
             << "Program terminated." << endl
             << "Notification of termination has been written to prog4_out.txt."
             << endl;

        fout << "Negative number of checks entered." << endl
             << "Program terminated without generating report." << endl;
    }
    else
    {
        if ( checks == 0 )
            check_fee = 0;
        else if ( checks <= CHECK_LEVEL1 )
            check_fee = checks * FEE_LEVEL1;
        else if ( checks <= CHECK_LEVEL2 )
            check_fee = checks * FEE_LEVEL2;
        else if ( checks <= CHECK_LEVEL3 )
            check_fee = checks * FEE_LEVEL3;
        else
            check_fee = checks * FEE_LEVEL4;

        fout << fixed << setprecision(2);

        if ( begin_balance < MIN_BAL )
        {
            total_fee = MONTHLY_FEE + check_fee + LOW_BAL_FEE;

            fout << "Low balance fee applied:   " << setw(8) << LOW_BAL_FEE << endl;
        }
        else
        {
            total_fee = MONTHLY_FEE + check_fee;
        }

        fout << "Number of checks written:  " << setw(8) << checks << endl
             << "Check fee applied:         " << setw(8) << check_fee << endl
             << "Monthly fee applied:       " << setw(8) << MONTHLY_FEE << endl << endl
             << "Total banking fees:       $" << setw(8) << total_fee << endl;


        cout << endl
             << "The bank's service fees have been written to prog4_out.txt."
             << endl;

    }

    fout.close();

    return EXIT_SUCCESS;
}
