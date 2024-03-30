#include "stdbool.h"
#include "stdio.h"
#include "graph.h"
#include "graphTest.h"

bool testForInputData(){
#include "graph.c"
    Graph* graph = readInputFromFile("task10-1/input.txt");
    distributeCities(graph);
    printInfoAboutGraph(graph);
    bool res = graph->governmentMarks[1] == 1
            && graph->governmentMarks[2] == 2
            && graph->governmentMarks[4] == 2
            && graph->governmentMarks[5] == 1;
    deleteGraph(graph);
    return res;
}

void runTestForInputData(){
    if(testForInputData()){
        printf("Test passed\n");
    }
    else{
        printf("Test failed\n");
    }
}