#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define CAPACITY 256
#define MEMORY_ALLOCATION_ERROR (-1)

typedef struct Node {
    char *word;
    int count;
    struct Node *next;
} Node;

typedef struct List {
    int length;
    int count;
    Node *head;
    Node *tail;
} List;

List *initList() {
    List *list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
}

bool isEmpty(List *list) {
    return list->head == NULL;
}

Node *searchNode(List *list, char *targetWord) {
    Node *current = list->head;
    while (current != NULL) {
        if (strcmp(current->word, targetWord) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

int add(List *list, char *word) {
    list->count++;
    if (searchNode(list, word) != NULL) {
        Node *current = searchNode(list, word);
        current->count++;
        return 0;
    }
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }
    list->length++;
    newNode->word = malloc(CAPACITY * sizeof(char));
    if (newNode->word == NULL) {
        return MEMORY_ALLOCATION_ERROR;
    }
    newNode->count = 1;
    newNode->next = NULL;
    strcpy(newNode->word, word);
    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
}

void deleteHead(List *list) {
    if (!isEmpty(list)) {
        list->length--;
        Node *tempHead = list->head;
        list->head = list->head->next;
        free(tempHead->word);
        free(tempHead);
    }
}

void deleteList(List *list) {
    while (!isEmpty(list)) {
        deleteHead(list);
    }
    free(list);
}

int listLen(List *list) {
    return list->length;
}

void printList(List *list) {
    if (isEmpty(list)) {
        return;
    }
    Node *currentNode = list->head;
    while (currentNode != NULL) {
        printf("%s %d\n", currentNode->word, currentNode->count);
        currentNode = currentNode->next;
    }
}