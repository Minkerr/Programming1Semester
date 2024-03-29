#include "expressionTree.h"
#include "expressionTreeTest.h"
#include <stdbool.h>
#include <stdio.h>

bool testExpTree(){
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/input.txt"));
    return calculate(tree) == 4;
}

void runAllTestsForTask7(){
    if(testExpTree()){
        printf("Test passed");
    }
    else{
        printf("Test failed");
    }
}