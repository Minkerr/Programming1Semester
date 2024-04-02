#include "AVLTreeTest.h"
#include "AVLTree.c"
#include <stdbool.h>

Tree *setUpTree(void) {
    Tree *tree = initTree();
    bool shouldClimbUp = true;
    tree->root = insert(tree->root, "A", "AAA", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = insert(tree->root, "E", "EEE", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = insert(tree->root, "C", "CCC", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = insert(tree->root, "B", "BBB", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = insert(tree->root, "D", "DDD", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = insert(tree->root, "F", "FFF", &shouldClimbUp);
    return tree;
}

bool testInsert(void) {
    Tree *tree = setUpTree();
    return tree->root->key[0] == 'C' && tree->root->balance == 0
           && tree->root->left->key[0] == 'A' && tree->root->left->balance == 1
           && tree->root->left->right->key[0] == 'B' && tree->root->left->right->balance == 0
           && tree->root->right->key[0] == 'E' && tree->root->right->balance == 0
           && tree->root->right->left->key[0] == 'D' && tree->root->right->left->balance == 0
           && tree->root->right->right->key[0] == 'F' && tree->root->right->right->balance == 0;
}

bool testFind(void) {
    Tree *tree = setUpTree();
    return findValueByKey(tree->root, "A")[0] == 'A'
           && findValueByKey(tree->root, "B")[0] == 'B'
           && findValueByKey(tree->root, "C")[0] == 'C'
           && findValueByKey(tree->root, "D")[0] == 'D'
           && findValueByKey(tree->root, "E")[0] == 'E'
           && findValueByKey(tree->root, "F")[0] == 'F';
}

bool testFindNonExcistingKey(void) {
    Tree *tree = setUpTree();
    return findValueByKey(tree->root, "X") == NULL;
}

bool testInsertAnExistingKey() {
    Tree *tree = setUpTree();
    bool shouldClimbUp = true;
    tree->root = insert(tree->root, "A", "X", &shouldClimbUp);
    return findValueByKey(tree->root, "A")[0] == 'X';
}

bool testDelete(void) {
    Tree *tree = setUpTree();
    bool shouldClimbUp = true;
    tree->root = deleteNode(tree->root, "A", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = deleteNode(tree->root, "C", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = deleteNode(tree->root, "B", &shouldClimbUp);
    shouldClimbUp = true;
    tree->root = deleteNode(tree->root, "F", &shouldClimbUp);
    return findValueByKey(tree->root, "A") == NULL
           && findValueByKey(tree->root, "B") == NULL
           && findValueByKey(tree->root, "C") == NULL
           && findValueByKey(tree->root, "F") == NULL
           && tree->root->key[0] == 'E' && tree->root->balance == -1
           && tree->root->left->key[0] == 'D' && tree->root->left->balance == 0;
}

bool runAllTestsForTask8(void) {
    int result = true;

    if (testInsert()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testFind()) {
        printf("Test passed\n");
    } else {
        printf("Test failed\n");
        result = false;
    }

    if (testFindNonExcistingKey()) {
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