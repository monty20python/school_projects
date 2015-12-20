/***************
Name: David Bendel
****************/

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

const int ARRAY_SIZE = 500000;

void merge_sort( vector<long>&, vector<long>&, long, long);
void merge( vector<long>&, vector<long>&, long, long, long);


int main()
{

	vector<long> sortArray(ARRAY_SIZE);
	vector<long> tempArray(ARRAY_SIZE);
	long left = 0, right = ARRAY_SIZE-1;

	for( vector<long>::size_type i = 0; i < ARRAY_SIZE; ++i )
		cin >> sortArray[i];

	clock_t t = clock();

	merge_sort( sortArray, tempArray, left, right );

	t = clock() - t;

	cout << "It took " << t << " clicks (" << (((float)(t)) /  CLOCKS_PER_SEC) 
		 << " seconds)." << endl;

	return 0;
}

void merge_sort( vector<long>& sortArray, vector<long>& tempArray, long left, long right )
{
	if( left < right )
	{
		long mid;
		mid = ((left + right ) / 2);

		merge_sort( sortArray, tempArray, left, mid);
		merge_sort( sortArray, tempArray, mid + 1, right);
		merge( sortArray, tempArray, left, mid + 1, right );
	}
}

void merge( vector<long>& sortArray, vector<long>& tempArray, 
			long left, long rightPos, long right )
{
	long leftEnd = rightPos - 1;
	long tempPos = left;
	long numElements = right - left + 1;

	while( left <= leftEnd && rightPos <= right)
	{
		if( sortArray[left] <= sortArray[rightPos])
			tempArray[tempPos++] = move( sortArray[left++]);
		else
			tempArray[tempPos++] = move( sortArray[rightPos++]);
	}

	while( left <= leftEnd )
		tempArray[tempPos++] = move(sortArray[left++]);

	while( rightPos <= right)
		tempArray[tempPos++] = move(sortArray[rightPos++]);

	for( vector<long>::size_type i = 0; i < numElements; ++i, --right)
		sortArray[right] = move( tempArray[right]);
}
