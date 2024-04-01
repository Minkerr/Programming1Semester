#include "expressionTreeTest.c"
#include "expressionTree.h"

int main() {
    int returnCode = runAllTestsForTask7();
    if (returnCode != 0) {
        return returnCode;
    }
    Tree* tree = parseTreeFromString(readStringFromFile("task7-2/input.txt"));
    printTree(tree);
    deleteTree(tree);
    return returnCode;
}