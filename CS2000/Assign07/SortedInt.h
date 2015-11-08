// FILE: SortedInt.h - header file for SortedInt class
//
// CONSTANT
//   static const int MAX_SIZE = ____
//     SortedInt::MAX_SIZE is the highest # of entries that can
//     be accommodated.
//
// CONSTRUCTOR
//   SortedInt()
//     Pre:  (none)
//     Post: The invoking SortedInt is initialized to an empty
//           SortedInt (i.e., one that contains no entries).
//
// CONSTANT MEMBER FUNCTIONS (ACCESSORS)
//   bool isEmpty() const
//     Pre:  (none)
//     Post: True is returned if the invoking SortedInt is empty,
//           otherwise false is returned.
//   int size() const
//     Pre:  (none)
//     Post: The # of entries in the invoking SortedInt is returned.
//   int valAt(int position) const
//     Pre:  The invoking SortedInt is not empty and
//           position >= 1 and position <= size()
//     Post: The value of the entry with the given position in the
//           invoking SortedInt is returned.
//     Note: For a non-empty SortedInt, the entry with the lowest
//           value is at position 1 and the entry with the highest
//           value is at a position given by size().
//   int findMin() const
//     Pre:  The invoking SortedInt is not empty.
//     Post: The lowest value in the invoking SortedInt is returned.
//   int findMax() const
//     Pre:  The invoking SortedInt is not empty.
//     Post: The highest value in the invoking SortedInt is returned.
//   double findAvg() const
//     Pre:  The invoking SortedInt is not empty.
//     Post: The average of the invoking SortedInt is returned.
//   int findFreq(int target) const
//     Pre:  (none)
//     Post: The # of times in which target occurs in the invoking
//           SortedInt is returned.
//   bool equal(const SortedInt& other) const
//     Pre:  (none)
//     Post: True is returned if the invoking SortedInt is equal or
//           identical to other, otherwise false is returned.
//     Note: Two SortedInt's are equal (identical) if they both
//           contain the same # of entries AND the values of every
//           pair of corresponding entries are equal.
//
// MODIFICATION MEMBER FUNCTIONS (MUTATORS)
//   void reset()
//     Pre:  (none)
//     Post: The invoking SortedInt is set to empty.
//   void insert(int newInt)
//     Pre:  size() < MAX_SIZE
//     Post: A new entry with value newInt is added to the invoking
//           SortedInt.
//   bool delOne(int target)
//     Pre:  (none)
//     Post: If target is found to occur one of more times in the
//           invoking SortedInt, then the first occurrence of target
//           is removed from the invoking SortedInt and true is
//           returned, otherwise the invoking SortedInt is unchanged
//           and false is returned.
//   void add(SortedInt addend)
//     Pre:  ( size() + addend.size() ) <= MAX_SIZE
//     Post: All entries in addend are added to the invoking SortedInt.
//     NOTE: addend is allowed to be the invoking itself.
//     QUIZ: Can you reason why addend is not passed by const reference?
//
// NON-MEMBER FUNCTIONS
//   SortedInt combine(const SortedInt& s1, const SortedInt& s2)
//     Pre:  ( s1.size() + s2.size() ) <= MAX_SIZE
//     Post: A SortedInt containing copies of all the entries in s1
//           and s2 is returned.

#ifndef SortedInt_H
#define SortedInt_H

class SortedInt
{
public:
   static const int MAX_SIZE = 10;
   SortedInt();
   bool isEmpty() const;
   int size() const;
   int valAt(int position) const;
   int findMin() const;
   int findMax() const;
   double findAvg() const;
   int findFreq(int target) const;
   bool equal(const SortedInt& other) const;
   void reset();
   void insert(int newInt);
   int delMin();
   int delMax();
   bool delOne(int target);
   void add(SortedInt addend);

private:
   int data[MAX_SIZE];
   int used;
};

SortedInt combine(const SortedInt& s1, const SortedInt& s2);

#endif
