#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// write prototype for StoreOrdered here
void StoreOrdered ( int[], int, int, int );
// write prototype for CombineOrdered
void CombineOrdered ( const int[], const int[], int[], int, int, int );
// write prototype(s) for display function(s) here
void DisplayArrays( const int[], int, string );

const int MAX_NUMS = 20;

int main()
{
   // declare evenIntsArray, oddIntsArray and comboIntsArray here
    int evenIntsArray[MAX_NUMS],
        oddIntsArray[MAX_NUMS],
        comboIntsArray[MAX_NUMS];

    int intValue,          // holder for user-entered integer
        numOfEvens,        // # of even integers entered
        numOfOdds,         // # of odd integers entered
        totalNums;         // total # of integers entered
    char reply;
    string evenStr = "evenIntsArray",
           oddStr = "oddIntsArray",
           comboStr = "comboIntsArray";

    do
    {
        numOfEvens = 0,
        numOfOdds = 0;
        totalNums = 0;
        cout << "You can enter up to " << MAX_NUMS << " integers." << endl;
        cout << "Continue to enter an integer? (n = no, any other = yes) ";
        cin >> reply;
        cin.ignore(9999, '\n');

        while (totalNums < MAX_NUMS && reply != 'n' && reply != 'N')
        {
            cout << "Integer value " << (totalNums + 1) << ": ";
            cin >> intValue;
            ++totalNums;

            if (intValue % 2 == 0)
            {
                ++numOfEvens;
            // call StoreOrdered here
                StoreOrdered( evenIntsArray, intValue, numOfEvens, totalNums );


            // call appropriate display function here
                DisplayArrays( evenIntsArray, numOfEvens, evenStr );

            }
            else
            {
                ++numOfOdds;
                // call StoreOrdered here
                StoreOrdered( oddIntsArray, intValue, numOfOdds, totalNums );


                // call appropriate display function here
                DisplayArrays( oddIntsArray, numOfOdds, oddStr );

            }

            if (totalNums == MAX_NUMS)
            {
                cout << "You have entered the maximum of " << MAX_NUMS
                     << " integers." << endl;
                break;
            }

            cout << "Continue to enter an integer? (n = no, any other = yes) ";
            cin >> reply;
            cin.ignore(9999, '\n');
        }
      // call CombineOrdered
        CombineOrdered( evenIntsArray, oddIntsArray, comboIntsArray, 
                        numOfEvens, numOfOdds, totalNums );

        cout << endl;
        if (comboIntsArray[0] % 2 == 0)
        {
         // call appropriate display function(s) here
         // (to display evenIntsArray followed by oddIntsArray)
            DisplayArrays( evenIntsArray, numOfEvens, evenStr );
            DisplayArrays( oddIntsArray, numOfOdds, oddStr );
        }
        else
        {
             // call appropriate display function(s) here
             // (to display oddIntsArray followed by evenIntsArray)
            DisplayArrays( oddIntsArray, numOfOdds, oddStr );
            DisplayArrays ( evenIntsArray, numOfEvens, evenStr );
        }

        // call appropriate display function(s) to display comboIntsArray here
        DisplayArrays( comboIntsArray, totalNums, comboStr );

        cout << endl;

        cout << "Do another case? (n = no, any other = yes) ";
        cin >> reply;
        cin.ignore(9999, '\n');
    } while (reply != 'n' && reply != 'N');

    cout << endl;
    cout << "Press Enter or Return when ready...";
    cin.get();

    return EXIT_SUCCESS;
}

// write definition for StoreOrdered here
void StoreOrdered( int evenIntsArray[], int intValue, int numOfEvens, int totalNums )
{
    int i;
    for ( i = numOfEvens - 1 ; i > 0 && evenIntsArray[i-1] > intValue; --i )
        evenIntsArray[i] = evenIntsArray[i-1];
    evenIntsArray[i] = intValue;

}

// write definition for CombineOrdered here
void CombineOrdered( const int evenIntsArray[], const int oddIntsArray[], 
                     int comboIntsArray[], int numOfEvens, int numOfOdds, 
                     int totalNums)
{
    int i,j,k;
    
    for ( i = 0, j = 0, k = 0; i < totalNums && (j < numOfEvens || k < numOfOdds); )
    {
        if ( j != numOfEvens && k != numOfOdds )
        {
        
            if ( evenIntsArray[j] < oddIntsArray[k] )
            {
                comboIntsArray[i] = evenIntsArray[j];
                ++j;
                ++i;
            }
            else if ( evenIntsArray[j] > oddIntsArray[k] )
            {
                comboIntsArray[i] = oddIntsArray[k];
                ++k;
                ++i;
            }
        }    
        else
        {
            if ( j == numOfEvens )
            {
                comboIntsArray[i] = oddIntsArray[k];
                ++k;
                ++i;
            }
            else if ( k == numOfOdds )
            {
                comboIntsArray[i] = evenIntsArray[j];
                ++j;
                ++i;
            }
        }
    }   
}

// write definition(s) for display function(s) here
void DisplayArrays( const int evenIntsArray[], int numOfEvens, string evenStr )
{
    cout << evenStr << " has " << numOfEvens << " value(s) stored: ";
    for ( int j = 0; j < numOfEvens; ++j)
        cout << evenIntsArray[j] << " ";
    cout << endl;
}
