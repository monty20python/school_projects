#ifndef FILE_H
#define FILE_H
#include<iostream>
#include<vector>
#include<fstream>
#include<string>

void fin_graph( std::vector<std::vector<int> > &, std::string );
void fout_graph( std::vector<std::vector<int> >, std::string );
void time_csv( size_t, std::string );

#endif
