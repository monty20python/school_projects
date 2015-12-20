/***************
Name: David Bendel
****************/


#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

const int SIZE = 2826;


int hash_fn( string temp )
{
	int tmp = temp.length();
	long fib;

	// uses n = temp.length() to compute the nth fibbonaci number
	fib = (1/sqrt(5))*(pow(((1+sqrt(5))/2), tmp) - pow(((1 - sqrt(5))/2), tmp));

	tmp = fib % 100;
	return tmp;
}

int main()
{
	vector<vector<string> > table;
	string input[SIZE];

	for(int i = 0; i < SIZE; ++i)
	{
		cin >> input[i];
	}

	for(int i = 0; i < 100; ++i)
	{
		vector<string> row;
		table.push_back(row);
	}

	for( int j = 0; j < SIZE; ++j)
	{
		string temp;
		int key;
		temp = input[j];
		key = hash_fn(temp);
		table[key].push_back(temp);
	}



	for(int i = 0; i < 100; ++i )
		for( int j = 0; j < table[i].size(); ++j)
			cout << table[i][j] << endl;
		

	return 0;
}
