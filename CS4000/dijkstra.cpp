#include "dijkstra.h"

int min_distance( std::vector<int> &distance, std::vector<bool> &set  )
{
	int min = std::numeric_limits<int>::max(), mindex;

	for(int i = 0; i < distance.size(); ++i)
	{
		if(set[i] == false && distance[i] <= min)
		{
			min = distance[i];
			mindex = i;
		}
	}

	return mindex;
}

void dijkstra( std::vector<std::vector<int> > graph, std::vector<std::vector<int> > &dist, 
		std::vector<int> &distance, std::vector<bool> &set, size_t &d_ns )
{
	std::chrono::time_point<std::chrono::high_resolution_clock> begin, end;

	begin = std::chrono::high_resolution_clock::now();
	for( int k = 0; k < graph.size(); k++)
	{
		distance[k] = 0;
		for( int i = 0; i < graph.size(); ++i )
		{
			int mindex = min_distance(distance, set);
		
			set[mindex] = true;

			for(int j = 0; j < graph.size(); ++j)
			{
				if(!(set[j]) && graph[mindex][j] && distance[mindex] != 
				   std::numeric_limits<int>::max()
				   && distance[mindex] + graph[mindex][j] < distance[j])
				{
					distance[j] = distance[mindex] + graph[mindex][j];
				}
			}
		}

		dist.push_back(distance);
		distance.clear();
		set.clear();
		distance.resize(graph.size(), std::numeric_limits<int>::max());
		set.resize(graph.size(), false);

	}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	d_ns = ns.count();
}

void dijkstra_print ( std::vector<std::vector<int> > dist ) 
{
	for( int i = 0; i < dist.size(); i++ )
	{	
		for( int j = 0; j < dist.size(); j++ )
		{
				std::cout << dist[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
