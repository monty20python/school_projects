/***************
Name: David Bendel
****************/

#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

const int SIZE = 25;
int array[SIZE][SIZE];
bool seen[SIZE];

void dfs(int index)
{
	seen[index] = true;
	for(int j = 0; j < SIZE; ++j)
	{
		if(!seen[j] && array[index][j] != 0)
		{
			cout << array[index][j] << " ";
			dfs(j);
		}
	}

}

int main()
{

	for(int i = 0; i < SIZE; ++i )
		for(int j = 0; j < SIZE; ++j )
			cin >> array[i][j];

	cout << "DFS: ";
	dfs(0);

	cout << endl;

	return 0;
}
