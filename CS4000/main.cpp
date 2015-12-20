#include<iostream>
#include<climits>
#include<random>
#include<chrono>
#include<fstream>
#include<vector>
#include<cmath>
#include<string>

#include "dijkstra.h"
#include "floyd_warshall.h"
#include "file.h"
#include "graph_gen.h"

int main()
{
	std::vector<std::vector<int> > graph; 
	int choice;
	int N, weight;
	std::vector<std::vector<int> > dist1, dist2;
	std::vector<bool> set;
	std::vector<int>distance;
	size_t d_ns, fw_ns;

	std::cout << std::endl << "Options: " << std::endl << "1) Generate Graph " << std::endl 
	          << "2) Input graph from file" << std::endl << "3) Run Test Suite" << std::endl
		  << "(1,2,3): ";
	std::cin >> choice;
	std::cout << std::endl;

	while( choice != 1 && choice != 2 && choice != 3 )
	{
		std::cout << "Please choose either 1, 2, or 3: " << std::endl;
		std::cin >> choice;

		if( choice == 1 || choice == 2 || choice == 3 )
			break;
	}

	if( choice == 1 )
	{
		std::cout << "Choose graph size: ";
		std::cin >> N;
		std::cout << "Choose max weight range: ";
		std::cin >> weight;
		graph_gen(graph, N, weight);
	}
	else if( choice == 2 )
	{
		std::string input_file, output_file;
		std::cout << "Enter filename: ";
		std::cin >> input_file;
		fin_graph( graph, input_file );
	}
	else
	{
		int size_array[5] = {50,100,250,500,1000};	
		weight = 100;
		
		for(int i = 0; i < 5; i++ )
		{
			graph_gen(graph,size_array[i],weight);	
			distance.resize(size_array[i], std::numeric_limits<int>::max());
			set.resize(size_array[i], false);

			std::string type3 = "dijkstra";

			dijkstra(graph, dist1, distance, set,  d_ns );

			std::cout << std::endl << "It took " << d_ns << " ns to run Dijkstra:" 
				  << std::endl;
			time_csv( d_ns, type3 );

			std::string type4 = "floyd_warshall";
			dist2 = graph;

			floyd_warshall( dist2, fw_ns);

			std::cout << std::endl << "It took " << fw_ns << " ns to run Floyd-Warshall:" 
				  << std::endl << std::endl;
			time_csv( fw_ns, type4 );
			set.clear();
			dist1.clear();
			dist2.clear();
			distance.clear();
			graph.clear();
		}
	}

	if(choice != 3 )
	{
		std::cout << std::endl;
	
		std::cout << "Choose algorithm: " << std::endl << "1) Dijkstra" << std::endl
	       	          << "2) F-W" << std::endl << "3) Both" << std::endl  << "Enter 1),  2), or 3): ";
		std::cin >> choice;

		if( choice == 1 )
		{
			std::string graph_type = "dijkstra_out.txt";
			std::string type = "dijkstra";
			set.resize(graph.size(), false);
			distance.resize(graph.size(), std::numeric_limits<int>::max());
	
			dijkstra(graph, dist1, distance, set,  d_ns );

			std::cout << std::endl << "It took " << d_ns << " ns to run Dijkstra:" 
				  << std::endl << std::endl;
			dijkstra_print( dist1 );
			fout_graph( dist1, graph_type );
			time_csv( d_ns, type );
		}
		else if( choice == 2 )
		{
			std::string graph_type = "floyd_warshall.txt";
			std::string type = "floyd_warshall";
			dist2 = graph;
	
			floyd_warshall( dist2, fw_ns);

			std::cout << std::endl << "It took " << fw_ns << " ns to run Floyd-Warshall:" 
				  << std::endl << std::endl;

			floyd_warshall_print( dist2 );
			fout_graph( dist2, graph_type );
			time_csv( fw_ns, type );

		}
		else if( choice == 3 )
		{
			std::string graph_type1 = "dijkstra_out.txt";
			std::string graph_type2 = "floyd_warshall_out.txt";
			std::string type1 = "dijkstra", type2 = "floyd_warshall";
			dist2 = graph;
			set.resize(graph.size(), false);
			distance.resize(graph.size(), std::numeric_limits<int>::max());

			dijkstra( graph, dist1, distance, set,  d_ns );
			floyd_warshall( dist2, fw_ns);

			std::cout << std::endl << "It took " << d_ns << " ns to run Dijkstra:" 
				  << std::endl << std::endl;
			dijkstra_print( dist1 );

			std::cout << std::endl << "It took " << fw_ns << " ns to run Floyd-Warshall:" 
				  << std::endl << std::endl;
			floyd_warshall_print( dist2 );

			fout_graph( dist1, graph_type1 );
			fout_graph( dist2, graph_type2 );
			time_csv(d_ns, type1);
			time_csv(fw_ns, type2);
		}
	}	
}

