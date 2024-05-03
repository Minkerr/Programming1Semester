#include "binaryAddition.h"
#include <stdbool.h>
#include <stdio.h>

bool testDecimalToBinary(void) {
    int num = -15;
    int bin[INT_SIZE] = {0};
    decimalToBinary(num, bin);
    bool result = true;

    for (int i = 0; i < INT_SIZE; ++i) {
        if (28 <= i && i <= 30) {
            result = (bin[i] == 0);
        } else {
            result = (bin[i] == 1);
        }
    }

    return result;
}

bool testBinaryToDecimal(void) {
    int binary[INT_SIZE] = {0};
    for (int i = 0; i < 32; i++) {
        binary[i] = 1;
    }
    binary[28] = 0;
    binary[29] = 0;
    binary[30] = 0;

    return binaryToDecimal(binary) == -15;
}

bool testAddition13Minus15(void) {
    int x[INT_SIZE] = {0};
    int y[INT_SIZE] = {0};
    int result[INT_SIZE] = {0};
    decimalToBinary(-15, x);
    decimalToBinary(13, y);
    addition(x, y, result);

    return binaryToDecimal(result) == -2;
}

bool testAddition1Plus0(void) {
    int x[INT_SIZE] = {0};
    int y[INT_SIZE] = {0};
    int result[INT_SIZE] = {0};
    decimalToBinary(1, x);
    decimalToBinary(0, y);
    addition(x, y, result);

    return binaryToDecimal(result) == 1;
}

bool testAdditionMinus2Minus100(void) {
    int x[INT_SIZE] = {0};
    int y[INT_SIZE] = {0};
    int result[INT_SIZE] = {0};
    decimalToBinary(-2, x);
    decimalToBinary(-100, y);
    addition(x, y, result);

    return binaryToDecimal(result) == -102;
}

bool runAllTestsTask4(void) {
    bool codeResult = true;

    if (testDecimalToBinary()) {
        printf("Test #1 for Task 4-1 has passed\n");
    } else {
        printf("Test #1 for Task 4-1 failed\n");
        codeResult = false;
    }

    if (testBinaryToDecimal()) {
        printf("Test #2 for Task 4-1 has passed\n");
    } else {
        printf("Test #2 for Task 4-1 failed\n");
        codeResult = false;
    }

    if (testAddition13Minus15()) {
        printf("Test #3 for Task 4-1 has passed\n");
    } else {
        printf("Test #3 for Task 4-1 failed\n");
        codeResult = false;
    }

    if (testAddition13Minus15()) {
        printf("Test #4 for Task 4-1 has passed\n");
    } else {
        printf("Test #4 for Task 4-1 failed\n");
        codeResult = false;
    }

    if (testAddition1Plus0()) {
        printf("Test #5 for Task 4-1 has passed\n");
    } else {
        printf("Test #5 for Task 4-1 failed\n");
        codeResult = false;
    }

    if (testAdditionMinus2Minus100()) {
        printf("Test #6 for Task 4-1 has passed\n");
    } else {
        printf("Test #6 for Task 4-1 failed\n");
        codeResult = false;
    }

    return codeResult;
}
