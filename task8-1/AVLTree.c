#include "AVLTree.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    char *key;
    char *value;
    int balance;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Tree *initTree() {
    Tree *tree = calloc(1, sizeof(Tree));
    if (tree == NULL) {
        printf("Memory allocation error");
    }
    return tree;
}

Node *createNode(char *key, char *value) {
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error");
        return NULL;
    }
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    return newNode;
}

Node *rotateLeft(Node *node) {
    Node *rightNode = node->right;
    Node *leftRightNode = rightNode->left;
    rightNode->left = node;
    node->right = leftRightNode;

    if (rightNode->balance != 0) {
        node->balance = 0;
        rightNode->balance = 0;
    } else {
        node->balance = 1;
        rightNode->balance = -1;
    }
    return rightNode;
}

Node *rotateRight(Node *node) {
    Node *leftNode = node->left;
    Node *rightLeftNode = leftNode->right;
    leftNode->right = node;
    node->left = rightLeftNode;

    if (leftNode->balance != 0) {
        node->balance = 0;
        leftNode->balance = 0;
    } else {
        node->balance = -1;
        leftNode->balance = 1;
    }
    return leftNode;
}

Node *bigRotateLeft(Node *node) {
    Node *rightNode = node->right;
    Node *leftRightNode = rightNode->left;
    Node *leftLeftRightNode = leftRightNode->left;
    Node *rightLeftRightNode = leftRightNode->right;
    leftRightNode->left = node;
    leftRightNode->right = rightNode;
    node->right = leftLeftRightNode;
    rightNode->left = rightLeftRightNode;

    switch (leftRightNode->balance) {
        case -1: {
            node->balance = 0;
            rightNode->balance = 1;
            break;
        }
        case 0: {
            node->balance = 0;
            rightNode->balance = 0;
            break;
        }
        case 1: {
            node->balance = -1;
            rightNode->balance = 0;
            break;
        }
    }
    leftRightNode->balance = 0;
    return leftRightNode;
}

Node *bigRotateRight(Node *node) {
    Node *leftNode = node->left;
    Node *rightLeftNode = leftNode->right;
    Node *rightRightLeftNode = rightLeftNode->right;
    Node *leftRightLeftNode = rightLeftNode->left;
    rightLeftNode->right = node;
    rightLeftNode->left = leftNode;
    node->left = rightRightLeftNode;
    leftNode->right = leftRightLeftNode;

    switch (rightLeftNode->balance) {
        case -1: {
            node->balance = 1;
            leftNode->balance = 0;
            break;
        }
        case 0: {
            node->balance = 0;
            leftNode->balance = 0;
            break;
        }
        case 1: {
            node->balance = 0;
            leftNode->balance = -1;
            break;
        }
    }
    rightLeftNode->balance = 0;
    return rightLeftNode;
}

Node *balance(Node *node) {
    if (node == NULL) {
        return node;
    }
    if (node->balance == 2) {
        if (node->right->balance >= 0) {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    if (node->balance == -2) {
        if (node->left->balance <= 0) {
            return rotateRight(node);
        }
        return bigRotateRight(node);
    }
    return node;
}

Node *findMin(Node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

Node *insert(Node *node, char *key, char *value, bool *shouldClimbUp) {
    if (node == NULL) {
        Node *newNode = createNode(key, value);
        return newNode;
    }

    int comparisonResult = strcmp(key, node->key);
    if (comparisonResult < 0) {
        node->left = insert(node->left, key, value, shouldClimbUp);
        node->balance--;
    } else if (comparisonResult > 0) {
        node->right = insert(node->right, key, value, shouldClimbUp);
        node->balance++;
    } else {
        *shouldClimbUp = false;
        node->value = strdup(value);
        return node;
    }
    if (!*shouldClimbUp) {
        node->balance = comparisonResult < 0 ? (node->balance + 1) : (node->balance - 1);
        return node;
    }
    if (node->balance == 2 || node->balance == -2 || node->balance == 0) {
        *shouldClimbUp = false;
    }
    return balance(node);
}

Node *deleteNode(Node *node, char *key, bool *shouldClimbUp) {
    if (node == NULL) {
        *shouldClimbUp = false;
        return NULL;
    }
    int comparisonResult = strcmp(key, node->key);
    int balanceDifference = 0;
    if (comparisonResult < 0) {
        node->left = deleteNode(node->left, key, shouldClimbUp);
        balanceDifference++;
    } else if (comparisonResult > 0) {
        node->right = deleteNode(node->right, key, shouldClimbUp);
        balanceDifference--;
    } else {
        if (node->left == NULL || node->right == NULL) {
            *shouldClimbUp = true;
            Node *tmp = node;
            node = node->left != NULL ? node->left : node->right;
            free(tmp->key);
            free(tmp->value);
            free(tmp);
        } else {
            Node *tmp = findMin(node->right);
            free(node->key);
            free(node->value);
            node->key = strdup(tmp->key);
            node->value = strdup(tmp->value);
            node->right = deleteNode(node->right, tmp->key, shouldClimbUp);
        }
    }
    if (!*shouldClimbUp || node == NULL) {
        return node;
    }
    node->balance += balanceDifference;
    if (node->balance == 1 || node->balance == -1) {
        *shouldClimbUp = false;
    }
    return balance(node);
}

void printTree(Node *root) {
    if (root == NULL) {
        return;
    }
    printTree(root->left);
    printf("%s: %s\n", root->key, root->value);
    printTree(root->right);
}

char *findValueByKey(Node *node, char *key) {
    if (node == NULL) {
        return NULL;
    }
    int comparisonResult = strcmp(key, node->key);
    if (comparisonResult < 0) {
        return findValueByKey(node->left, key);
    } else if (comparisonResult > 0) {
        return findValueByKey(node->right, key);
    } else {
        return node->value;
    }
}

void deleteTreeRecursion(Node **node) {
    if (*node == NULL) {
        return;
    }
    deleteTreeRecursion(&((*node)->left));
    deleteTreeRecursion(&((*node)->right));
    free((*node)->value);
    free((*node)->key);
    free(*node);
    node = NULL;
}

void deleteTree(Tree **tree) {
    deleteTreeRecursion(&((*tree)->root));
    free(*tree);
    tree = NULL;
}