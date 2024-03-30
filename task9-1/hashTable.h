#pragma once

typedef struct HashTable HashTable;

HashTable *initTable();

int hash(char *key);

void addToTable(HashTable *table, char *word);

void deleteTable(HashTable *table);

HashTable* readFileToTable(char* fileName);

void printTable(HashTable * table);

void printWordsWithNumber(HashTable * table);

double getFillFactor(HashTable *table);

int getMaxListLength(HashTable *table);

double getAverageListLength(HashTable *table);