#include "expressionTree.c"
#include "expressionTreeTest.h"
#include <stdbool.h>
#include <stdio.h>

bool testExpressionTree(){
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/input.txt"));
    bool res = calculate(tree) == 4;
    deleteTree(tree);
    return res;
}

int runAllTestsForTask7(){
    if(testExpressionTree()){
        printf("Test passed\n");
        return 0;
    }
    else{
        printf("Test failed\n");
        return -1;
    }
}