#include <stdio.h>
#include "binaryAddition.h"

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
}

int binaryToDecimal(int *num) {
    int sum = 0;
    int current = 1;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        sum += num[i] * current;
        current <<= 1;
    }
    return sum;
}

void addition(int *first, int *second, int *result) {
    int inMind = 0;
    for (int i = INT_SIZE - 1; i >= 0; i--) {
        result[i] = (first[i] + second[i] + inMind) % 2;
        inMind = (first[i] + second[i] + inMind > 1) ? 1 : 0;
    }
    printBinaryNumber(result);
}


