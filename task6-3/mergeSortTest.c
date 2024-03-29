#include "mergeSort.h"
#include "list.h"
#include <string.h>
#include <stdio.h>

bool testMergeSortCommonCaseName(){
    List* list = readFromFile("task6-3/input.txt");
    list = mergeSort(list, name);
    bool res = true;
    if(strcmp(list->head->name, "John") != 0){
        res = false;
    }
    deleteHead(list);
    if(strcmp(list->head->name, "Mike") != 0){
        res = false;
    }
    deleteHead(list);if(strcmp(list->head->name, "Simone") != 0){
        res = false;
    }
    deleteHead(list);if(strcmp(list->head->name, "Tommy") != 0){
        res = false;
    }
    deleteHead(list);

    return res;
}

bool testMergeSortCommonCasePhone(){
    List* list = readFromFile("task6-3/input.txt");
    list = mergeSort(list, phone);
    bool res = true;
    if(strcmp(list->head->name, "Simone") != 0){
        res = false;
    }
    deleteHead(list);
    if(strcmp(list->head->name, "John") != 0){
        res = false;
    }
    deleteHead(list);if(strcmp(list->head->name, "Tommy") != 0){
        res = false;
    }
    deleteHead(list);if(strcmp(list->head->name, "Mike") != 0){
        res = false;
    }
    deleteHead(list);

    return res;
}

bool testEmptyList(){
    List* list = initialize();
    list = mergeSort(list, name);
    return isEmpty(list);
}

void runAllTestsForTask6(){
    if(testMergeSortCommonCaseName()){
        printf("Test #1 passed\n");
    }
    else{
        printf("Test #1 failed\n");
    }

    if(testMergeSortCommonCasePhone()){
        printf("Test #2 passed\n");
    }
    else{
        printf("Test #2 failed\n");
    }

    if(testEmptyList()){
        printf("Test #3 passed\n");
    }
    else{
        printf("Test #3 failed\n");
    }
}