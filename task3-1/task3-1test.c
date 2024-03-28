#include "task3-1.c"
#include <stdbool.h>

bool testQSortForEmptyArray() {
    int arr[] = {};
    smartQsort(arr, 0, 0);
    return sizeof(arr) == 0;
}

bool testQSortForOneElementArray() {
    int arr[] = {1};
    smartQsort(arr, 0, 0);
    return arr[0] == 1;
}

bool testQSortForCommonSmallArray() {
    int a[] = {3, 1, 2};
    smartQsort(a, 0, 3);
    return a[0] == 1 && a[1] == 2 && a[2] == 3;
}

bool testQSortForCommonBigArray() {
    int a[] = {3, 1, 2, 0, 12, 11, 4, 8, 10, 7, 9, 5, 6};
    smartQsort(a, 0, 12);
    bool result = true;
    for (int i = 0; i < 12; i++) {
        if(a[i] != i){
            result = false;
        }
    }
    return result;
}

void runAllTestsTask3(){
    if(testQSortForEmptyArray()){
        printf("Test #1 for Task 3-1 has passed\n");
    } else{
        printf("Test #1 for Task 3-1 failed\n");
    }

    if(testQSortForOneElementArray()){
        printf("Test #2 for Task 3-1 has passed\n");
    } else{
        printf("Test #2 for Task 3-1 failed\n");
    }

    if(testQSortForCommonSmallArray()){
        printf("Test #3 for Task 3-1 has passed\n");
    } else{
        printf("Test #3 for Task 3-1 failed\n");
    }

    if(testQSortForCommonBigArray()){
        printf("Test #4 for Task 3-1 has passed\n");
    } else{
        printf("Test #4 for Task 3-1 failed\n");
    }
}