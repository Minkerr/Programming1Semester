#pragma once

#include <stdbool.h>

#define CAPACITY 256

// realization of Linked List
typedef struct List List;

// create new list
List *initList();

// check if the list is empty
bool isEmpty(List *list);

// add new element to the list
int add(List *list, char *word);

// delete list and free memory
void deleteList(List *list);

// get list length
int listLength(List *list);

// print all elements of the list
void printList(List *list);
