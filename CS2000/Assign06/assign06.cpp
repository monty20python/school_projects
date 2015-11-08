// FILE: assign06.cpp
//       An interactive test program for the SortedInt data type.

#include "SortedInt.h"
#include <iostream>
#include <cstdlib>
using namespace std;

// PROTOTYPES for functions used by this test program:

void print_menu();
// Pre:  (none)
// Post: A menu of choices for this program is written to cout.

char get_user_command();
// Pre:  (none)
// Post: The user is prompted to enter a one character command.
//       The next character is read (skipping blanks and newline
//       characters), and this character is returned.

int get_object_num();
// Pre:  (none)
// Post: The user is prompted to enter either 1, 2 or 3. The
//       prompt is repeated until a valid integer can be read
//       and the integer's value is either 1, 2 or 3. The valid
//       integer read is returned. The input buffer is cleared
//       of any extra input until and including the first
//       newline character.

int get_integer();
// Pre:  (none)
// Post: The user is prompted to enter an integer. The prompt
//       is repeated until a valid integer can be read. The
//       valid integer read is returned. The input buffer is
//       cleared of any extra input until and including the
//       first newline character.

void print_to_cout(SortedInt src);
// Pre:  (none)
// Post: The content of src is displayed on cout.
/* Quiz: Why isn't src passed by const reference? */

