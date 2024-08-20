/*Write a C program to create two link lists positive and negative from a Original linked list, so  
that positive linked list contains all positive elements and negative linked list contains negative   
elements. Positive and negative linked lists should use the node of existing original linked list.*/
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

void splitList(struct Node* head, struct Node** positive, struct Node** negative) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data >= 0) {
            insertNode(positive, temp->data);
        } else {
            insertNode(negative, temp->data);
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
    struct Node* original = NULL;
    struct Node* positive = NULL;
    struct Node* negative = NULL;

    int choice;
    int data;

    do {
        printf("\n-- Menu --\n");
        printf("1. Insert element into the Original list\n");
        printf("2. Split the Original list into Positive and Negative lists\n");
        printf("3. Display Original list\n");
        printf("4. Display Positive list\n");
        printf("5. Display Negative list\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &data);
                insertNode(&original, data);
                printf("Element inserted into the Original list.\n");
                break;
            case 2:
                splitList(original, &positive, &negative);
                printf("Original list split into Positive and Negative lists.\n");
                break;
            case 3:
                printf("Original list: ");
                displayList(original);
                break;
            case 4:
                printf("Positive list: ");
                displayList(positive);
                break;
            case 5:
                printf("Negative list: ");
                displayList(negative);
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
