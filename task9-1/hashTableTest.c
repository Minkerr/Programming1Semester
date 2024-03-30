#include "hashTableTest.h"
#include "hashTable.h"
#include "stdio.h"

bool testGetMaxListLength() {
    HashTable *table = readFileToTable("task9-1/input.txt");
    bool res = (0.35 <= getFillFactor(table) && getFillFactor(table) <= 0.37);
    deleteTable(table);
    return res;
}

bool testGetAverageListLength() {
    HashTable *table = readFileToTable("task9-1/input.txt");
    bool res = getMaxListLength(table) == 2;
    deleteTable(table);
    return res;
}

bool testGetFillFactor() {
    HashTable *table = readFileToTable("task9-1/input.txt");
    bool res = (1.24 <= getAverageListLength(table) && getAverageListLength(table) <= 1.26);
    deleteTable(table);
    return res;
}

void runAllTestsForTask9() {
    if(testGetFillFactor()){
        printf("Test #1 passed\n");
    }
    else{
        printf("Test #1 failed\n");
    }
    if(testGetAverageListLength()){
        printf("Test #2 passed\n");
    }
    else{
        printf("Test #2 failed\n");
    }
    if(testGetMaxListLength()){
        printf("Test #3 passed\n");
    }
    else{
        printf("Test #3 failed\n");
    }
}