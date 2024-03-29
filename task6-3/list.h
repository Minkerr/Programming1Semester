#pragma once

#include "stdbool.h"

typedef enum SortingKey {
    name, phone
} SortingKey;

typedef struct List List;

List *initialize();

bool isEmpty(List *list);

void add(List *list, char *name, char *phone);

void deleteHead(List* list);

void deleteList(List *list);

int listLen(List *list);

void moveHeadToNewList(List* newList, List* oldList);

List *mergeTwoListsByKey(List *first, List *second, enum SortingKey sortingKey);

List* readFromFile(char* fileName);

void printList(List* list);