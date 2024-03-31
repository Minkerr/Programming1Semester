#include "AVLTree.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define CAPACITY 256

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
    Tree *tree = malloc(sizeof(Tree));
    tree->root = NULL;
    return tree;
}

Node *createNode(char *key, char *value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->key = malloc(CAPACITY * sizeof(char));
    newNode->value = malloc(CAPACITY * sizeof(char));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->balance = 0;
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

Node* bigRotateLeft(Node* node) {
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

Node* bigRotateRight(Node* node) {
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

Node* balance(Node *node) {
    if(node == NULL){
        return node;
    }
    if (node->balance == 2) {
        if (node->right->balance >= 0) {
            return rotateLeft(node);
        }
        return bigRotateLeft(node);
    }
    if (node->balance == -2) {
        if (node->left->balance <= 0){
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

int getTreeHeight(Node* root){
    if(root == NULL) {
        return 0;
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

void recalculateBalance(Node* root){
    if(root == NULL) {
        return;
    }
    int leftHeight = getTreeHeight(root->left);
    int rightHeight = getTreeHeight(root->right);
    root->balance = rightHeight - leftHeight;
    recalculateBalance(root->left);
    recalculateBalance(root->right);
}

Node* insert(Node *node, char *key, char *value) {
    if (node == NULL) {
        Node *newNode = createNode(key, value);
        return newNode;
    }

    int comp = strcmp(key, node->key);
    if (comp < 0) {
        node->left = insert(node->left, key, value);
        node->balance--;
    } else if (comp > 0) {
        node->right = insert(node->right, key, value);
        node->balance++;
    } else {
        node->value = strdup(value);
        return node;
    }
    recalculateBalance(node);
    return balance(node);
}

Node *deleteNode(Node *root, char *key) {
    if (root == NULL) {
        return NULL;
    }

    int comp = strcmp(key, root->key);
    if (comp < 0) {
        root->left = deleteNode(root->left, key);
    } else if (comp > 0) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL || root->right == NULL) {
            Node *tmp = root->left != NULL ? root->left : root->right;
            if (tmp == NULL) {
                tmp = root;
                root = NULL;
                free(tmp->key);
                free(tmp->value);
                free(tmp);
            } else {
                root = tmp;
            }
        } else {
            Node *tmp = findMin(root->right);
            free(root->key);
            free(root->value);
            root->key = strdup(tmp->key);
            root->value = strdup(tmp->value);
            root->right = deleteNode(root->right, tmp->key);
        }
    }
    recalculateBalance(root);
    return balance(root);
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
    int comp = strcmp(key, node->key);
    if (comp < 0) {
        return findValueByKey(node->left, key);
    }
    else if (comp > 0) {
        return findValueByKey(node->right, key);
    }
    else {
        return node->value;
    }
}

void deleteTreeRecursion(Node *node) {
    if (node == NULL) {
        return;
    }
    deleteTreeRecursion(node->left);
    deleteTreeRecursion(node->right);
    free(node->value);
    free(node->key);
    free(node);
}

void deleteTree(Tree* tree) {
    deleteTreeRecursion(tree->root);
    free(tree);
}