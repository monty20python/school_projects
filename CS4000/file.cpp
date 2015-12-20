#include "file.h"

void fin_graph( std::vector<std::vector<int> > &graph, std::string file_in )
{
	std::ifstream fin;
	fin.open(file_in);
	std::string line;
	long long M;

	if(!fin)
	{
		std::cerr << std::endl << "Input file failed to open" << std::endl
			  << "Terminating Program" << std::endl;
		fin.close();

		std::_Exit(EXIT_FAILURE);
		std::abort();
	}

	std::cout << "Enter matrix size: ";
	std::cin >> M;
	graph.resize(M, std::vector<int>(M));

	for( int i = 0; i < M; i++)
		for( int j = 0; j < M; j++)
			fin >> graph[i][j];		
	fin.close();
}

void fout_graph( std::vector<std::vector<int> > graph, std::string graph_type )
{
	std::ofstream fout;
	fout.open(graph_type);

	if( !fout )
	{
		std::cout << std::endl << std::endl
		          << "Output file failed to open" << std::endl
		          << "Terminating Program" << std::endl;
		fout.close();

		std::_Exit(EXIT_FAILURE);
		std::abort();
	}

	for(int i = 0; i < graph.size(); i++)
	{
		for(int j = 0; j < graph.size(); j++)
			fout << graph[i][j] << " ";
		fout << std::endl;
	}

	fout.close();
}

void time_csv( size_t ns, std::string type )
{
	std::ofstream out;
	out.open(type.append(".csv"), std::ios_base::app);

	out << ns << ',' << ' ';

}	
