#include <stdbool.h>
#include <stdio.h>
#include "graph.h"
#include "graphTest.h"

bool testCaseForGraphWithSixVertexes() {
    Graph *graph = readInputFromFile("task10-1/input.txt");
    distributeCities(graph);
    printInfoAboutGraph(graph);
    bool res = graph->governmentMarks[1] == 1
               && graph->governmentMarks[2] == 2
               && graph->governmentMarks[4] == 2
               && graph->governmentMarks[5] == 2;
    deleteGraph(&graph);
    return res;
}

bool testSmallCase() {
    Graph *graph = readInputFromFile("task10-1/inputTrickyTest.txt");
    distributeCities(graph);
    printInfoAboutGraph(graph);
    bool res = graph->governmentMarks[2] == 2;
    deleteGraph(&graph);
    return res;
}

bool runAllTestsForTask10() {
    bool result = true;
    if (testCaseForGraphWithSixVertexes()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testSmallCase()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    return result;
}