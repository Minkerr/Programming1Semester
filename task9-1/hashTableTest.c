#include "hashTableTest.h"
#include "hashTable.c"
#include "stdio.h"

bool testGetMaxListLength() {
    HashTable *table = readFileToTable("task9-1/input.txt");
    bool res = getMaxListLength(table) == 2;
    deleteTable(table);
    return res;
}

bool testGetAverageListLength() {
    HashTable *table = readFileToTable("task9-1/input.txt");
    bool res = (1.24 <= getAverageListLength(table) && getAverageListLength(table) <= 1.26);
    deleteTable(table);
    return res;
}

bool testGetFillFactor() {
    HashTable *table = readFileToTable("task9-1/input.txt");
    bool res = (0.62 <= getFillFactor(table) && getFillFactor(table) <= 0.64);
    deleteTable(table);
    return res;
}

bool runAllTestsForTask9() {
    bool returnCode = true;

    if (testGetFillFactor()) {
        printf("Test #1 passed\n");
    } else {
        printf("Test #1 failed\n");
        returnCode = false;
    }
    if (testGetAverageListLength()) {
        printf("Test #2 passed\n");
    } else {
        printf("Test #2 failed\n");
        returnCode = false;
    }
    if (testGetMaxListLength()) {
        printf("Test #3 passed\n");
    } else {
        printf("Test #3 failed\n");
        returnCode = false;
    }

    return returnCode;
}