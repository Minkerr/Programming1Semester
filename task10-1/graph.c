#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

#define GRAPH_SIZE 16
#define INCORRECT_INPUT (-1)
#define GRAPH_IS_NULL (-2)

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
                graph->shortestDistance[i][j] = INT_MAX;
            }
        }
    }
    return graph;
}

int addEdge(Graph *graph, int from, int to, int length) {
    if (graph == NULL) {
        return GRAPH_IS_NULL;
    }
    if (from <= graph->vertexNum && to <= graph->vertexNum) {
        from--;
        to--;
        graph->edges[from][to] = length;
        graph->edges[to][from] = length;
        return 0;
    } else {
        return INCORRECT_INPUT;
    }
}

void deleteGraph(Graph **graph) {
    free(*graph);
    graph = NULL;
}

int minDistanceVertex(const int dist[], const bool visited[], int size) {
    int min = INT_MAX;
    int minIndex = 0;
    for (int v = 0; v < size; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(Graph *graph, int startVertex) {
    int size = graph->vertexNum;
    int dist[GRAPH_SIZE] = {0};
    bool visited[GRAPH_SIZE] = {false};
    for (int i = 0; i < size; i++) {
        dist[i] = INT_MAX;
    }
    dist[startVertex] = 0;

    for (int count = 0; count < size - 1; count++) {
        int u = minDistanceVertex(dist, visited, size);
        visited[u] = true;

        for (int v = 0; v < size; v++) {
            if (!visited[v] && graph->edges[u][v] && dist[u] != INT_MAX && dist[u] + graph->edges[u][v] < dist[v]) {
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
    if (file == NULL) {
        return NULL;
    }
    int n = 0;
    int m = 0;
    fscanf_s(file, "%d %d", &n, &m);
    Graph *graph = initGraph(n);
    for (int i = 0; i < m; i++) {
        int from = 0;
        int to = 0;
        int len = 0;
        fscanf_s(file, "%d %d %d", &from, &to, &len);
        int addingResult = addEdge(graph, from, to, len);
        if (addingResult != 0) {
            return NULL;
        }
    }
    int k = 0;
    fscanf_s(file, "%d", &k);
    for (int i = 0; i < k; i++) {
        int city = 0;
        fscanf_s(file, "%d", &city);
        markCity(graph, city, i + 1);
    }
    fclose(file);
    return graph;
}

void dfs(Graph *graph, int capital, bool *visited) {
    visited[capital] = true;
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->edges[capital][i] && !visited[i]
            && (graph->governmentMarks[i] == graph->governmentMarks[capital] || graph->governmentMarks[i] == 0)) {
            dfs(graph, i, visited);
        }
    }
}

bool markTheNearestAvailableVertex(Graph *graph, int capital) {
    int minIndex = -1;
    int minDist = INT_MAX;
    bool visited[GRAPH_SIZE] = {false};
    dfs(graph, capital, visited);
    for (int i = 0; i < graph->vertexNum; i++) {
        if (graph->governmentMarks[i] == 0 && graph->shortestDistance[capital][i] < minDist && visited[i]) {
            minDist = graph->shortestDistance[capital][i];
            minIndex = i;
        }
    }
    if (minIndex != -1) {
        graph->governmentMarks[minIndex] = graph->governmentMarks[capital];
        return true;
    } else {
        return false;
    }
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
    int turnCounter = 0;
    int notMarkedVertexesLeft = graph->vertexNum - numberOfCapitals;
    while (notMarkedVertexesLeft > 0) {
        bool wasVertexMarked = markTheNearestAvailableVertex(graph, listOfCapitals[turnCounter]);
        turnCounter = (turnCounter + 1) % numberOfCapitals;
        if (wasVertexMarked) {
            notMarkedVertexesLeft--;
        }
    }
}


