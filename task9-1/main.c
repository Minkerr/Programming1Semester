#include "hashTable.h"
#include "hashTableTest.h"

int main() {
    if (!runAllTestsForTask9()) {
        return -1;
    }
    HashTable *table = readFileToTable("task9-1/input.txt");
    printTable(table);
    printWordsWithNumber(table);
    deleteTable(&table);
    return 0;
}
