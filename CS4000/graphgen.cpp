#include"graph_gen.h"

void graph_gen( std::vector<std::vector<int> > &graph, int N, int weight )
{
	std::chrono::time_point<std::chrono::high_resolution_clock> time =
	       	std::chrono::high_resolution_clock::now();
       	std::chrono::nanoseconds ns =
	       	std::chrono::duration_cast<std::chrono::nanoseconds>(time.time_since_epoch());
	
	size_t new_seed = ns.count();
	std::mt19937_64 generator;
	generator.seed(new_seed);
	
	graph.resize(N,std::vector<int>(N,0));
	
	graph[0][0] = 0;
	for(int i = 0; i < N; ++i)
	{
		for(int j = 0; j < N; ++j)
		{
			if( i != j )
			{
				graph[i][j] = (generator() % weight) + 1;
				graph[j][i] = (generator() % weight) + 1;
			}
			else
			{
				graph[j][i] = 0;
			}
		}

	}
}
