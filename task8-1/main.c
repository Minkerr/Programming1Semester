#include "AVLTree.h"
#include "AVLTreeTest.h"
#include <stdlib.h>
#include <stdio.h>

#define CAPACITY 256

char *readStringFromConsole() {
    char *line = calloc(CAPACITY, sizeof(char));
    if (line == NULL) {
        return NULL;
    }
    char c = '0';
    int index = 0;
    int lineSize = CAPACITY;
    while ((c = getchar()) != '\n') {
        if (lineSize == CAPACITY) {
            char *newLine = realloc(line, (lineSize + CAPACITY) * sizeof(char));
            if (newLine == NULL) {
                return NULL;
            } else {
                line = newLine;
                lineSize = lineSize + CAPACITY;
            }
        }
        line[index++] = c;
    }
    return line;
}

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Find\n");
    printf("4. Print\n");
    printf("5. Exit\n");
}

int main() {
    Tree *tree = initTree();
    bool shouldClimbUp = true;
    if (!runAllTestsForTask8()) {
        return -1;
    }
    int command = 0;
    char *key = {0};
    char *val = {0};
    do {
        printMenu();
        printf("Enter the command number (1-5): \n");
        char *readResult = readStringFromConsole();
        command = (readResult[0] - '0');

        switch (command) {
            case 1:
                printf("Enter the key: \n");
                key = readStringFromConsole();
                printf("Enter the value: \n");
                val = readStringFromConsole();
                bool shouldClimbUp = true;
                tree = insert(tree, key, val, &shouldClimbUp);
                break;
            case 2:
                printf("Enter the key: \n");
                key = readStringFromConsole();
                shouldClimbUp = true;
                tree = deleteNode(tree, key, &shouldClimbUp);
                break;
            case 3:
                printf("Enter the key: \n");
                key = readStringFromConsole();
                char *foundValue = findValueByKey(tree, key);
                if (foundValue != NULL) {
                    printf("%s\n", foundValue);
                } else {
                    printf("There is no such key.\n");
                }
                break;
            case 4:
                printTree(tree);
                break;
            case 5:
                deleteTree(&tree);
                break;
            default:
                printf("Incorrect input\n");
        }
    } while (command != 5);

    return 0;
}
