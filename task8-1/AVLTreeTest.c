#include "AVLTreeTest.h"
#include "AVLTree.h"
#include <stdbool.h>
#include <stdio.h>

Tree *setUpTree(void) {
    Tree *tree = initTree();
    bool shouldClimbUp = true;
    tree = insert(tree, "A", "AAA", &shouldClimbUp);
    shouldClimbUp = true;
    tree = insert(tree, "E", "EEE", &shouldClimbUp);
    shouldClimbUp = true;
    tree = insert(tree, "C", "CCC", &shouldClimbUp);
    shouldClimbUp = true;
    tree = insert(tree, "B", "BBB", &shouldClimbUp);
    shouldClimbUp = true;
    tree = insert(tree, "D", "DDD", &shouldClimbUp);
    shouldClimbUp = true;
    tree = insert(tree, "F", "FFF", &shouldClimbUp);
    return tree;
}

bool testFind(void) {
    Tree *tree = setUpTree();
    return findValueByKey(tree, "A")[0] == 'A'
           && findValueByKey(tree, "B")[0] == 'B'
           && findValueByKey(tree, "C")[0] == 'C'
           && findValueByKey(tree, "D")[0] == 'D'
           && findValueByKey(tree, "E")[0] == 'E'
           && findValueByKey(tree, "F")[0] == 'F';
}

bool testFindNonExistingKey(void) {
    Tree *tree = setUpTree();
    return findValueByKey(tree, "X") == NULL;
}

bool testInsertAnExistingKey() {
    Tree *tree = setUpTree();
    bool shouldClimbUp = true;
    tree = insert(tree, "A", "X", &shouldClimbUp);
    return findValueByKey(tree, "A")[0] == 'X';
}

bool testDelete(void) {
    Tree *tree = setUpTree();
    bool shouldClimbUp = true;
    tree = deleteNode(tree, "A", &shouldClimbUp);
    shouldClimbUp = true;
    tree = deleteNode(tree, "C", &shouldClimbUp);
    shouldClimbUp = true;
    tree = deleteNode(tree, "B", &shouldClimbUp);
    shouldClimbUp = true;
    tree = deleteNode(tree, "F", &shouldClimbUp);
    return findValueByKey(tree, "A") == NULL
           && findValueByKey(tree, "B") == NULL
           && findValueByKey(tree, "C") == NULL
           && findValueByKey(tree, "F") == NULL
           && findValueByKey(tree, "E")[0] == 'E'
           && findValueByKey(tree, "D")[0] == 'D';
}

bool runAllTestsForTask8(void) {
    int result = true;

    if (testFind()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testFindNonExistingKey()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testInsertAnExistingKey()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testDelete()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    return result;
}