#include "list.c"
#include "mergeSort.h"
#include <string.h>

List *mergeTwoListsByKey(List *first, List *second, enum SortingKey sortingKey) {
    List *mergedList = initList();

    while (listLength(first) != 0 && listLength(second) != 0) {
        int comparisonResult = sortingKey == PHONE ? strcmp(getPhoneName(first), getPhoneName(second))
                                                   : strcmp(getHeadName(first), getHeadName(second));
        if (comparisonResult < 0) {
            moveHeadToNewList(mergedList, first);
        } else {
            moveHeadToNewList(mergedList, second);
        }
    }
    while (listLength(first) != 0) {
        moveHeadToNewList(mergedList, first);
    }
    while (listLength(second) != 0) {
        moveHeadToNewList(mergedList, second);
    }
    deleteList(&first);
    deleteList(&second);
    return mergedList;
}

List *mergeSort(List *list, SortingKey key) {
    int length = listLength(list);
    if (length <= 1) {
        return list;
    }
    List *left = initList();
    if (left == NULL) {
        return NULL;
    }
    List *right = initList();
    if (right == NULL) {
        deleteList(&right);
        return NULL;
    }
    for (int i = 0; i < length / 2; i++) {
        moveHeadToNewList(left, list);
    }
    for (int i = 0; i < (length + 1) / 2; i++) {
        moveHeadToNewList(right, list);
    }
    deleteList(&list);
    left = mergeSort(left, key);
    right = mergeSort(right, key);
    return mergeTwoListsByKey(left, right, key);
}