#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 256

List *initList() {
    List *list = calloc(1, sizeof(List));
    return list;
}

bool isEmpty(List *list) {
    return list->head == NULL;
}

int add(List *list, char *name, char *phone) {
    Node *newNode = calloc(1, sizeof(Node));
    if (newNode == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }
    list->length++;
    newNode->name = calloc(strlen(name), sizeof(char));
    newNode->phone = calloc(strlen(phone), sizeof(char));
    if (newNode->name == NULL || newNode->phone == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;
    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    return 0;
}

void deleteHead(List *list) {
    if (!isEmpty(list)) {
        (list)->length--;
        Node *tempHead = (list)->head;
        (list)->head = (list)->head->next;
        free(tempHead->phone);
        free(tempHead->name);
        free(tempHead);
    }
}

void deleteList(List *list) {
    while (!isEmpty(list)) {
        deleteHead(list);
    }
    free(list);
}

int listLength(List *list) {
    return list->length;
}

void moveHeadToNewList(List *newList, List *oldList) {
    add(newList, oldList->head->name, oldList->head->phone);
    deleteHead(oldList);
}

List *readFromFile(const char *fileName) {
    List *list = initList();
    FILE *file = fopen(fileName, "r");
    char c = '0';
    char *line = calloc(CAPACITY, sizeof(char));
    int lineSize = CAPACITY;
    int index = 0;
    char *name = calloc(CAPACITY, sizeof(char));
    char *phone = calloc(CAPACITY, sizeof(char));

    while ((c = fgetc(file)) != EOF) {
        if (c == ' ') {
            line[index] = '\0';
            strcpy(name, line);
            index = 0;
        } else if (c == '\n') {
            line[index] = '\0';
            strcpy(phone, line);
            add(list, name, phone);
            index = 0;
        } else {
            if (lineSize == CAPACITY) {
                char *newLine = realloc(line, (lineSize + CAPACITY) * sizeof(char));
                if (newLine == NULL) {
                    return NULL;
                } else {
                    line = newLine;
                    lineSize = lineSize + CAPACITY;
                }
            }
            line[index++] = c;
        }
    }

    fclose(file);
    return list;
}

void printList(List *list) {
    if (isEmpty(list)) {
        return;
    }
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        printf("%s %s\n", currentNode->name, currentNode->phone);
        currentNode = currentNode->next;
    }
}