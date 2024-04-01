#pragma once

#define INT_SIZE (sizeof(int) * 8)

// print a number in binary notation to the console
void printBinaryNumber(int *num);

// converting a number from decimal to binary
void decimalToBinary(int num, int *convertedNum);

// converting a number from binary to decimal
int binaryToDecimal(int *num);

// add two numbers in binary notation and write to the string "result"
void addition(int *first, int *second, int *result);