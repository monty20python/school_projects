#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include<vector>
#include<iostream>
#include<fstream>
#include<climits>
#include<cmath>
#include<chrono>

void dijkstra( std::vector<std::vector<int> >, std::vector<std::vector<int> >&, std::vector<int>&, std::vector<bool>&, size_t& );
int min_distance( std::vector<int> &, std::vector<bool> & );
void dijkstra_print( std::vector<std::vector<int> > );

#endif
