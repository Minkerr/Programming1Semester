#include "mergeSort.h"
#include "list.h"
#include <string.h>
#include <stdio.h>

bool testMergeSortCommonCaseName() {
    List *list = readFromFile("task6-3/input.txt");
    List *sortedList = mergeSort(list, NAME);
    bool res = true;
    if (strcmp(sortedList->head->name, "John") != 0) {
        res = false;
    }
    deleteHead(sortedList);
    if (strcmp(sortedList->head->name, "Mike") != 0) {
        res = false;
    }
    deleteHead(sortedList);
    if (strcmp(sortedList->head->name, "Simone") != 0) {
        res = false;
    }
    deleteHead(sortedList);
    if (strcmp(sortedList->head->name, "Tommy") != 0) {
        res = false;
    }
    deleteHead(sortedList);

    return res;
}

bool testMergeSortCommonCasePhone() {
    List *list = readFromFile("task6-3/input.txt");
    List *sortedList = mergeSort(list, PHONE);
    bool res = true;
    if (strcmp(sortedList->head->name, "Simone") != 0) {
        res = false;
    }
    deleteHead(sortedList);
    if (strcmp(sortedList->head->name, "John") != 0) {
        res = false;
    }
    deleteHead(sortedList);
    if (strcmp(sortedList->head->name, "Tommy") != 0) {
        res = false;
    }
    deleteHead(sortedList);
    if (strcmp(sortedList->head->name, "Mike") != 0) {
        res = false;
    }
    deleteHead(sortedList);

    return res;
}

bool testEmptyList() {
    List *list = initList();
    list = mergeSort(list, NAME);
    return isEmpty(list);
}

int runAllTestsForTask6() {
    int returnCode = 0;

    if (testMergeSortCommonCaseName()) {
        printf("Test #1 passed\n");
    } else {
        printf("Test #1 failed\n");
        returnCode = -1;
    }

    if (testMergeSortCommonCasePhone()) {
        printf("Test #2 passed\n");
    } else {
        printf("Test #2 failed\n");
        returnCode = -1;
    }

    if (testEmptyList()) {
        printf("Test #3 passed\n");
    } else {
        printf("Test #3 failed\n");
        returnCode = -1;
    }

    return returnCode;
}