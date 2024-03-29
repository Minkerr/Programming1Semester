#include "list.h"

List* mergeSort(List* list, SortingKey key) {
    int length = listLen(list);
    if (length <= 1) {
        return list;
    }
    List* left = initialize();
    List* right = initialize();
    for (int i = 0; i < length / 2; i++){
        moveHeadToNewList(left, list);
    }
    for (int i = 0; i < (length + 1) / 2; i++) {
        moveHeadToNewList(right, list);
    }
    deleteList(list);
    left = mergeSort(left, key);
    right = mergeSort(right, key);
    return mergeTwoListsByKey(left, right, key);
}