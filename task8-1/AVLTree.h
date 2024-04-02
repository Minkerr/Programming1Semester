#pragma once

#include <stdbool.h>

// AVT-Tree dictionary
typedef struct Tree Tree;
// One node of the tree. It contains key and value
typedef struct Node Node;

// Create new empty tree
Tree *initTree();

// Insert new node to tree. Returns new root
Node *insert(Node *node, char *key, char *value, bool *shouldClimbUp);

// Delete node from tree by value. Returns new root
Node *deleteNode(Node *root, char *key, bool *shouldClimbUp);

// print to console all keys and values from tree
void printTree(Node *root);

// returns the found value for this key, or NULL if nothing is found
char *findValueByKey(Node *node, char *key);

// delete tree and free memory
void deleteTree(Tree **tree);