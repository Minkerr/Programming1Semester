#include "mergeSortTest.h"
#include "mergeSort.h"
#include "list.h"
#include "errorCode.h"
#include <string.h>
#include <stdio.h>

bool testMergeSortCommonCaseName() {
    List *list = readFromFile("C:\\Users\\valen\\CLionProjects\\Programming1Semester\\task6-3\\input.txt");
    List *temp = mergeSort(list, NAME);
    if (temp != NULL) {
        list = temp;
    } else {
        deleteList(&list);
        return false;
    }
    bool result = true;
    if (strcmp(getHeadName(list), "John") != 0) {
        result = false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "Mike") != 0) {
        result = false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "Simone") != 0) {
        result = false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "Tommy") != 0) {
        result = false;
    }
    deleteHead(list);

    return result;
}

bool testMergeSortCommonCasePhone() {
    List *list = readFromFile("C:\\Users\\valen\\CLionProjects\\Programming1Semester\\task6-3\\input.txt");
    List *temp = mergeSort(list, PHONE);
    if (temp != NULL) {
        list = temp;
    } else {
        deleteList(&list);
        return false;
    }
    bool result = true;
    if (strcmp(getHeadName(list), "Simone") != 0) {
        result = false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "John") != 0) {
        result = false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "Tommy") != 0) {
        result = false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "Mike") != 0) {
        result = false;
    }
    deleteHead(list);

    return result;
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