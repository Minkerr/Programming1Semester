#pragma once

#include "list.h"

// parameters by which the list can be sorted
typedef enum SortingKey {
    NAME, PHONE
} SortingKey;

// sorting the list by the selected parameter using the merge sort algorithm
List *mergeSort(List *list, SortingKey key);