#include "smartQuickSort.h"

#define THRESHOLD 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int bound = partition(arr, low, high);
        quickSort(arr, low, bound - 1);
        quickSort(arr, bound + 1, high);
    }
}

void insertSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void smartQsort(int arr[], int low, int high) {
    if (low < high) {
        if (high - low + 1 <= THRESHOLD) {
            insertSort(arr + low, high - low + 1);
        } else {
            quickSort(arr, low, high);
        }
    }
}
