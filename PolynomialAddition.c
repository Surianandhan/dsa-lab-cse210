#include <stdio.h>
#include <stdlib.h>

struct Node {
    float coeff;
    int exp;
    struct Node *next;
};

void insertAtEnd(struct Node **head, float coeff, int exp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

struct Node *addPolynomials(struct Node *p, struct Node *q) {
    struct Node *result = NULL;
    while (p && q) {
        if (p->exp > q->exp) {
            insertAtEnd(&result, p->coeff, p->exp);
            p = p->next;
        } else if (q->exp > p->exp) {
            insertAtEnd(&result, q->coeff, q->exp);
            q = q->next;
        } else {
            float sum = p->coeff + q->coeff;
            if (sum != 0)
                insertAtEnd(&result, sum, p->exp);
            p = p->next;
            q = q->next;
        }
    }
    while (p) {
        insertAtEnd(&result, p->coeff, p->exp);
        p = p->next;
    }
    while (q) {
        insertAtEnd(&result, q->coeff, q->exp);
        q = q->next;
    }
    return result;
}

void display(struct Node *head) {
    while (head) {
        printf("%.1fx^%d ", head->coeff, head->exp);
        if (head->next)
            printf("+ ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;
    insertAtEnd(&poly1, 5, 2);
    insertAtEnd(&poly1, 7, 4);
    insertAtEnd(&poly1, 2, 3);
    insertAtEnd(&poly2, 8, 2);
    insertAtEnd(&poly2, 6, 4);
    insertAtEnd(&poly2, 9, 3);
    printf("Polynomial 1: ");
    display(poly1);
    printf("Polynomial 2: ");
    display(poly2);
    struct Node *sum = addPolynomials(poly1, poly2);
    printf("Sum: ");
    display(sum);
    return 0;
}