#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct Node {
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}

void insert(int data) {
    int index = data % SIZE;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (hashTable[index] == NULL)
        hashTable[index] = newNode;
    else {
        struct Node *temp = hashTable[index];
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
}

void search(int data) {
    int index = data % SIZE;
    struct Node *temp = hashTable[index];
    while (temp) {
        if (temp->data == data) {
            printf("Data %d found\n", data);
            return;
        }
        temp = temp->next;
    }
    printf("Data %d not found\n", data);
}

int main() {
    init();
    int choice, data;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insert(data);
                break;
            case 2:
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}