int main(int argc, char* argv[])
{
   SortedInt s1, s2, s3;  // 3 SortedInt's to perform tests on
   reset(s1);             // initialize s1 to an empty SortedInt
   reset(s2);             // initialize s2 to an empty SortedInt
   reset(s3);             // initialize s3 to an empty SortedInt
   int objectNum,         // A number to indicate s1, s2 or s3
       givenValue,        // Holder for a user supplied value
       delCount;          // Counter for tracking items deleted
   char choice;           // A command character entered by the user

   cout << "3 SortedInt objects (s1 s2 s3) have been created." << endl;
   cout << "Each is now empty." << endl;

   do
   {
      if (argc == 1)
         print_menu();
      choice = get_user_command();
      switch (choice)
      {
      case 'a':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            if ( ! isEmpty(s1) )
               cout << "   Average for s1 is "
                    << findAvg(s1) << endl;
            else
               cout << "   s1 is empty (average undefined)" << endl;
            break;
         case 2:
            if ( ! isEmpty(s2) )
               cout << "   Average for s2 is "
                    << findAvg(s2) << endl;
            else
               cout << "   s2 is empty (average undefined)" << endl;
            break;
         case 3:
            if ( ! isEmpty(s3) )
               cout << "   Average for s3 is "
                    << findAvg(s3) << endl;
            else
               cout << "   s3 is empty (average undefined)" << endl;
         }
         break;
      case 'A':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            add(s1, s1);
            cout << "   s1 has been added to s1 " << endl;
            break;
         case 2:
            add(s1, s2);
            cout << "   s2 has been added to s1 " << endl;
            break;
         case 3:
            add(s1, s3);
            cout << "   s3 has been added to s1 " << endl;
         }
         break;
      case 'c': case 'C':
         s3 = combine(s1, s2);
         cout << "   s3 has been set to the combination of s1 and s2"
              << endl;
         break;
      case 'e':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            if ( isEmpty(s1) )
               cout << "   s1 is empty" << endl;
            else
               cout << "   s1 is not empty" << endl;
            break;
         case 2:
            if ( isEmpty(s2) )
               cout << "   s2 is empty" << endl;
            else
               cout << "   s2 is not empty" << endl;
            break;
         case 3:
            if ( isEmpty(s3) )
               cout << "   s3 is empty" << endl;
            else
               cout << "   s3 is not empty" << endl;
         }
         break;
      case 'E':
         if ( equal(s1, s2) )
            cout << "   s1 is identical to s2" << endl;
         else
            cout << "   s1 is not identical to s2" << endl;
         if ( equal(s1, s3) )
            cout << "   s1 is identical to s3" << endl;
         else
            cout << "   s1 is not identical to s3" << endl;
         if ( equal(s2, s3) )
            cout << "   s2 is identical to s3" << endl;
         else
            cout << "   s2 is not identical to s3" << endl;
         break;
      case 'f': case 'F':
         givenValue = get_integer();
         cout << "   The # of times " << givenValue
              << " occurs in s1 is " << findFreq(s1, givenValue) << endl;
         break;
      case 'i': case 'I':
         objectNum = get_object_num();
         givenValue = get_integer();
         switch (objectNum)
         {
         case 1:
            insert(s1, givenValue);
            cout << "   " << givenValue << " has been inserted into s1"
                 << endl;
            break;
         case 2:
            insert(s2, givenValue);
            cout << "   " << givenValue << " has been inserted into s2"
                 << endl;
            break;
         case 3:
            insert(s3, givenValue);
            cout << "   " << givenValue << " has been inserted into s3"
                 << endl;
         }
         break;
      case 'k':
         objectNum = get_object_num();
         givenValue = get_integer();
         switch (objectNum)
         {
         case 1:
            if ( delOne(s1, givenValue) )
               cout << "   " << givenValue << " has been deleted from s1"
                    << endl;
            else
               cout << "   " << givenValue << " not found in s1" << endl;
            break;
         case 2:
            if ( delOne(s2, givenValue) )
               cout << "   " << givenValue << " has been deleted from s2"
                    << endl;
            else
               cout << "   " << givenValue << " not found in s2" << endl;
            break;
         case 3:
            if ( delOne(s3, givenValue) )
               cout << "   " << givenValue << " has been deleted from s3"
                    << endl;
            else
               cout << "   " << givenValue << " not found in s3" << endl;
         }
         break;
      case 'K':
         objectNum = get_object_num();
         givenValue = get_integer();
         delCount = 0;
         switch (objectNum)
         {
         case 1:
            while ( delOne(s1, givenValue) ) ++delCount;
            cout << "   " << delCount << " copies of "
                 << givenValue << " has been deleted from s1" << endl;
            break;
         case 2:
            while ( delOne(s2, givenValue) ) ++delCount;
            cout << "   " << delCount << " copies of "
                 << givenValue << " has been deleted from s2" << endl;
            break;
         case 3:
            while ( delOne(s3, givenValue) ) ++delCount;
            cout << "   " << delCount << " copies of "
                 << givenValue << " has been deleted from s3" << endl;
         }
         break;
      case 'm':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            if ( isEmpty(s1) )
               cout << "   s1 is empty" << endl;
            else
               cout << "   Lowest value in s1 is "
                    << findMin(s1) << endl;
            break;
         case 2:
            if ( isEmpty(s2) )
               cout << "   s2 is empty" << endl;
            else
               cout << "   Lowest value in s2 is "
                    << findMin(s2) << endl;
            break;
         case 3:
            if ( isEmpty(s3) )
               cout << "   s3 is empty" << endl;
            else
               cout << "   Lowest value in s3 is "
                    << findMin(s3) << endl;
         }
         break;
      case 'M':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            if ( isEmpty(s1) )
               cout << "   s1 is empty" << endl;
            else
               cout << "   Highest value in s1 is "
                    << findMax(s1) << endl;
            break;
         case 2:
            if ( isEmpty(s2) )
               cout << "   s2 is empty" << endl;
            else
               cout << "   Highest value in s2 is "
                    << findMax(s2) << endl;
            break;
         case 3:
            if ( isEmpty(s3) )
               cout << "   s3 is empty" << endl;
            else
               cout << "   Highest value in s3 is "
                    << findMax(s3) << endl;
         }
         break;
      case 'p': case 'P':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            if ( isEmpty(s1) )
               cout << "   s1: (empty)" << endl;
            else
            {
               cout << "   s1: ";
               print_to_cout(s1);
            }
            break;
         case 2:
            if ( isEmpty(s2) )
               cout << "   s2: (empty)" << endl;
            else
            {
               cout << "   s2: ";
               print_to_cout(s2);
            }
            break;
         case 3:
            if ( isEmpty(s3) )
               cout << "   s3: (empty)" << endl;
            else
            {
               cout << "   s3: ";
               print_to_cout(s3);
            }
         }
         break;
      case 'r': case 'R':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            reset(s1);
            cout << "   s1 has been reset and is now empty" << endl;
            break;
         case 2:
            reset(s2);
            cout << "   s2 has been reset and is now empty" << endl;
            break;
         case 3:
            reset(s3);
            cout << "   s3 has been reset and is now empty" << endl;
         }
         break;
      case 's': case 'S':
         objectNum = get_object_num();
         switch (objectNum)
         {
         case 1:
            cout << "   Size of s1 is " << size(s1) << endl;
            break;
         case 2:
            cout << "   Size of s2 is " << size(s2) << endl;
            break;
         case 3:
            cout << "   Size of s3 is " << size(s3) << endl;
         }
         break;
      case 'x':
         objectNum = get_object_num();
         delCount = 0;
         switch (objectNum)
         {
         case 1:
            if ( isEmpty(s1) )
               cout << "   s1 is empty" << endl;
            else
            {
               int minValue = findMin(s1);
               while ( delOne(s1, minValue) ) ++delCount;
               cout << "   " << delCount << " copies of " << minValue
                    << " has been deleted from s1" << endl;
            }
            break;
         case 2:
            if ( isEmpty(s2) )
               cout << "   s2 is empty" << endl;
            else
            {
               int minValue = findMin(s2);
               while ( delOne(s2, minValue) ) ++delCount;
               cout << "   " << delCount << " copies of " << minValue
                    << " has been deleted from s2" << endl;
            }
            break;
         case 3:
            if ( isEmpty(s3) )
               cout << "   s3 is empty" << endl;
            else
            {
               int minValue = findMin(s3);
               while ( delOne(s3, minValue) ) ++delCount;
               cout << "   " << delCount << " copies of " << minValue
                    << " has been deleted from s3" << endl;
            }
         }
         break;
      case 'X':
         objectNum = get_object_num();
         delCount = 0;
         switch (objectNum)
         {
         case 1:
            if ( isEmpty(s1) )
               cout << "   s1 is empty" << endl;
            else
            {
               int maxValue = findMax(s1);
               while ( delOne(s1, maxValue) ) ++delCount;
               cout << "   " << delCount << " copies of " << maxValue
                    << " has been deleted from s1" << endl;
            }
            break;
         case 2:
            if ( isEmpty(s2) )
               cout << "   s2 is empty" << endl;
            else
            {
               int maxValue = findMax(s2);
               while ( delOne(s2, maxValue) ) ++delCount;
               cout << "   " << delCount << " copies of " << maxValue
                    << " has been deleted from s2" << endl;
            }
            break;
         case 3:
            if ( isEmpty(s3) )
               cout << "   s3 is empty" << endl;
            else
            {
               int maxValue = findMax(s3);
               while ( delOne(s3, maxValue) ) ++delCount;
               cout << "   " << delCount << " copies of " << maxValue
                    << " has been deleted from s3" << endl;
            }
         }
         break;
      case 'q': case 'Q':
         cout << "Quit option selected...bye" << endl;
         break;
      default:
         cout << choice << " is not a valid option...try again"
              << endl;
      }
   }
   while (choice != 'q' && choice != 'Q');

   cin.ignore(999, '\n');
   cout << "Press Enter or Return when ready...";
   cin.get();
   return EXIT_SUCCESS;
}

