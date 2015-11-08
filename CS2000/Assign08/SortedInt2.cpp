// FILE: SortedInt2.cpp
//       Implementation file for the SortedInt2 class
//       (See SortedInt2.h for documentation.)
// INVARIANT for the SortedInt2 class:
// (1) Entries of the SortedInt2 are stored in a one-dimensional,
//     run-time (dynamic) array of integers referenced by the
//     member variable data (i.e., the starting address of the
//     the array is stored in data); the capacity of the array
//     is stored in the member variable capacity.
// (2) # of entries the SortedInt2 currently contains is stored
//     in the member variable used.
// (3) Entries of SortedInt2 are stored sorted in non-decreasing
//     order from data[0] through data[used - 1].
// (4) We DON'T care what is stored in any of the array elements
//     from data[used] through data[capacity - 1].
//
// DOCUMENTATION for private member (helper) function:
//   void resize(int new_capacity)
//     Pre:  (none)
//     Post: The capacity (size of the dynamic array) of the
//           invoking SortedInt2 is changed to new_capacity, with
//           the provision that the new capacity should never be
//           less than used (so that the existing collection can
//           still be represented) AND should be at least 1 (used
//           may be 0 and we don't want to request a dynamic
//           array of size 0). The collection represented by the
//           invoking SortedInt2 remains unchanged.

#include "SortedInt2.h"
#include <iostream>
#include <cassert>

using namespace std;

void SortedInt2::resize(int new_capacity)
{
   if( new_capacity <= used )
      new_capacity = ( 1.5 * used) + 1;
   if( new_capacity < DEFAULT_CAPACITY )
      new_capacity = DEFAULT_CAPACITY;

   capacity = new_capacity;
   int* newData = new int [capacity];

   for( int i = 0; i < used; ++i )
      newData[i] = data[i];
   data = newData;
}

SortedInt2::SortedInt2(int init_capacity) : capacity(init_capacity), used(0)
{
   if(capacity < DEFAULT_CAPACITY)
      capacity = DEFAULT_CAPACITY;
   data = new int [capacity];
}

SortedInt2::SortedInt2(const SortedInt2& src) : capacity(src.capacity), used(src.used)
{
   data = new int [capacity];
   for( int i = 0; i < used; ++i )
      data[i] = src.data[i];
}

SortedInt2::~SortedInt2()
{
   delete [] data;
}

bool SortedInt2::isEmpty() const
{
   if ( used == 0 )
      return true;
   else
      return false;
}

int SortedInt2::size() const
{
   return used;
}

int SortedInt2::valAt(int position) const
{
   assert( size() > 0 );
   assert( 1 <= position );
   assert( position <= size() );

   return data[position - 1]; 
}

int SortedInt2::findMin() const
{
   assert( size() > 0 );

   return data[0]; 
}

int SortedInt2::findMax() const
{
   assert(size() > 0);
   
   return data[used-1]; 
}

double SortedInt2::findAvg() const
{
   assert( size() > 0 );
   int sum = 0;
   double avg;

   for( int i = 0; i < used; ++i )
      sum += data[i];
   avg = static_cast<double>(sum) / used;

   return avg; 
}

int SortedInt2::findFreq(int target) const
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

SortedInt2& SortedInt2::operator=(const SortedInt2& rhs)
{
   if( this != &rhs )
   {
      int* newData = new int [rhs.capacity];
      for( int i = 0; i < rhs.used; ++i )
         newData[i] = rhs.data[i];
      delete [] data;
      data = newData;
      capacity = rhs.capacity;
      used = rhs.used;
   }
   return *this;
}

void SortedInt2::reset()
{
   used = 0;
}


void SortedInt2::insert(int newInt)
{
   int i;
 
   if( used >= capacity )
      resize(used);

   for ( i = used; i > 0 && data[i-1] > newInt; --i )
      data[i] = data[i-1];
   data[i] = newInt;
   ++used;  
}

bool SortedInt2::delOne(int target)
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

void SortedInt2::operator+=(SortedInt2 addend)
{
   int addSize = addend.size();
   
   for( int i = 0; i < addSize; ++i)
      insert(addend.data[i]);
}

bool operator==(const SortedInt2& lhs, const SortedInt2& rhs)
{
   if ( lhs.used == rhs.used )
   {
      for( int i = 0, j = 0; i < lhs.used && j < rhs.used; ++i, ++j)
      {
         if ( lhs.data[i] != rhs.data[j] )
            return false;
      }
      return true;
   }
   else
      return false; 
}

SortedInt2 operator+(const SortedInt2& s1, const SortedInt2& s2)
{   
   SortedInt2 result(s1);

   result += s2;
   
   return result; 
}

