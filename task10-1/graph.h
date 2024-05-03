#pragma once

// a graph stored as an adjacency matrix and containing information about governments and their cities
typedef struct Graph Graph;

// add new vertex to graph
int addEdge(Graph *graph, int from, int to, int length);

// delete graph and free memory
void deleteGraph(Graph **graph);

// print the shortest distance from each vertex to each and the number of the government to which it belongs
void printInfoAboutGraph(Graph *graph);

// create a graph based on information about edges and capitals from a file
Graph *readInputFromFile(char *fileName);

// distribute all vertices according to the given capitals
void distributeCities(Graph *graph);
