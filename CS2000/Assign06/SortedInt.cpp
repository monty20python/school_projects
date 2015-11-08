// FILE: SortedInt.cpp
//       Implementation file for SortedInt
//       (See SortedInt.h for documentation.)
// INVARIANT for SortedInt:
// (1) Entries of the SortedInt are stored in a one-dimensional,
//     compile-time array of integers whose size is MAX_SIZE;
//     the member variable data references the array.
// (2) # of entries the SortedInt currently contains is stored
//     in the member variable used.
// (3) Entries of SortedInt are stored sorted in non-decreasing
//     order from data[0] through data[used - 1].
// (4) We DON'T care what is stored in any of the array elements
//     from data[used] and beyond.

#include <iostream>
#include <cassert>
#include "SortedInt.h"
using namespace std;

bool isEmpty(const SortedInt& s)
{
   if ( s.used == 0 )
      return true;
   else
      return false;
}

int size(const SortedInt& s)
{  
   return s.used; 
}

int valAt(const SortedInt& s, int position)
{
   assert( s.used > 0 );
   assert( 1 <= position );
   assert( position <= s.used );
   return s.data[position - 1]; 
}

int findMin(const SortedInt& s)
{
   assert(s.used > 0 );
   int min = s.data[0];

   for( int i = 1; i < s.used; ++i )
   {
      if ( min > s.data[i] )
         min = s.data[i];
   }

   return min; 
}

int findMax(const SortedInt& s)
{
   assert(s.used > 0);
   int max = s.data[0];

   for ( int i = 1; i < s.used; ++i )
   {
      if ( max < s.data[i] )
         max = s.data[i];
   }
   
   return max; 
}

double findAvg(const SortedInt& s)
{
   assert(s.used > 0 );
   int sum = 0;
   double avg;

   for( int i = 0; i < s.used; ++i )
      sum += s.data[i];
   avg = static_cast<double>(sum) / s.used;

   return avg; 
}

int findFreq(const SortedInt& s, int target)
{
   int i = 0,
       count = 0;

   while(i < s.used )
   {
      if ( s.data[i] == target )
      {
         ++count;
         ++i;
      }
      else 
         ++i;
   } 

   return count; 
}

bool equal(const SortedInt& s1, const SortedInt& s2)
{
   if ( s1.used == s2.used )
   {
      for( int i = 0, j = 0; i < s1.used && j < s2.used; ++i, ++j)
      {
         if ( s1.data[i] != s2.data[j] )
            return false;
      }
      return true;
   }
   else
      return false; 
}

void reset(SortedInt& s)
{
   s.used = 0;
}

void insert(SortedInt& s, int newInt)
{
   assert( s.used < MAX_SIZE );
   int i = 0;
    
   for ( i = s.used - 1; i > 0 && s.data[i-1] > newInt; --i )
      s.data[i] = s.data[i-1];
   s.data[i] = newInt;
}

bool delOne(SortedInt& s, int target)
{
   for( int i = 0; i < s.used; ++i )
      if( s.data[i] == target )
      {
         while( i < s.used )
         {
            s.data[i] = s.data[i + 1];
            ++i;
         }
         --s.used;
         return true;
      }
   return false; 
}

void add(SortedInt& benend, SortedInt addend)
{
   assert((benend.used + addend.used) <= MAX_SIZE);
   benend.used = benend.used + addend.used;

   for( int i = addend.used, j = 0; i < benend.used 
        && j < addend.used; ++i, ++j)
      benend.data[i] = addend.data[j];
}

SortedInt combine(const SortedInt& s1, const SortedInt& s2)
{
   assert((s1.used + s2.used) <= MAX_SIZE);
   
   SortedInt result;

   result.used = s1.used + s2.used;

   for( int i = 0; i < s1.used; ++i )
      result.data[i] = s1.data[i];
   for( int j = s1.used; j < result.used; ++j )
      result.data[j] = s2.data[j];

   return result; 
}
