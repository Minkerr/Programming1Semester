#include "hashTable.h"
#include "hashTableTest.h"

int main() {
    HashTable* table = readFileToTable("task9-1/input.txt");
    printTable(table);
    printWordsWithNumber(table);
    runAllTestsForTask9();
    deleteTable(table);
}
