#pragma once

typedef struct Tree Tree;

Tree* initTree();

char* readStringFromFile(char* fileName);

Tree* parseTreeFromString(char* str);

void printTree(Tree* tree);

int calculate(Tree* tree);