void print_menu()
{
   cout << endl;
   cout << "The following choices are available: " << endl;
   cout << "  a  Query average for s1, s2 or s3" << endl;
   cout << "  A  Add s1, s2 or s3 to s1" << endl;
   cout << "  c  Set s3 to the combination of s1 and s2" << endl;
   cout << "  e  Check if s1, s2 or s3 is empty" << endl;
   cout << "  E  Check if any pair of {s1 s2 s3} is identical" << endl;
   cout << "  f  Find # of times a given value occurs in s1" << endl;
   cout << "  i  Insert a new value into s1, s2 or s3" << endl;
   cout << "  k  Remove 1 of a given value from s1, s2 or s3" << endl;
   cout << "  K  Remove all of a given value from s1, s2 or s3" << endl;
   cout << "  m  Query lowest value for s1, s2 or s3" << endl;
   cout << "  M  Query highest value for s1, s2 or s3" << endl;
   cout << "  p  Print s1, s2 or s3 (to stdout)" << endl;
   cout << "  r  Reset s1, s2 or s3 to become empty" << endl;
   cout << "  s  Query size for s1, s2 or s3" << endl;
   cout << "  x  Remove all lowest values from s1, s2 or s3" << endl;
   cout << "  X  Remove all highest values from s1, s2 or s3" << endl;
   cout << "  q  Quit this test program" << endl;
}

char get_user_command()
{
   char command;

   cout << "Enter choice: ";
   cin >> command;

   cout << command << " read." << endl;
   return command;
}

int get_object_num()
{
   int result;

   cout << "Enter object # (1 = s1, 2 = s2, 3 = s3) ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid integer input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter object # (1 = s1, 2 = s2, 3 = s3) ";
      cin  >> result;
   }
   // cin.ignore(999, '\n');

   while (result != 1 && result != 2 && result != 3)
   {
      cin.ignore(999, '\n');
      cerr << "Invalid object # (must be 1, 2 or 3)..." << endl;
      cout << "Re-enter object # (1 = s1, 2 = s2, 3 = s3) ";
      cin  >> result;
      while ( ! cin.good() )
      {
         cerr << "Invalid integer input..." << endl;
         cin.clear();
         cin.ignore(999, '\n');
         cout << "Re-enter object # (1 = s1, 2 = s2, 3 = s3) ";
         cin  >> result;
      }
      // cin.ignore(999, '\n');
   }

   cout << result << " read." << endl;
   return result;
}

int get_integer()
{
   int result;

   cout << "Enter integer value ";
   cin  >> result;
   while ( ! cin.good() )
   {
      cerr << "Invalid integer input..." << endl;
      cin.clear();
      cin.ignore(999, '\n');
      cout << "Re-enter integer value ";
      cin  >> result;
   }
   // cin.ignore(999, '\n');

   cout << result << " read." << endl;
   return result;
}

void print_to_cout(SortedInt src)
{
   for (int i = 1; i <= size(src); ++i)
      cout << valAt(src, i) << "  ";
   cout << endl;
}

