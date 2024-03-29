#include "expressionTreeTest.h"
#include "expressionTree.h"

int main() {
    Tree* tree = parseTreeFromString(readStringFromFile("task7-2/input.txt"));
    printTree(tree);
    runAllTestsForTask7();

    return 0;
}