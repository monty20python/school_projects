#include "floyd_warshall.h"

void floyd_warshall( std::vector<std::vector<int> > &dist,
	             size_t &fw_ns  	)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> begin, end;

	begin = std::chrono::high_resolution_clock::now();
	for(int x = 0; x < dist.size(); x++)
		for(int y = 0; y < dist.size(); y++)
			for(int z = 0; z < dist.size(); z++)
			{
				if( dist[y][x] + dist[x][z] < dist[y][z] )
					dist[y][z] = dist[y][x] + dist[x][z];
			}
	end = std::chrono::high_resolution_clock::now();
	std::chrono::nanoseconds ns = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
	fw_ns = ns.count();

}

void floyd_warshall_print( std::vector<std::vector<int> > dist )
{
	for(int i = 0; i < dist.size(); i++ )
	{
		for(int j = 0; j < dist.size(); j++ )
			std::cout << dist[i][j] << " ";
		std::cout << std::endl;
	}
}	
