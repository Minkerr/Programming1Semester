#include "AVLTree.c"

void printMenu() {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Find\n");
    printf("4. Print\n");
    printf("5. Exit\n");
}

int main() {
    Tree* tree = initTree();
    int command;
    char key[CAPACITY];
    char val[CAPACITY];
    
    do {
        printMenu();
        printf("Enter the command number (1-5):");
        scanf("%d", &command);

        switch(command) {
            case 1:
                printf("Enter the key: ");
                scanf("%s", &key);
                printf("Enter the value: ");
                scanf("%s", &val);
                tree->root = insert(tree->root, key, val);
                break;
            case 2:
                printf("Enter the key: ");
                scanf("%s", &key);
                tree->root = deleteNode(tree->root, key);
                break;
            case 3:
                printf("Enter the key: ");
                scanf("%s", &key);
                char* foundValue = findValueByKey(tree->root, key);
                if(foundValue != NULL) {
                    printf("%s\n", foundValue);
                } else {
                    printf("There is no such key.\n");
                }
                break;
            case 4:
                printTree(tree->root);
                break;
            case 5:
                deleteTree(tree);
                break;
            default:
                printf("Incorrect input\n");
        }
    } while (command != 5);

}
