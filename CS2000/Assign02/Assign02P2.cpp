#include <iostream>
#include <cstdlib>
#include <cctype>
using namespace std;

void printDiamond( int someSize = 1, char someSymbol = '*');

int main()
{
    printDiamond();
    cout << endl;
    printDiamond(1);
    cout << endl;
    printDiamond(2);
    cout << endl;
    printDiamond(3);
    cout << endl;
    printDiamond(4);
    cout << endl;
    printDiamond(5);
    cout << endl;
    printDiamond(1, '$');
    cout << endl;
    printDiamond(2, '$');
    cout << endl;
    printDiamond(3, '$');
    cout << endl;
    printDiamond(4, '$');
    cout << endl;
    printDiamond(5, '$');
    cout << endl;

    int someSize = 10;
    char someSymbol = ' ';
    printDiamond(someSize, someSymbol);
    cout << endl;

    return EXIT_SUCCESS;
}

void printDiamond ( int someSize, char someSymbol )
{
    if ( isblank(someSymbol))
        someSymbol = '*';

    if ( someSize <= 0) 
    {
        someSize = 1;
    } 
    else if ( someSize % 2 == 0 )
    {
        someSize = someSize + 1; 
    }

    for ( int line = 0; line < someSize; line+=2 )
    {
        for (int space = someSize-2; space > line; space-=2)
            cout << ' ';
        for (int symbol = 0; symbol <= line; symbol++)
            cout << someSymbol;
        
       cout << endl;
    }    
    for ( int line = 2; line <= someSize; line+=2 )
    {
        for ( int space = 2; space <= line; space+=2 )
            cout << ' ';
        for ( int symbol = someSize; symbol > line; symbol--)
            cout << someSymbol;
        cout << endl;
    }
}
