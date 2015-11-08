#include <iostream>
#include <cstdlib>
#include <cctype>
#include <cstring>
// other header files where appropriate
using namespace std;

void ShowUsageGuide();
// prototype for FormSeqAsIs
void FormSeqAsIs(int,  char*[], char*&, int&);
char* SpacingSeqAsIs(int, char*[], char*, int);
// prototype for FormSeqProc
void FormSeqProc(int&, char*, char*&, int&, int);
// prototype for FormSeqProcRev
void FormSeqProcRev(int, char*, char*&);
// prototype for Equal
bool Equal(char*, char*);
// prototype for FreeAllDynaMem
void FreeAllDynaMem(char*&, char*&, char*&, char*&);
// other prototypes where appropriate


int main( int argc, char* argv[] )
{
    if (argc < 2)
    {
        ShowUsageGuide();
        return EXIT_SUCCESS;
    }

    char* seqAsIs = 0, 
        * seqProc = 0,
        * seqProcRev = 0,
        * seqAsIscpy = 0;
    int strLen = 0,
        newLen = 0;

    FormSeqAsIs(argc, argv, seqAsIs, strLen);
    seqAsIscpy = SpacingSeqAsIs(argc, argv, seqAsIs, strLen);

    // display seqAsIs preceded by "As is: "
    cout << "As is: " << seqAsIscpy << endl;

    FormSeqProc(strLen, seqAsIs, seqProc, newLen, argc);

    // display seqProc preceded by "---->: "
    cout << "---->: " << seqProc << endl;

    FormSeqProcRev(newLen, seqProc ,seqProcRev);

    // display seqProcRev preceded by "<----: "
    cout << "<----: " << seqProcRev << endl;

    if ( Equal(seqProc, seqProcRev) )
        cout << "Sequence entered is a palindrome" << endl;
    else
        cout << "Sequence entered is not a palindrome" << endl;
    cout << "======================================================="
         << endl;

    FreeAllDynaMem( seqAsIs, seqProc, seqProcRev, seqAsIscpy );

    return EXIT_SUCCESS;
}

void ShowUsageGuide()
{
   cout << "USAGE: ./a5 <sequence to check for palindrome>" << endl;
}

// definition for FormSeqAsIs
void FormSeqAsIs( int argc,  char* argv[], char* &seqAsIs, int& strLen )
{
    for ( int i = 1; i < argc; ++i )
        strLen += strlen( argv[i] );     

    seqAsIs = new char [strLen + 1];
    *seqAsIs = '\0';

    for ( int i = 1; i < argc; ++i )
        strcat( seqAsIs, argv[i] );
}

// properly spaces seqAsIs
char* SpacingSeqAsIs( int argc,  char* argv[], char* seqAsIs, int strLen )
{     
    char* seqAsIscpy = 0;
    seqAsIscpy = new char [strLen + argc];
    *seqAsIscpy = '\0';

    for ( int i = 1; i < argc; ++i )
    {
        strcat( seqAsIscpy, argv[i] );
        strcat( seqAsIscpy, " " );
    }    

    return seqAsIscpy;
}

// definition for FormSeqProc
void FormSeqProc( int &strLen, char* seqAsIs, char* &seqProc, 
                  int& newLen, int argc)
{
    for ( int i = 0; i < strLen; i++ )
        if ( isalnum( *( seqAsIs + i )) )
            ++newLen;

    seqProc = new char [newLen + 1];
    *seqProc = '\0';

    for ( int i = 0, j = 0; i < strLen; ++i )
    {
        if ( isalnum( *(seqAsIs + i )) != 0 )
        {
            *(seqProc + j ) = tolower(*( seqAsIs + i ));
            ++j;
        }
    }
}

// definition for FormSeqProcRev
void FormSeqProcRev( int newLen, char* seqProc, char*& seqProcRev)
{
    seqProcRev = new char [newLen + 1];
    *seqProcRev = '\0';
    strcpy ( seqProcRev, seqProc );

    char temp;

    for ( int i = 0, lstchar = newLen - 1; i < ((newLen / 2) ); ++i, --lstchar )
    {    
            temp = *(seqProcRev + i);
            *(seqProcRev + i ) = *(seqProcRev + lstchar );
            *(seqProcRev + lstchar ) = temp;
    }   
}

// definition for Equal
bool Equal( char* seqProc, char* seqProcRev )
{
    if ( strcmp( seqProc, seqProcRev ) == 0 )
        return true;
    else
        return false;
}

// definition for FreeAllDynaMem
void FreeAllDynaMem( char*& seqAsIs, char*& seqProc, 
                     char*& seqProcRev, char*& seqAsIscpy)
{
    delete [] seqAsIs;
    delete [] seqProc;
    delete [] seqProcRev;
    delete [] seqAsIscpy;

    seqAsIs = 0;
    seqProc = 0;
    seqProcRev= 0; 
    seqAsIscpy = 0;
}

