#include "list.h"
#include "errorCode.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 256

typedef struct Node {
    char *name;
    char *phone;
    struct Node *next;
} Node;

typedef struct List {
    int length;
    Node *head;
    Node *tail;
} List;

List *initList() {
    return calloc(1, sizeof(List));
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
    if (newNode->name == NULL) {
        free(newNode);
        return MEMORY_ALLOCATION_ERROR;
    }
    newNode->phone = calloc(strlen(phone), sizeof(char));
    if (newNode->phone == NULL) {
        free(newNode->name);
        free(newNode);
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

void deleteHead(List **list) {
    if (!isEmpty(*list)) {
        (*list)->length--;
        Node *tempHead = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(tempHead->phone);
        free(tempHead->name);
        free(tempHead);
    } else {
        free(*list);
        *list = NULL;
    }
}

void deleteList(List **list) {
    while (!isEmpty(*list)) {
        Node *tempHead = (*list)->head;
        (*list)->head = (*list)->head->next;
        free(tempHead->phone);
        free(tempHead->name);
        free(tempHead);
    }
    free(*list);
    *list = NULL;
}

int listLength(List *list) {
    return list->length;
}

void moveHeadToNewList(List *newList, List *oldList) {
    add(newList, oldList->head->name, oldList->head->phone);
    deleteHead(&oldList);
}

List *readFromFile(const char *fileName) {
    List *list = initList();
    if (list == NULL) {
        return NULL;
    }
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
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
                char *newName = realloc(name, (lineSize + CAPACITY) * sizeof(char));
                char *newPhone = realloc(phone, (lineSize + CAPACITY) * sizeof(char));
                if (newLine == NULL || newName == NULL || newPhone == NULL) {
                    free(name);
                    free(phone);
                    free(line);
                    return NULL;
                } else {
                    line = newLine;
                    name = newName;
                    phone = newPhone;
                    lineSize = lineSize + CAPACITY;
                }
            }
            line[index++] = c;
        }
    }
    free(name);
    free(phone);
    free(line);
    fclose(file);
    return list;
}

char *getHeadName(List *list) {
    return list->head->name;
}

char *getPhoneName(List *list) {
    return list->head->phone;
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