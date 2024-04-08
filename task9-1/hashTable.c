#include "list.h"
#include "errorCode.h"
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11

typedef struct HashTable {
    int size;
    int countData;
    List *table[TABLE_SIZE];
} HashTable;

HashTable *initTable() {
    HashTable *table = malloc(sizeof(HashTable));
    if (table == NULL) {
        return NULL;
    }
    int lastNotInitializedTable = 0;
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table->table[i] = initList();
        if (table->table[i] == NULL) {
            lastNotInitializedTable = i;
            break;
        }
    }
    if (lastNotInitializedTable != 0) {
        for (int i = 0; i < lastNotInitializedTable; ++i) {
            deleteList(table->table[i]);
        }
        free(table);
        return NULL;
    }
    table->countData = 0;
    table->size = TABLE_SIZE;
    return table;
}

int hash(const char *key) {
    int result = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        result = (result + key[i]) % TABLE_SIZE;
    }
    return result;
}

int addToTable(HashTable *table, const char * const word) {
    List *elementOfTable = table->table[hash(word)];
    table->countData++;
    return add(elementOfTable, word);
}

void deleteTable(HashTable **table) {
    for (int i = 0; i < (*table)->size; i++) {
        deleteList((*table)->table[i]);
    }
    free(*table);
    *table = NULL;
}

HashTable *readFileToTable(char *fileName) {
    HashTable *table = initTable();
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    char word[CAPACITY] = {0};
    while (fscanf_s(file, "%s ", word, CAPACITY) != EOF) {
        int addingResult = addToTable(table, word);
        if (addingResult != OK) {
            deleteTable(&table);
            fclose(file);
            return NULL;
        }
    }
    fclose(file);
    return table;
}

void printTable(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("hash: %d\nelements:\n", i);
        printList(table->table[i]);
        printf("\n");
    }
}

void printWordsWithNumber(HashTable *table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printList(table->table[i]);
    }
}

double getFillFactor(HashTable *table) {
    return (double) (table->countData) / (table->size);
}

int getMaxListLength(HashTable *table) {
    int maxLength = 0;
    for (int i = 0; i < table->size; i++) {
        if (listLength(table->table[i]) > maxLength) {
            maxLength = listLength(table->table[i]);
        }
    }
    return maxLength;
}

double getAverageListLength(HashTable *table) {
    int count = 0;
    int sumLen = 0;
    for (int i = 0; i < table->size; i++) {
        if (listLength(table->table[i]) != 0) {
            sumLen += listLength(table->table[i]);
            count++;
        }
    }
    return (double) (sumLen) / count;
}