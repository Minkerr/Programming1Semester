#include "expressionTree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define CAPACITY 256
#define MEMORY_ALLOCATION_ERROR (-2)

typedef struct Node {
    char operation;
    int number;
    struct Node *left;
    struct Node *right;
} Node;

typedef struct Tree {
    Node *root;
} Tree;

Tree *initTree() {
    return calloc(1, sizeof(Tree));
}

bool isNodeANumber(Node *node) {
    return node->left == NULL && node->right == NULL;
}

char *readStringFromFile(const char * const fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    char *line = calloc(CAPACITY, sizeof(char));
    if (line == NULL) {
        fclose(file);
        return NULL;
    }
    char c = '0';
    int index = 0;
    int lineSize = CAPACITY;
    while ((c = fgetc(file)) != EOF) {
        if (lineSize == CAPACITY) {
            char *newLine = realloc(line, (lineSize + CAPACITY) * sizeof(char));
            if (newLine == NULL) {
                free(line);
                fclose(file);
                return NULL;
            } else {
                line = newLine;
                lineSize = lineSize + CAPACITY;
            }
        }
        line[index++] = c;
    }
    fclose(file);
    return line;
}

int parseNumberFromString(char *str, int *i) {
    int result = 0;
    sscanf(&str[(*i)], "%d", &result);
    while (str[(*i)] >= '0' && str[(*i)] <= '9' || str[(*i)] == '-') {
        (*i)++;
    }
    return result;
}

bool isOperation(char *str, int i) {
    return str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-' &&
        ((str[i + 1] <= '0') || (str[i + 1] >= '9'));
}

Node *parseTreeFromStringRec(char *str, int *i, int *errorCode) {
    int strLength = strlen(str) - 1;
    while ((*i) != strLength && (str[(*i)] == '(' || str[(*i)] == ')' || str[(*i)] == ' ')) {
        (*i)++;
    }
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        (*errorCode) = MEMORY_ALLOCATION_ERROR;
        return NULL;
    }
    if (isOperation(str, (*i))) {
        newNode->operation = str[(*i)++];
        newNode->left = parseTreeFromStringRec(str, i, errorCode);
        newNode->right = parseTreeFromStringRec(str, i, errorCode);
    } else {
        newNode->number = parseNumberFromString(str, i);
    }
    return newNode;
}

Tree *parseTreeFromString(char *str) {
    if (str == NULL) {
        return NULL;
    }
    int i = 0;
    int errorCode = 0;
    Tree *tree = initTree();
    if (tree == NULL) {
        return NULL;
    }
    tree->root = parseTreeFromStringRec(str, &i, &errorCode);
    if (errorCode != 0) {
        return NULL;
    }
    return tree;
}

void printTreeRec(Node *node) {
    if (node == NULL) {
        return;
    }
    if (isNodeANumber(node)) {
        printf(" %d", node->number);
    } else {
        printf(" ( %c", node->operation);
        printTreeRec(node->left);
        printTreeRec(node->right);
        printf(" )");
    }
}

void printTree(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    printTreeRec(tree->root);
    printf("\n");
}

int calculateRec(Node *node) {
    if (isNodeANumber(node)) {
        return node->number;
    } else {
        char operation = node->operation;
        switch (operation) {
            case '+':
                return calculateRec(node->left) + calculateRec(node->right);
            case '/':
                return calculateRec(node->left) / calculateRec(node->right);
            case '*':
                return calculateRec(node->left) * calculateRec(node->right);
            default:
                return calculateRec(node->left) - calculateRec(node->right);
        }
    }

}

int calculate(Tree *tree) {
    if (tree == NULL) {
        printf("Tree is NULL");
        return 0;
    }
    return calculateRec(tree->root);
}

void deleteTreeRecursive(Node *node) {
    if (node == NULL) {
        return;
    }
    deleteTreeRecursive(node->left);
    deleteTreeRecursive(node->right);
    free(node);
}

void deleteTree(Tree **tree) {
    deleteTreeRecursive((*tree)->root);
    free(*tree);
    *tree = NULL;
}