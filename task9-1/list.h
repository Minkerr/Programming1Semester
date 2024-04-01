#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 256

typedef struct List List;

List *initList();

bool isEmpty(List *list);

int add(List *list, char *word);

void deleteHead(List *list);

void deleteList(List *list);

int listLen(List *list);

void printList(List *list);
