/*
    File: prog3_dkb71.cpp
    Author: David Bendel
    C.S.1428.253
    Program: #3
    Due Date: 03/08/13

    A retail company must file a monthly sales tax report listing the sales
    for the month and the amount of sales tax collected. This program reads
    from an input file the month (string), the year (integer), and the total
    amount (real) collected at the cash register (product sales + sales tax).
    Sales tax consists of both a state sales tax and a city sales tax. For
    example, if the state sales tax is 4% and the city sales tax is 2%, the
    total sales tax would be 6%.

    Processing:
    If the total amount collected is known (and it is - was read from the
    input file) and the total sales tax is 6% (city & state), the amount of
    the product sales is calculated as:

    S = T / 1.06  where S is the product sales and T is the total income
    (product sales plus sales tax).

    To encourage growth of small businesses, a small business owner receives
    a tax break on state taxes. If product sales for the month are less than
    $100,000, the business is only responsible for 90% of the taxes it would
    pay if product sales had met or exceeded $100,000.

   (Named constants are used for all literals.)

   Shown below is a sample layout for file output. Two blank lines are left
   after the author's identifying information before a sales tax report
   is printed. The output is displayed in tabular form with a 'title' and
   'column headers'.

   After the sales tax report is generated, the author's identifying
   information is printed to the console. Two blank lines are left before
   a message is printed to the console letting the user know the name of
   the output file to which the sales report was written. Note the sample
   console layout below.

   Arrays are not used in generating the sales report. The string library
   is included since the month is read in as a string.

   Input(file - prog3_25?inp.txt): month(string)
                                   year(int)
                                   total_collected(double)
   Constants: CITY_TAX_RATE  (double)
              STATE_TAX_RATE (double)
              SALES_CUTOFF   (double)
              TAX_BREAK      (double)

   Output(console):  (Sample Console Output)

        Author's Name
        C.S.1428.025?
        --/--/--
              <blank line>
              <blank line>
        The << month >> tax report has been saved to prog3_25?out.txt.

   Output(file - prog3_25?out.txt): (Sample File Output)

        Author's Name
        C.S.1428.025?
        --/--/--
              <blank line>
              <blank line>
        Month:   << month >> ,  << year >>
        ----------------------------------------
        Total Collected:       $ total_collected
        Sales:                   sales
        City Sales Tax:          city_tax
        State Sales Tax:         state_tax
        Total Sales Tax:         total_tax
        ----------------------------------------

        =======================================================================

   <Output will vary based on actual input.>
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main ()
{
    const double CITY_TAX_RATE = 0.02,
	             STATE_TAX_RATE = 0.04,
	             SALES_CUTOFF = 100000.00,
	             TAX_BREAK = 0.9;

	double total_collected,
	       product_sales,
	       city_taxes,
	       state_taxes,
	       total_taxes;

	int year;

	string month;

	ifstream fin;
	fin.open ( "prog3_253inp.txt" );

	if ( !fin )
	{
		cout << endl << endl
			 << "***Program Terminated.***" << endl << endl
			 << "Input file failed to open!" << endl;

		fin.close();

		return 1;
	}

	ofstream fout;
	fout.open ( "prog3_253out.txt" );

	if ( !fout )
	{
		cout << endl << endl
			 << "***Program Terminated.***" << endl << endl
			 << "Input file failed to open!" << endl;

		fin.close();
	    fout.close();

		return 2;
	}

    fin >> month >> year >> total_collected;

    product_sales = total_collected / ( 1 + CITY_TAX_RATE + STATE_TAX_RATE );

    city_taxes = product_sales * CITY_TAX_RATE;

    if ( product_sales < SALES_CUTOFF )
       state_taxes = ( product_sales * STATE_TAX_RATE ) * TAX_BREAK;
    else
       state_taxes = product_sales * STATE_TAX_RATE;

    total_taxes = state_taxes + city_taxes;

	fout << fixed << setprecision(2)
         << "David Bendel" << endl
         << "C.S.1428.253" << endl
         << "03/08/13" << endl << endl << endl

         << "Month:    " << month << ", " << year << endl
         << "-----------------------------------" << endl
         << "Total Collected:        $" << setw(8) << total_collected << endl
         << "Sales:                   " << setw(8) << product_sales << endl
         << "City Sales Tax:          " << setw(8) << city_taxes << endl
         << "State Sales Tax:         " << setw(8) << state_taxes << endl
         << "Total Sales Tax:         " << setw(8) << total_taxes << endl
         << "-----------------------------------" << endl;

	cout << "David Bendel" << endl
         << "C.S.1428.253" << endl
         << "03/08/13" << endl << endl << endl

         << "The " << month << " tax report has been saved to prog3_out.txt." << endl;

    fin.close();
    fout.close();

    return EXIT_SUCCESS;
}

