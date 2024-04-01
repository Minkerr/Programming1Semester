#include "smartQuickSort.h"

#define THRESHOLD 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i + 1], &array[high]);
    return i + 1;
}

void insertSort(int array[], int low, int high) {
    for (int i = low + 1; i < high; i++) {
        int temp = array[i];
        int j = i - 1;
        while (j >= low && array[j] > temp) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void smartQsort(int array[], int low, int high) {
    if (high - low + 1 <= THRESHOLD) {
        insertSort(array, low, high);
    } else {
        int bound = partition(array, low, high);
        smartQsort(array, low, bound - 1);
        smartQsort(array, bound + 1, high);
    }
}
