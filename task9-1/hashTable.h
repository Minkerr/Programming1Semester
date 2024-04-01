#pragma once

// chain hash table
typedef struct HashTable HashTable;

// create new empty table
HashTable *initTable();

// add new word to hash table
void addToTable(HashTable *table, char *word);

// delete table and free memory
void deleteTable(HashTable *table);

// read words from file and put them to table
HashTable* readFileToTable(char* fileName);

// print all hashes and words corresponding to the hash
void printTable(HashTable * table);

//
void printWordsWithNumber(HashTable * table);

double getFillFactor(HashTable *table);

int getMaxListLength(HashTable *table);

double getAverageListLength(HashTable *table);