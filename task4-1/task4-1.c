#include <stdio.h>

#define INT_SIZE 32

void reverse(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printBinaryNumber(int *num) {
    for (int i = 0; i < INT_SIZE; i++) {
        printf("%d", num[i]);
    }
    printf("\n");
}

void decimalToBinary(int num, int *convertedNum) {
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        int bit = (num >> i) & 1;
        convertedNum[INT_SIZE - i - 1] = bit;
    }
    printBinaryNumber(convertedNum);
}

int binaryToDecimal(int *num) {
    int decimal = 0;
    int weight = 1;
    int sign = 0;
    if (num[0]) {
        sign = 1;
        weight = -1;
    }
    for (int i = INT_SIZE - 1; i > 0; i--) {
        if ((num[i] + sign) % 2) {
            decimal += weight;
        }
        weight *= 2;
    }
    return decimal - sign;
}

void addition(int *first, int *second, int *result) {
    int inMind = 0;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        result[i] = (first[i] + second[i] + inMind) % 2;
        inMind = (first[i] + second[i] + inMind > 1) ? 1 : 0;
    }
    printBinaryNumber(result);
}


