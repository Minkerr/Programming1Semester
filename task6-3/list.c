#include "list.h"
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
    List *list = malloc(sizeof(List));
    list->head = list->tail = NULL;
    list->length = 0;
    return list;
}

bool isEmpty(List *list) {
    return list->head == NULL;
}

void add(List *list, char *name, char *phone) {
    Node *newNode = malloc(sizeof(Node));
    list->length++;
    newNode->name = malloc(CAPACITY * sizeof(char));
    newNode->phone = malloc(CAPACITY * sizeof(char));
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
}

void deleteHead(List* list) {
    if (!isEmpty(list)) {
        list->length--;
        Node *tempHead = list->head;
        list->head = list->head->next;
        free(tempHead->phone);
        free(tempHead->name);
        free(tempHead);
    }
    if(isEmpty(list)){
        free(list);
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

void moveHeadToNewList(List* newList, List* oldList) {
    add(newList, oldList->head->name, oldList->head->phone);
    deleteHead(oldList);
}

List *mergeTwoListsByKey(List *first, List *second, enum SortingKey sortingKey) {
    List *mergedList = initList();

    while (listLen(first) != 0 && listLen(second) != 0) {
        int comp;
        if (sortingKey == phone) {
            comp = strcmp(first->head->phone, second->head->phone);
        } else {
            comp = strcmp(first->head->name, second->head->name);
        }

        if (comp < 0) {
            moveHeadToNewList(mergedList, first);
        }
        else{
            moveHeadToNewList(mergedList, second);
        }
    }
    while (listLen(first) != 0){
        moveHeadToNewList(mergedList, first);
    }
    while (listLen(second) != 0){
        moveHeadToNewList(mergedList, second);
    }
    deleteList(first);
    deleteList(second);
    return mergedList;
}

List* readFromFile(char* fileName) {
    List* list = initList();
    FILE* file = fopen(fileName, "r");
    char name[CAPACITY];
    char phone[CAPACITY];
    while (fscanf_s(file, "%s %s", name, CAPACITY, phone, CAPACITY) != EOF) {
        add(list, &name[0], &phone[0]);
    }
    fclose(file);
    return list;
}

void printList(List* list) {
    if (isEmpty(list)) {
        return;
    }
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        printf("%s %s\n", currentNode->name, currentNode->phone);
        currentNode = currentNode->next;
    }
}