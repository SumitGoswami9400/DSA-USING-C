/*Write a C program to split a singly linked list in two linked lists, the node information is given 
by the user at  which linked list has to split.*/
#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void splitLinkedList(struct Node* head, int splitValue, struct Node** first, struct Node** second) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == splitValue) {
            *first = head;
            *second = temp->next;
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }
}

void clearList(struct Node** head) {
    struct Node* current = *head;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
}

int main() {
    struct Node* head = NULL;
    struct Node* first = NULL;
    struct Node* second = NULL;

    int choice;
    int data;
    int splitValue;

    do {
        printf("\n-- Menu --\n");
        printf("1. Insert element into the Linked List\n");
        printf("2. Split the Linked List\n");
        printf("3. Display the Original Linked List\n");
        printf("4. Display the First Linked List\n");
        printf("5. Display the Second Linked List\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter an element: ");
                scanf("%d", &data);
                insertNode(&head, data);
                printf("Element inserted into the Linked List.\n");
                break;
            case 2:
                printf("Enter the value at which to split the Linked List: ");
                scanf("%d", &splitValue);
                splitLinkedList(head, splitValue, &first, &second);
                printf("Linked List split into two lists.\n");
                break;
            case 3:
                printf("Original Linked List: ");
                displayList(head);
                break;
            case 4:
                printf("First Linked List: ");
                displayList(first);
                break;
            case 5:
                printf("Second Linked List: ");
                displayList(second);
                break;
                case 6:
                exit(0);
           default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

