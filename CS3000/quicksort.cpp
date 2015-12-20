/***************
Name: David Bendel
****************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
#include <vector>

using namespace std;

const long ARRAY_SIZE = 500000;

void quick_sort( vector<long> &,  long,  long );
long pivot( long );

int main()
{
	vector<long> sortArray (ARRAY_SIZE);
	long left = 0, right = ARRAY_SIZE - 1;

	for( vector<long>::size_type i = 0; i < ARRAY_SIZE; ++i )
		cin >> sortArray[i];

    long pivot_init = pivot(right);

	swap(sortArray[left], sortArray[pivot_init]);

	clock_t t = clock();

	quick_sort( sortArray, left, right );

	t = clock() - t;

	cout << "It took " << t << " clicks (" << (((float)(t)) /  CLOCKS_PER_SEC) 
		 << " seconds)." << endl;

	return 0;
}

void quick_sort ( vector<long>& sortArray,  long left,  long right )
{ 
	if(left < right)
	{
        long l = left + 1, r = right;

        long pivot_pos = pivot(right);
        long pivot = sortArray[pivot_pos];

        while(l<r)
        {
            if(sortArray[l] <= pivot)
                l++;
            else if(sortArray[r] >= pivot)
                r--;
            else
                swap(sortArray[l],sortArray[r]);
        }

        if(sortArray[l] < pivot)
        {
            swap(sortArray[l],sortArray[left]);
            l--;
        }

        else
        {
            l--;
            swap(sortArray[l],sortArray[left]);
        }

        quick_sort(sortArray, left, l);
        quick_sort(sortArray, r, right);
    }
}

long pivot( long right )
{
    unsigned seed = clock();    // Horribly inefficent but it works.
    mt19937 generator(seed);    // Tried to pass seed from main, didn't work
	long pivot_pos = generator() % right;

	return pivot_pos;
}

	
