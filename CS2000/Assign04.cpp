#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <climits>

using namespace std;

void SeedRand();
int BoundedRandomInt(int lowerBound, int upperBound);
int GetIntInput(int argc, const char inputDescription[],
                int validLo, int validHi);
void StoreOrdered ( int[], int, int, int );
void CombineOrdered ( const int[], const int[], int[], int, int, int, int );
void PlotArray ( const int arrayCombo[], int lower_value_bound, 
                 int upper_value_bound, int lower_size_bound, 
                 int upper_size_bound, int range_width, int comboSize );

int main(int argc, char* argv[])
{
    int *array1 = 0,
        *array2 = 0,
        *arrayCombo = 0;
    int lower_size_bound,
        upper_size_bound,
        lower_value_bound,
        upper_value_bound,
        range_width,
        arraySize1 = 0,
        arraySize2 = 0,
        comboSize = 0,
        randomInt,          // holder for a pseudo-random value
        i,
        count1 = 0,
        count2 = 0;                  // general loop counter
    char reply;

    //SeedRand();           // disabled for reproducible results

    do
    {
        lower_size_bound = GetIntInput(argc, "lower bound for array size",
                                       0, INT_MAX - 1);
        upper_size_bound = GetIntInput(argc, "upper bound for array size",
                                       lower_size_bound + 1, INT_MAX);
        lower_value_bound = GetIntInput(argc, "lower bound for array value",
                                        0, INT_MAX - 1);
        upper_value_bound = GetIntInput(argc, "upper bound for array value",
                                        lower_value_bound + 1, INT_MAX);
        range_width = GetIntInput(argc, "frequency plot range width",
                                  1, upper_value_bound - lower_value_bound + 1);

        
        arraySize1 = BoundedRandomInt( lower_size_bound, upper_size_bound );
        arraySize2 = BoundedRandomInt( lower_size_bound, upper_size_bound );
        comboSize  = arraySize1 + arraySize2;



        if (arraySize1 > 0)
            array1 = new int [arraySize1];   
        if (arraySize2 > 0)
            array2 = new int [arraySize2]; 
        if (comboSize > 0)
            arrayCombo = new int [comboSize]; 



        i = 0;
        while (i < arraySize1)
        {
            ++count1;
 
            randomInt = BoundedRandomInt( lower_value_bound, 
                                          upper_value_bound );
         
            StoreOrdered( array1, randomInt, arraySize1, count1 );

            ++i;
        }
        
        i = 0;
        while (i < arraySize2)
        {
            ++count2;

            randomInt = BoundedRandomInt( lower_value_bound, 
                                          upper_value_bound );
                   
            StoreOrdered( array2, randomInt, arraySize2, count2 );
           
            ++i;     
        }
       
        CombineOrdered( array1, array2, arrayCombo, arraySize1, arraySize2, 
                        comboSize, lower_size_bound );

        cout << endl;
        
        PlotArray( arrayCombo, lower_value_bound, upper_value_bound, 
                   lower_size_bound, upper_size_bound, range_width, comboSize);

        delete [] array1;
        delete [] array2;
        delete [] arrayCombo;

        array1 = 0;
        array2 = 0;
        arrayCombo = 0;

        count1 = 0;
        count2 = 0;
        i = 0;

        cout << "Do another (y = yes, any other character = no): ";
        cin >> reply;
        if (argc > 1)
            cout << reply << endl;
        cin.ignore(999, '\n');
    }
    while (reply == 'y' || reply == 'Y');

    cout << "Press the Enter/Return key when ready...";
    cin.get();
    return EXIT_SUCCESS;
}

// Function to seed the random number generator
// PRE:  none
// POST: The random number generator has been seeded.
void SeedRand()
{
    srand( (unsigned) time(NULL) );
}

// Function to generate a random integer between
// lowerBound and upperBound (inclusive)
// PRE:  lowerBound is a positive integer.
//       upperBound is a positive integer.
//       upperBound is larger than lowerBound
//       The random number generator has been seeded.
// POST: A random integer between lowerBound and upperBound
//       has been returned.
int BoundedRandomInt(int lowerBound, int upperBound)
{
    return ( rand() % (upperBound - lowerBound + 1) ) + lowerBound;
}

int GetIntInput(int argc, const char inputDescription[],
                int validLo, int validHi)
{
    int result;
    cout << "Enter " << inputDescription << ": ";
    cin  >> result;
    while ( ! cin.good() )
    {
        cerr << "Invalid integer input..." << endl;
        cin.clear();
        cin.ignore(999, '\n');
        cout << "Re-enter " << inputDescription << ": ";
        cin  >> result;
    }
    cin.ignore(999, '\n');

    while ( ! (result >= validLo && result <= validHi) )
    {
        cerr << "Invalid " << inputDescription << " (must be between "
             << validLo << " and " << validHi << ")..." << endl;
        cout << "Re-enter " << inputDescription << ": ";
        cin  >> result;
        while ( ! cin.good() )
        {
            cerr << "Invalid integer input..." << endl;
            cin.clear();
            cin.ignore(999, '\n');
            cout << "Re-enter " << inputDescription << ": ";
            cin  >> result;
        }
        cin.ignore(999, '\n');
    }
    if (argc > 1)
       cout << result << endl;

    return result;
}

// definition for StoreOrdered (adopt/adapt from Assignment 3 Part 2)
void StoreOrdered( int array1[], int randomInt, int arraySize1, int count1 )
{
    int i;
    
    for ( i = count1 - 1  ; i > 0 && array1[i-1]  > randomInt; --i )
        array1[i] = array1[i-1];
    array1[i] = randomInt;
}

// definition for CombineOrdered (adopt/adapt from Assignment 3 Part 2)
void CombineOrdered( const int array1[], const int array2[], 
                     int arrayCombo[], int arraySize1, int arraySize2, 
                     int comboSize, int lower_size_bound)
{
    int i,j,k;
    
    for ( i = 0, j = 0, k = 0; i < comboSize ; )
    {
        if ( j != arraySize1 && k != arraySize2 )
        {       
            if ( array1[j] <= array2[k] )
            {
                arrayCombo[i] = array1[j];
                ++j;
                ++i;
            }
            else if ( array1[j] > array2[k] )
            {
                arrayCombo[i] = array2[k];
                ++k;
                ++i;
            }
        }   
        else
        {
            if ( j == arraySize1 )
            {
                arrayCombo[i] = array2[k];
                ++k;
                ++i;
            }
            else if ( k == arraySize2 )
            {
                arrayCombo[i] = array1[j];
                ++j;
                ++i;
            }
        }
    } 
}
// write definition for PlotArray (core task of this assignment)
void PlotArray ( const int arrayCombo[], int lower_value_bound, 
                 int upper_value_bound, int lower_size_bound, 
                int upper_size_bound, int range_width, int comboSize )
{
    int lines = 0,
        temp = 0;

    if ( upper_value_bound % range_width == 0 )
        lines = upper_value_bound / range_width;

    else
        lines = ( upper_value_bound / range_width ) + 1;

    for ( int i = 0,  j = lower_value_bound,  k = 0; i < lines && j <= 
          upper_value_bound && k < comboSize  ; ++i )
    {
        temp = j + range_width ;

        if ( temp > upper_value_bound )
            temp = j + ( upper_value_bound % range_width ) + 1;

        cout << setw(2) << j << " -" << setw(2) << temp - 1 << ": ";

        while ( arrayCombo[k] >= j && arrayCombo[k] < temp  )
        {
            cout << "*";
            ++k;
        }
                
        j = temp;

        cout << endl;
    }
    temp = 0;
    lines = 0;
}
