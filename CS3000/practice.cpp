/***************
Name: David Bendel
Course: CSCE 3110.002
Assignment: Program 1
Due Date: January 30, 2015 11:55pm
****************/

#include <iostream>

using namespace std;

int main()
{
	const int ARRAY_SIZE = 10;							
	int intergerArray[ARRAY_SIZE][ARRAY_SIZE] = {{0}};  //Initialize Array to 0

	for( int i = 0; i < ARRAY_SIZE; ++i)
		for(int j = 0; j < ARRAY_SIZE; ++j)
			cin >> intergerArray[i][j];		//Read file into array

	for( int i = 0; i < ARRAY_SIZE; ++i)
	{
		for(int j = 0; j < ARRAY_SIZE; ++j)
			cout << intergerArray[i][j] << " "; //Output array to screen

		cout << endl;
	}

	return 0;
}