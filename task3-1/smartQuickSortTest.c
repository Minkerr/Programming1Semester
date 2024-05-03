#include "smartQuickSort.c"
#include "smartQuickSortTest.h"
#include <stdbool.h>
#include <stdio.h>

bool testQSortForEmptyArray() {
    int array[] = {};
    smartQsort(array, 0, 0);
    return sizeof(array) == 0;
}

bool testQSortForOneElementArray() {
    int array[] = {1};
    smartQsort(array, 0, 0);
    return array[0] == 1;
}

bool testQSortForCommonSmallArray() {
    int array[] = {3, 1, 2};
    smartQsort(array, 0, 3);
    return array[0] == 1 && array[1] == 2 && array[2] == 3;
}

bool testQSortForCommonBigArray() {
    int array[] = {3, 1, 2, 0, 12, 11, 4, 8, 10, 7, 9, 5, 6};
    smartQsort(array, 0, 12);
    bool result = true;
    for (int i = 0; i < 12; i++) {
        if (array[i] != i) {
            result = false;
        }
    }
    return result;
}

int runAllTestsTask3() {
    int returnCode = 0;

    if (testQSortForEmptyArray()) {
        printf("Test #1 for Task 3-1 has passed\n");
    } else {
        printf("Test #1 for Task 3-1 failed\n");
        returnCode = -1;
    }

    if (testQSortForOneElementArray()) {
        printf("Test #2 for Task 3-1 has passed\n");
    } else {
        printf("Test #2 for Task 3-1 failed\n");
        returnCode = -1;
    }

    if (testQSortForCommonSmallArray()) {
        printf("Test #3 for Task 3-1 has passed\n");
    } else {
        printf("Test #3 for Task 3-1 failed\n");
        returnCode = -1;
    }

    if (testQSortForCommonBigArray()) {
        printf("Test #4 for Task 3-1 has passed\n");
    } else {
        printf("Test #4 for Task 3-1 failed\n");
        returnCode = -1;
    }

    return returnCode;
}