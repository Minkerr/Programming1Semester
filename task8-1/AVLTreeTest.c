#include "AVLTreeTest.h"
#include "AVLTree.h"
#include <stdbool.h>
#include <stdio.h>

Tree *setUpTree(void) {
    Tree *tree = initTree();
    tree = insert(tree, "A", "AAA");
    tree = insert(tree, "E", "EEE");
    tree = insert(tree, "C", "CCC");
    tree = insert(tree, "B", "BBB");
    tree = insert(tree, "D", "DDD");
    tree = insert(tree, "F", "FFF");
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
    tree = insert(tree, "A", "X");
    return findValueByKey(tree, "A")[0] == 'X';
}

bool testDelete(void) {
    Tree *tree = setUpTree();
    tree = deleteNode(tree, "A");
    tree = deleteNode(tree, "C");
    tree = deleteNode(tree, "B");
    tree = deleteNode(tree, "F");
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