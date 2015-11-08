// FILE: SortedInt.cpp
//       Implementation file for the SortedInt class
//       (See SortedInt.h for documentation.)
// INVARIANT for the SortedInt class:
// (1) Entries of the SortedInt are stored in a one-dimensional,
//     compile-time array of integers whose size is MAX_SIZE;
//     the member variable data references the array.
// (2) # of entries the SortedInt currently contains is stored
//     in the member variable used.
// (3) Entries of SortedInt are stored sorted in non-decreasing
//     order from data[0] through data[used - 1].
// (4) We DON'T care what is stored in any of the array elements
//     from data[used] through data[MAX_SIZE - 1].

#include <iostream>
#include <cassert>
#include "SortedInt.h"
using namespace std;


SortedInt::SortedInt() : used(0)
{
   data[0] = 0;
}

bool SortedInt::isEmpty() const
{
   if ( used == 0 )
      return true;
   else
      return false;
}

int SortedInt::size() const
{
   return used;
}

int SortedInt::valAt(int position) const
{
   assert( size() > 0 );
   assert( 1 <= position );
   assert( position <= size() );
   return data[position - 1]; 
}

int SortedInt::findMin() const
{
   assert( size() > 0 );

   return data[0]; 
}

int SortedInt::findMax() const
{
   assert(used > 0);
   
   return data[used-1]; 
}

double SortedInt::findAvg() const
{
   assert( size() > 0 );
   int sum = 0;
   double avg;

   for( int i = 0; i < used; ++i )
      sum += data[i];
   avg = static_cast<double>(sum) / used;

   return avg; 
}

int SortedInt::findFreq(int target) const
{
   int i = 0,
       count = 0;

   while(i < used )
   {
      if ( data[i] == target )
      {
         ++count;
         ++i;
      }
      else 
         ++i;
   } 
   return count; 
}

bool SortedInt::equal(const SortedInt& other) const
{
   if ( used == other.used )
   {
      for( int i = 0, j = 0; i < used && j < other.used; ++i, ++j)
      {
         if ( data[i] != other.data[j] )
            return false;
      }
      return true;
   }
   else
      return false; 
}

void SortedInt::reset()
{
   used = 0;
}

void SortedInt::insert(int newInt)
{
   assert( size() < MAX_SIZE );
   int i;
 
   for ( i = used; i > 0 && data[i-1] > newInt; --i )
      data[i] = data[i-1];
   data[i] = newInt;
   ++used;  
}

bool SortedInt::delOne(int target)
{
   for( int i = 0; i < used; ++i )
      if( data[i] == target )
      {
         while( i < used - 1 )
         {
            data[i] = data[i + 1];
            ++i;
         }
         --used;
         return true;
      }
   return false; 
}

void SortedInt::add(SortedInt addend)
{
   assert((size() + addend.size()) <= MAX_SIZE);
   int addSize = addend.size();
   
   for( int i = 0; i < addSize; ++i)
      insert(addend.data[i]);
      

}

SortedInt combine(const SortedInt& s1, const SortedInt& s2)
{
   assert((s1.size() + s2.size()) <= SortedInt::MAX_SIZE);
   
   SortedInt result;
   
   result.add(s1);
   result.add(s2);

   return result; 
}
