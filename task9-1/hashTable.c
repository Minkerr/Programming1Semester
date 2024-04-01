#include "list.c"

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
    for (int i = 0; i < TABLE_SIZE; ++i) {
        table->table[i] = initList();
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

int addToTable(HashTable *table, char *word) {
    List *elementOfTable = table->table[hash(word)];
    table->countData++;
    return add(elementOfTable, word);
}

void deleteTable(HashTable *table) {
    for (int i = 0; i < table->size; i++) {
        deleteList(table->table[i]);
    }
    free(table);
    table = NULL;
}

HashTable *readFileToTable(char *fileName) {
    HashTable *table = initTable();
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return NULL;
    }
    char word[CAPACITY] = {0};
    while (fscanf_s(file, "%s ", word, CAPACITY) != EOF) {
        addToTable(table, word);
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
        if (listLen(table->table[i]) > maxLength) {
            maxLength = listLen(table->table[i]);
        }
    }
    return maxLength;
}

double getAverageListLength(HashTable *table) {
    int count = 0;
    int sumLen = 0;
    for (int i = 0; i < table->size; i++) {
        if (listLen(table->table[i]) != 0) {
            sumLen += listLen(table->table[i]);
            count++;
        }
    }
    return (double) (sumLen) / count;
}