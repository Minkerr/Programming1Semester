#pragma once

// chain hash table
typedef struct HashTable HashTable;

// create new empty table
HashTable *initTable();

// add new word to hash table
int addToTable(HashTable *table, const char const *word);

// delete table and free memory
void deleteTable(HashTable **table);

// read words from file and put them to table
HashTable *readFileToTable(char *fileName);

// print all hashes and words corresponding to the hash
void printTable(HashTable *table);

// print all words in hash table with their number of appearances
void printWordsWithNumber(HashTable *table);

// get fill factor of the table
double getFillFactor(HashTable *table);

// get max length of list in cell of table
int getMaxListLength(HashTable *table);

// get average length of list in cell of table
double getAverageListLength(HashTable *table);