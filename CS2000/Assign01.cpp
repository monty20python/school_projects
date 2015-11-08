/*
    Author: David Bendel
    Due Date: 7/11/13

    The program allows the user to interactively input (1) the month and year
    for the bill, (2) the subscription type (which package), and (3) the 
    number of hours used. The user is7 be prompted to enter each of the 
    three input data separately.

    The program prints the amount due in all cases. For a Package A customer, 
    the program also prints the amount that would be saved had Package B 
    been purchased (only if there would be savings) and the amount that would 
    be saved had Package C been purchased (only if there would be savings). 
    For a Package B customer, the program also prints the amount that 
    would be saved had Package C been purchased 
    (only if there would be savings).
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

// Function Prototypes
void PrepareOutputFile ( ofstream &, char [] );
void GetMonthAndYear ( int &, int & );
bool CheckLeapYear ( int );
int CalcMaxHoursInMonth ( int, bool );
int GetHoursUsed ( int );
char GetPackageType ();
double CalcBaseCharge ( char );
double CalcExcessCharge ( char , int );
double CalcSalesTax ( double, double );
double CalcTotalDue ( double, double, double );
void OutputActualBill ( ostream &, int, int, char, int, double, 
                        double, double, double );
void OutputWouldBeSavings ( ostream &, char, double, double );

// Global Constants
const int MAX_LENGTH_FN = 20, // Maximum Filename Length
          MAX_HOURS_31 = 744,
          MAX_HOURS_30 = 720,
          MAX_HOURS_29 = 696,
          MAX_HOURS_28 = 672,
          PACKAGE_A_MAX_HOURS = 10,
          PACKAGE_B_MAX_HOURS = 20;

const double PACKAGE_A_MONTH = 9.95,
             PACKAGE_B_MONTH = 14.95,
             PACKAGE_C_MONTH = 19.95,
             ADD_HOURS_A = 2.00,
             ADD_HOURS_B = 1.00,
             SALES_TAX = 0.0825;

int main()
{
    int month = 0,
        year = 0,
        hours_used = 0,
        max_hours = 0;

    double base_charge = 0,
           excess_charge = 0,
           tax = 0,
           total_due = 0,
           savings_if_B = 0,
           savings_if_C = 0;

    char package_type,
         reply,
         outputFilename[ MAX_LENGTH_FN + 1 ];

    bool leap_year;

    ofstream fout;

    PrepareOutputFile ( fout, outputFilename );

    do
    {
        GetMonthAndYear ( month, year );
        leap_year = CheckLeapYear ( year );
        max_hours = CalcMaxHoursInMonth ( month, leap_year );
        hours_used = GetHoursUsed ( max_hours );
        package_type = GetPackageType ();
        base_charge = CalcBaseCharge ( package_type );
        excess_charge = CalcExcessCharge ( package_type, hours_used );
        tax = CalcSalesTax ( base_charge, excess_charge );
        total_due = CalcTotalDue ( base_charge, excess_charge, tax );

        if (package_type == 'a' || package_type == 'A')
        {
             savings_if_B = total_due - (( CalcBaseCharge ('B') + 
                            CalcExcessCharge ( 'B', hours_used )) * 
                            ( 1 + SALES_TAX ));

             savings_if_C = total_due -  
                            CalcBaseCharge ('C') * ( 1 + SALES_TAX );
        }
        else if (package_type == 'b' || package_type == 'B')
        {
             savings_if_C = total_due - CalcBaseCharge ('C') + 
             CalcSalesTax ( 0, base_charge );
        }

        OutputActualBill ( cout, month, year, package_type, hours_used, 
                           base_charge, excess_charge, tax, total_due );
        OutputActualBill ( fout, month, year, package_type, hours_used, 
                           base_charge, excess_charge, tax, total_due );
        OutputWouldBeSavings ( cout, package_type, savings_if_B, savings_if_C );
        OutputWouldBeSavings ( fout, package_type, savings_if_B, savings_if_C );

        savings_if_B = 0; //reinitialize to 0 for repititions 
        savings_if_C = 0;

        cout << "Do another customer? (n = no, any other = yes) ";
        cin >> reply;
    } while (reply != 'n' && reply != 'N');
   
    fout.close();

    cout << "Press Enter or Return when ready..." << endl;
    cin.ignore(999, '\n');
    cin.get();
    return EXIT_SUCCESS;
}

// write definition for PrepareOutputFile
void PrepareOutputFile ( ofstream &fout, char outputFilename[])
{
    cout << "Output file name up to " << MAX_LENGTH_FN << " characters: ";
    cin.get ( outputFilename, MAX_LENGTH_FN + 1, '\n');
    cin.ignore (999, '\n');

    fout.open ( outputFilename, ios::out );

    if ( fout.fail() )
    {
        cout << "Output file" << outputFilename << " failed to open" << endl;
        cout << "Press Enter or Return when Ready..." << endl;
        cin.get();
        exit (EXIT_FAILURE);
    }
}

// GetMonthAndYear gets month and year from user
void GetMonthAndYear ( int &month, int &year )
{
    do
    {
        cout << "Please enter month (1-12): ";
        cin >> month;
    } while ( month < 1 || month > 12 );

    do
    {
        cout << "Please enter year (2000-9999): ";
        cin >> year;
    } while ( year < 2000 || year > 9999 );
}

// CheckLeapYear checks to see if the year given is a leap year
bool CheckLeapYear ( int year )
{
    bool leap_year;

    if ( ( ( year % 4 == 0 ) && ( year % 100 != 0) ) || ( year % 400 == 0 ) )
       leap_year = true;
    else
      leap_year = false;

   return leap_year;
}

// CalcMaxHoursInMonth calculates maximum number of hours in a given month
int CalcMaxHoursInMonth ( int month, bool leap_year )
{
    int max_hours;

    switch ( month )
    {
        case 1:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: max_hours = MAX_HOURS_31;
            break;
        case 4:
        case 6:
        case 9: max_hours = MAX_HOURS_30;
            break;
        case 3: max_hours = MAX_HOURS_31 - 1;
        break;
        case 11: max_hours = MAX_HOURS_30 + 1;
        break;
        case 2:
            if ( leap_year == true )
                max_hours = MAX_HOURS_29;
            else
                max_hours = MAX_HOURS_28;
        break;
    }

    return max_hours;
}

// GetHoursUsed gets hours used from user
int GetHoursUsed ( int max_hours )
{
    int hours_used;

    do
    {
        cout << "Enter number of hours used: ";
        cin >> hours_used;
    } while ( hours_used < 0 || hours_used > max_hours );

    return hours_used;
}

// GetPackageType gets package type input from user
char GetPackageType ()
{
    char package_type;

    do
    {
        cout << "Please enter package type (A,B,C): ";
        cin >> package_type;
    } while ( package_type != 'A' && package_type != 'a' && package_type != 'B' 
              && package_type != 'b' && package_type != 'C' 
              && package_type != 'c' );

    return package_type;
}

// CalcBaseCharge calculates base charge based on input
double CalcBaseCharge ( char package_type )
{
    double base_charge;

    if ( package_type == 'A' || package_type == 'a')
        base_charge = PACKAGE_A_MONTH;
   else if ( package_type == 'B' || package_type == 'b' )
        base_charge = PACKAGE_B_MONTH;
   else if ( package_type == 'C' || package_type == 'c')
        base_charge = PACKAGE_C_MONTH;

   return base_charge;
}

// CalcExcessCharge calculates charge for going over package allowance in hours
double CalcExcessCharge ( char package_type, int hours_used )
{
    double excess_charge;

    if (( package_type == 'A' || package_type == 'a' ) 
           && hours_used > PACKAGE_A_MAX_HOURS )
        excess_charge = ( hours_used - PACKAGE_A_MAX_HOURS ) * ADD_HOURS_A;
    else if (( package_type == 'B' || package_type == 'b' ) 
                && hours_used > PACKAGE_B_MAX_HOURS )
        excess_charge = ( hours_used - PACKAGE_B_MAX_HOURS ) * ADD_HOURS_B;
    else
        excess_charge = 0;

    return excess_charge;
}

// CalcSalesTax calculates sales tax using SALES_TAX constant
double CalcSalesTax ( double excess_charge, double base_charge )
{
    double tax;

    tax = ( excess_charge + base_charge ) * SALES_TAX;

    return tax;
}

// CalcTotalDue calculates total due based on input
double CalcTotalDue ( double tax, double excess_charge, double base_charge )
{
    double total_due;

    total_due = tax + excess_charge + base_charge;

    return total_due;
}

// OutputActualBill formats the output for the file and console
void OutputActualBill (ostream &out, int month, int year, char package_type, 
                       int hours_used, double base_charge, double excess_charge, 
                       double tax, double total_due )
{

   string month_name;

   switch( month )
   {
        case 1: month_name = "January ";
        break;
        case 2: month_name = "Febuary ";
        break;
        case 3: month_name = "March ";
        break;
        case 4: month_name = "April ";
        break;
        case 5: month_name = "May ";
        break;
        case 6: month_name = "June ";
        break;
        case 7: month_name = "July ";
        break;
        case 8: month_name = "August ";
        break;
        case 9: month_name = "September ";
        break;
        case 10: month_name = "October ";
        break;
        case 11: month_name = "November ";
        break;
        case 12: month_name = "December ";
        break;
   }

    out << fixed << setprecision(2) 
        << "=======================================" << endl
        << "San Marcos One-of-a-kind Fitness Center" << endl
        << "=======================================" << endl
        << "Monthly statement for:   " << setw(10) << month_name << year << endl
        << "---------------------------------------" << endl
        << "Package:                       " << setw(8) 
        << static_cast<char>(toupper(package_type)) << endl;

    if ( package_type == 'A' || package_type == 'a')
    {
        out << "Base hours:                    " << setw(8) 
            << PACKAGE_A_MAX_HOURS << endl
            << "Hourly rate for excess hours:  " << setw(8) 
            << ADD_HOURS_A << endl; 
    }   
    else if ( package_type == 'B' || package_type == 'b' )
    {
        out << "Base hours:                    " << setw(8) 
            << PACKAGE_B_MAX_HOURS << endl
            << "Hourly rate for excess hours:  " << setw(8) 
            << ADD_HOURS_B << endl; 
    }
    else if ( package_type == 'C' || package_type == 'c' )
    {
        out << "Base hours:                   " << setw(8) 
            << "unlimited" << endl
            << "Hourly rate for excess hours:  " << setw(8) << "N/A" << endl; 
    }

    out << "---------------------------------------" << endl
        << "Total hours used:              " << setw(8) << hours_used << endl
        << "Base charge:                   " << setw(8) << base_charge << endl 
        << "Excess charge:                 " << setw(8) << excess_charge << endl
        << "Sales tax (8.25):              " << setw(8) << tax << endl
        << "Total due:                     " << setw(8) << total_due << endl
        << "=======================================" << endl;
}

// OutputWouldBeSavings outputs to file and console possible savings
void OutputWouldBeSavings ( ostream &out, char package_type, 
                            double savings_if_B, double savings_if_C )
{
    if ( savings_if_B > 0 && savings_if_C > 0 && 
       ( package_type == 'A' || package_type == 'a' ))
    {
        out << "Savings if package B:          " << setw(8) 
            << savings_if_B << endl
            << "Savings if package C:          " << setw(8) 
            << savings_if_C << endl
            << "=======================================" << endl;
    }
    else if ( savings_if_B > 0 && 
            ( package_type != 'B' || package_type != 'b' ))
    {
        out << "Savings if package B:          " << setw(8) 
            << savings_if_B << endl
            << "=======================================" << endl;
    }
    else if ( savings_if_C > 0 && 
            ( package_type != 'C' || package_type != 'c' )) 
    {    
        out << "Savings if package C:          " << setw(8) 
            << savings_if_C << endl
            << "=======================================" << endl;
    }
}