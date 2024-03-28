#include "task4-1.c"
#include <stdbool.h>
#include <stdio.h>

bool testReverse() {
    int a[] = {5, 4, 3, 2, 1};
    reverse(a, 5);
    return a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5;
}

bool testDecimalToBinary() {
    int num = -15;
    int bin[32] = {};
    decimalToBinary(num, bin);
    bool result = true;

    for (int i = 0; i < 32; ++i) {
        if (28 <= i && i <= 30) {
            result = (bin[i] == 0);
        } else {
            result = (bin[i] == 1);
        }
    }

    return result;
}

bool testBinaryToDecimal() {
    int binary[32];
    for (int i = 0; i < 32; i++) {
        binary[i] = 1;
    }
    binary[28] = 0;
    binary[29] = 0;
    binary[30] = 0;

    return binaryToDecimal(binary) == -15;
}

bool testAddition13Minus15(){
    int x[32];
    int y[32];
    int res[32];
    decimalToBinary(-15, x);
    decimalToBinary(13, y);
    addition(x, y, res);

    return binaryToDecimal(res) == -2;
}

bool testAddition1Plus0(){
    int x[32];
    int y[32];
    int res[32];
    decimalToBinary(1, x);
    decimalToBinary(0, y);
    addition(x, y, res);

    return binaryToDecimal(res) == 1;
}

bool testAdditionMinus2Minus100(){
    int x[32];
    int y[32];
    int res[32];
    decimalToBinary(-2, x);
    decimalToBinary(-100, y);
    addition(x, y, res);

    return binaryToDecimal(res) == -102;
}

void runAllTestsTask4() {
    if (testReverse()) {
        printf("Test #1 for Task 4-1 has passed\n");
    } else {
        printf("Test #1 for Task 4-1 failed\n");
    }

    if (testDecimalToBinary()) {
        printf("Test #2 for Task 4-1 has passed\n");
    } else {
        printf("Test #2 for Task 4-1 failed\n");
    }

    if (testBinaryToDecimal()) {
        printf("Test #3 for Task 4-1 has passed\n");
    } else {
        printf("Test #3 for Task 4-1 failed\n");
    }

    if (testAddition13Minus15()) {
        printf("Test #4 for Task 4-1 has passed\n");
    } else {
        printf("Test #4 for Task 4-1 failed\n");
    }

    if (testAddition13Minus15()) {
        printf("Test #4 for Task 4-1 has passed\n");
    } else {
        printf("Test #4 for Task 4-1 failed\n");
    }

    if (testAddition1Plus0()) {
        printf("Test #5 for Task 4-1 has passed\n");
    } else {
        printf("Test #5 for Task 4-1 failed\n");
    }

    if (testAdditionMinus2Minus100()) {
        printf("Test #5 for Task 4-1 has passed\n");
    } else {
        printf("Test #5 for Task 4-1 failed\n");
    }
}
