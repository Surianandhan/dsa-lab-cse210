#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->link = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data) {
    struct Node *newNode = createNode(data);
    newNode->link = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data) {
    if (*head == NULL) {
        *head = createNode(data);
        return;
    }
    struct Node *temp = *head;
    while (temp->link)
        temp = temp->link;
    temp->link = createNode(data);
}

void insertAtPosition(struct Node **head, int data, int pos) {
    if (pos < 0) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 0) {
        insertAtBeginning(head, data);
        return;
    }
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
    for (int i = 0; temp && i < pos - 1; i++)
        temp = temp->link;
    if (!temp) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    newNode->link = temp->link;
    temp->link = newNode;
}

void deleteByValue(struct Node **head, int data) {
    if (*head == NULL) {
        printf("Empty list\n");
        return;
    }
    struct Node *prev = NULL, *temp = *head;
    while (temp && temp->data != data) {
        prev = temp;
        temp = temp->link;
    }
    if (!temp) {
        printf("Node not found\n");
        return;
    }
    if (prev)
        prev->link = temp->link;
    else
        *head = temp->link;
    free(temp);
    printf("Node deleted\n");
}

void display(struct Node *head) {
    if (!head) {
        printf("Empty list\n");
        return;
    }
    printf("List: ");
    while (head) {
        printf("%d ", head->data);
        head = head->link;
    }
    printf("\n");
}

int main() {
    struct Node *head = NULL;
    int choice, data, pos;
    while (1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n4. Delete by Value\n5. Display\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(&head, data);
                break;
            case 5:
                display(head);
                break;
            case 0:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}