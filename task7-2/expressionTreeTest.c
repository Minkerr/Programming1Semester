#include "expressionTree.h"
#include "expressionTreeTest.h"
#include <stdbool.h>
#include <stdio.h>

bool testExpressionTreeForComplexCase() {
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/input.txt"));
    bool result = calculate(tree) == 4;
    deleteTree(&tree);
    return result;
}

bool testExpressionTreeForAdding() {
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/test1.txt"));
    bool result = calculate(tree) == 4;
    deleteTree(&tree);
    return result;
}

bool testExpressionTreeForSubtraction() {
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/test2.txt"));
    bool result = calculate(tree) == 4;
    deleteTree(&tree);
    return result;
}

bool testExpressionTreeForMultiplication() {
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/test3.txt"));
    bool result = calculate(tree) == 4;
    deleteTree(&tree);
    return result;
}

bool testExpressionTreeForDividing() {
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/test4.txt"));
    bool result = calculate(tree) == 4;
    deleteTree(&tree);
    return result;
}

bool runAllTestsForTask7() {
    bool result = true;
    if (testExpressionTreeForComplexCase()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testExpressionTreeForAdding()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testExpressionTreeForSubtraction()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testExpressionTreeForMultiplication()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testExpressionTreeForDividing()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    return result;
}