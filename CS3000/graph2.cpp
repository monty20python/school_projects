/***************
Name: David Bendel
****************/

#include <iostream>
#include <ctime>
#include <climits>
#include <vector>

using namespace std;

int min_distance( int distance[], bool set[] )
{
	int min = INT_MAX, mindex;

	for(int i = 0; i < 25; ++i)
	{
		if(set[i] == false && distance[i] <= min)
		{
			min = distance[i];
			mindex = i;
		}
	}

	return mindex;
}

void dijkstra(int graph[25][25], int source )
{
	int distance[25];
	bool set[25];
	vector<int> path;

	for( int i = 0; i < 25; ++i )
	{
		distance[i] = INT_MAX;
		set[i] = false;
	}

	distance[source] = 0;

	for( int i = 0; i < 24; ++i )
	{
		clock_t t;

		t = clock();
		int mindex = min_distance(distance, set);

		set[mindex] = true;

		for(int j = 0; j < 25; ++j)
		{
			if(!(set[j]) && graph[mindex][j] && distance[mindex] != INT_MAX
				&& distance[mindex] + graph[mindex][j] < distance[j])
			{
				distance[j] = distance[mindex] + graph[mindex][j];
				path.push_back(j + 1);
			}
		}

		t = clock() - t;

		if( !(path.empty()) && distance[i] != INT_MAX && distance[i] != 0)
		{
			cout << t << " clocks " << static_cast<double>(t)/CLOCKS_PER_SEC << " seconds " <<  "1 ";
			for(int l = 0; l < path.size(); ++l)
				cout << path[l] << " ";
			cout << endl;
			path.clear();
		}
	}
}

int main()
{
	int graph[25][25];

	for(int i = 0; i < 25; ++i)
		for(int j = 0; j < 25; ++j)
			cin >> graph[j][i];

	dijkstra( graph, 0 );

	return 0;
}
