#pragma once

#include <stdbool.h>

// AVT-Tree dictionary
typedef struct Tree Tree;

// Create new empty tree
Tree *initTree();

// Insert new node to tree. Returns new root
Tree *insert(Tree *tree, char *key, char *value);

// Delete node from tree by value. Returns new root
Tree *deleteNode(Tree *tree, char *key);

// print to console all keys and values from tree
void printTree(Tree *tree);

// returns the found value for this key, or NULL if nothing is found
char *findValueByKey(Tree *tree, char *key);

//

// delete tree and free memory
void deleteTree(Tree **tree);