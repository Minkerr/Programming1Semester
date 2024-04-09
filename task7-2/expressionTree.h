#pragma once

// a binary tree that implements an expression tree that can calculate an expression
typedef struct Tree Tree;

// read string from file
char *readStringFromFile(const char * const fileName);

// create a tree based on an expression in string
Tree *parseTreeFromString(char *str);

// print the tree as the expression it represents
void printTree(Tree *tree);

// calculate the value of expression in tree
int calculate(Tree *tree, int* errorCode);

// delete tree and free memory
void deleteTree(Tree **tree);