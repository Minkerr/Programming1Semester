#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define GRAPH_SIZE 16
#define INF 1000000

typedef struct Graph {
    int edges[GRAPH_SIZE][GRAPH_SIZE];
    int governmentMarks[GRAPH_SIZE];
    int shortestDistance[GRAPH_SIZE][GRAPH_SIZE];
    int vertexNum;
} Graph;

Graph *initGraph(int num) {
    Graph *graph = malloc(sizeof(Graph));
    graph->vertexNum = num;
    for (int i = 0; i < GRAPH_SIZE; i++) {
        graph->governmentMarks[i] = 0;
        for (int j = 0; j < GRAPH_SIZE; j++) {
            graph->edges[i][j] = 0;
            if (i == j) {
                graph->shortestDistance[i][j] = 0;
            } else {
                graph->shortestDistance[i][j] = INF;
            }
        }
    }
    return graph;
}

void addEdge(Graph *graph, int from, int to, int length) {
    if (from <= graph->vertexNum && to <= graph->vertexNum) {
        from--;
        to--;
        graph->edges[from][to] = length;
        graph->edges[to][from] = length;
    }
}

void deleteGraph(Graph *graph) {
    free(graph);
}

int minDistanceVertex(int dist[], int visited[], int size) {
    int min = INF, minIndex;
    for (int v = 0; v < size; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(Graph *graph, int startVertex) {
    int size = graph->vertexNum;
    int dist[size];
    int visited[size];
    for (int i = 0; i < size; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = minDistanceVertex(dist, visited, size);
        visited[u] = 1;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph->edges[u][v] && dist[u] != INF && dist[u] + graph->edges[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->edges[u][v];
            }
        }
    }

    for (int i = 0; i < size; i++) {
        graph->shortestDistance[startVertex][i] = dist[i];
    }
}

void printInfoAboutGraph(Graph *graph) {
    printf("The shortest distances: ");
    for (int j = 0; j < graph->vertexNum; j++) {
        printf("\n%d: \n", j + 1);
        for (int i = 0; i < graph->vertexNum; i++) {
            printf("%d ", graph->shortestDistance[j][i]);
        }
    }
    printf("\nVertexes and their government number: \n");
    for (int i = 0; i < graph->vertexNum; i++) {
        printf("%d %d\n", i + 1, graph->governmentMarks[i]);
    }
}

void markCity(Graph *graph, int city, int num) {
    graph->governmentMarks[--city] = num;
}

Graph *readInputFromFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    int n;
    int m;
    fscanf_s(file, "%d %d", &n, &m);
    Graph *graph = initGraph(n);
    for (int i = 0; i < m; i++) {
        int from;
        int to;
        int len;
        fscanf_s(file, "%d %d %d", &from, &to, &len);
        addEdge(graph, from, to, len);
    }
    int k;
    fscanf_s(file, "%d", &k);
    for (int i = 0; i < k; i++) {
        int city;
        fscanf_s(file, "%d", &city);
        markCity(graph, city, i + 1);
    }
    fclose(file);
    return graph;
}

void markTheNearestNotMarkedVertex(Graph *graph, int capital) {
    int minIndex = 0;
    int minDist = INF;
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->governmentMarks[i] == 0 && graph->shortestDistance[capital][i] < minDist) {
            minDist = graph->shortestDistance[capital][i];
            minIndex = i;
        }
    }
    graph->governmentMarks[minIndex] = graph->governmentMarks[capital]; //mark the found the nearest city with a number of capital
}

void distributeCities(Graph *graph) {
    int numberOfCapitals = 0;
    int listOfCapitals[GRAPH_SIZE];
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->governmentMarks[i] > 0) {
            dijkstra(graph, i);
            listOfCapitals[numberOfCapitals] = i;
            numberOfCapitals++;
        }
    }
    int counter = 0;
    for (int i = 0; i < graph->vertexNum - numberOfCapitals; i++) {
        markTheNearestNotMarkedVertex(graph, listOfCapitals[counter]);
        counter = (counter + 1) % numberOfCapitals;
    }
}


