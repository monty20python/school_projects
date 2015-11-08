// FILE: SortedInt.h - header file for SortedInt
//
// CONSTANT
//   const int MAX_SIZE = ____
//   MAX_SIZE is the highest # of entries that can
//     be accommodated.
//
// FUNCTIONS
//   bool isEmpty(const SortedInt& s)
//     Pre:  (none)
//     Post: True is returned if the s is empty,
//           otherwise false is returned.
//   int size(const SortedInt& s)
//     Pre:  (none)
//     Post: The # of entries in s is returned.
//   int valAt(const SortedInt& s, int position)
//     Pre:  s is not empty and 1 <= position <= size()
//     Post: The value of the entry with the given position in s
//           is returned.
//     Note: For a non-empty SortedInt s, the entry with the lowest
//           value is at position 1 and the entry with the highest
//           value is at a position given by size(s).
//   int findMin(const SortedInt& s)
//     Pre:  s is not empty.
//     Post: The lowest value in s is returned.
//   int findMax(const SortedInt& s)
//     Pre:  s is not empty.
//     Post: The highest value in s is returned.
//   double findAvg(const SortedInt& s)
//     Pre:  s is not empty.
//     Post: The average of s is returned.
//   int findFreq(const SortedInt& s, int target)
//     Pre:  (none)
//     Post: The # of times in which target occurs in s is returned.
//   bool equal(const SortedInt& s1, const SortedInt& s2)
//     Pre:  (none)
//     Post: True is returned if the s1 is equal or identical to s2,
//           otherwise false is returned.
//     Note: Two SortedInt's are equal (identical) if they both
//           contain the same # of entries AND the values of every
//           pair of corresponding entries are equal.
//   void reset(SortedInt& s)
//     Pre:  (none)
//     Post: s is set to empty.
//   void insert(SortedInt& s, int newInt)
//     Pre:  size(s) < MAX_SIZE
//     Post: A new entry with value newInt is added to s.
//   bool delOne(SortedInt& s, int target)
//     Pre:  (none)
//     Post: If target is found to occur one of more times in s,
//           then the first occurrence of target is removed from s
//           and true is returned, otherwise s is unchanged and
//           false is returned.
//   void add(SortedInt& benend, SortedInt addend)
//     Pre:  ( size(benend) + size(addend) ) <= MAX_SIZE
//     Post: All entries in addend are added to benend.
//     NOTE: addend is allowed to be benend itself.
//     QUIZ: Can you see why addend is not passed by const reference?
//   SortedInt combine(const SortedInt& s1, const SortedInt& s2)
//     Pre:  ( size(s1) + size(s2) ) <= MAX_SIZE
//     Post: A SortedInt containing copies of all the entries in s1
//           and s2 is returned.

#ifndef SortedInt_H
#define SortedInt_H

const int MAX_SIZE = 10;

struct SortedInt
{
   int data[MAX_SIZE];
   int used;
};

bool isEmpty(const SortedInt& s);
int size(const SortedInt& s);
int valAt(const SortedInt& s, int position);
int findMin(const SortedInt& s);
int findMax(const SortedInt& s);
double findAvg(const SortedInt& s);
int findFreq(const SortedInt& s, int target);
bool equal(const SortedInt& s1, const SortedInt& s2);
void reset(SortedInt& s);
void insert(SortedInt& s, int newInt);
bool delOne(SortedInt& s, int target);
void add(SortedInt& benend, SortedInt addend);
SortedInt combine(const SortedInt& s1, const SortedInt& s2);

#endif

