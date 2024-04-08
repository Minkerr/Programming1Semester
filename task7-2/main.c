#include "expressionTreeTest.h"
#include "expressionTree.h"

int main() {
    int returnCode = runAllTestsForTask7();
    if (!returnCode) {
        return -1;
    }
    Tree *tree = parseTreeFromString(readStringFromFile("task7-2/input.txt"));
    printTree(tree);
    deleteTree(&tree);
    return 0;
}