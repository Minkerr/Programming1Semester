#include "expressionTree.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#define STRING_SIZE 64

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
    Tree *tree = malloc(sizeof(Tree));
    return tree;
}

bool isNodeANumber(Node *node) {
    return node->left == NULL && node->right == NULL;
}

char *readStringFromFile(char *fileName) {
    FILE *file = fopen(fileName, "r");
    char *string = malloc(STRING_SIZE * sizeof(char));
    fgets(string, STRING_SIZE, file);
    fclose(file);
    return string;
}

int parseNumberFromString(char *str, int *i) {
    int result = 0;
    int sign = 1;
    if (str[(*i)] == '-') {
        sign = -1;
        (*i)++;
    }
    while (str[(*i)] >= '0' && str[(*i)] <= '9') {
        result = result * 10 + (str[(*i)] - '0');
        (*i)++;
    }
    return sign * result;
}

bool isOperation(char *str, int i) {
    return str[i] == '+' || str[i] == '/' || str[i] == '*' || str[i] == '-' &&
                                                              ((str[i + 1] <= '0') || (str[i + 1] >= '9'));
}

Node *parseTreeFromStringRec(char *str, int *i) {
    int strLength = strlen(str) - 1;
    while ((*i) != strLength && (str[(*i)] == '(' || str[(*i)] == ')' || str[(*i)] == ' ')) {
        (*i)++;
    }
    Node *newNode = malloc(sizeof(Node));
    if (isOperation(str, (*i))) {
        newNode->operation = str[(*i)++];
        newNode->left = parseTreeFromStringRec(str, i);
        newNode->right = parseTreeFromStringRec(str, i);
    } else {
        newNode->number = parseNumberFromString(str, i);
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

Tree *parseTreeFromString(char *str) {
    int i = 0;
    Tree *tree = initTree();
    tree->root = parseTreeFromStringRec(str, &i);
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
    printTreeRec(tree->root);
    printf("\n");
}

int calculateRec(Node* node){
    if(isNodeANumber(node)){
        return node->number;
    }
    else{
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
    return calculateRec(tree->root);
}