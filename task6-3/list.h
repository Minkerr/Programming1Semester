#pragma once

#include "stdbool.h"

#define MEMORY_ALLOCATION_ERROR (-1)

// parameters by which the list can be sorted
typedef enum SortingKey {
    NAME, PHONE
} SortingKey;

// one node of linked list, contains information about one element
typedef struct Node {
    char *name;
    char *phone;
    struct Node *next;
} Node;

// contains head and tail of linked list
typedef struct List {
    int length;
    Node *head;
    Node *tail;
} List;

// create new empty list
List *initList();

// check if the list is empty
bool isEmpty(List *list);

// add new element to the list
int add(List *list, char *name, char *phone);

// delete list head and free the memory it used
void deleteHead(List *list);

// delete list and free the memory it used
void deleteList(List *list);

// get length of the list
int listLength(List *list);

// remove head from old list and add it to new list
void moveHeadToNewList(List *newList, List *oldList);

// create new list with data from file
List *readFromFile(const char *fileName);

// print list to the console
void printList(List *list);