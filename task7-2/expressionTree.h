#pragma once

typedef struct Tree Tree;

char* readStringFromFile(char* fileName);

Tree* parseTreeFromString(char* str);

void printTree(Tree* tree);

int calculate(Tree* tree);

void deleteTree(Tree* tree);