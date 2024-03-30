#pragma once

typedef struct Graph Graph;

Graph *initGraph(int num);

void addEdge(Graph *graph, int from, int to, int length);

void deleteGraph(Graph *graph);

void dijkstra(Graph *graph, int startVertex);

void printInfoAboutGraph(Graph *graph);

Graph *readInputFromFile(char *fileName);

void distributeCities(Graph *graph);
