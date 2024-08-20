/*Write a C program to find union (of two linked lists) based on their information field that 
implements singly linked list (with information field Emp_Id and Name of employee for each node ).*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int Emp_Id;
    char Name[100];
    struct Node* next;
};

struct Node* createNode(int Emp_Id, const char* Name) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->Emp_Id = Emp_Id;
    strcpy(newNode->Name, Name);
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int Emp_Id, const char* Name) {
    struct Node* newNode = createNode(Emp_Id, Name);
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
        printf("Emp_Id: %d, Name: %s\n", temp->Emp_Id, temp->Name);
        temp = temp->next;
    }
}

struct Node* findUnion(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp1 = list1;
    struct Node* temp2 = list2;

    while (temp1 != NULL) {
        insertNode(&result, temp1->Emp_Id, temp1->Name);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        struct Node* current = list1;
        int found = 0;
        while (current != NULL) {
            if (current->Emp_Id == temp2->Emp_Id && strcmp(current->Name, temp2->Name) == 0) {
                found = 1;
                break;
            }
            current = current->next;
        }

        if (!found) {
            insertNode(&result, temp2->Emp_Id, temp2->Name);
        }

        temp2 = temp2->next;
    }

    return result;
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
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* result = NULL;

    int choice;
    int Emp_Id;
    char Name[100];

    do {
        printf("\n-- Menu --\n");
        printf("1. Insert node into List 1\n");
        printf("2. Insert node into List 2\n");
        printf("3. Find Union\n");
        printf("4. Display List 1\n");
        printf("5. Display List 2\n");
        printf("6. Display Union List\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Emp_Id: ");
                scanf("%d", &Emp_Id);
                printf("Enter Name: ");
                scanf("%s", Name);
                insertNode(&list1, Emp_Id, Name);
                printf("Node inserted into List 1.\n");
                break;
            case 2:
                printf("Enter Emp_Id: ");
                scanf("%d", &Emp_Id);
                printf("Enter Name: ");
                scanf("%s", Name);
                insertNode(&list2, Emp_Id, Name);
                printf("Node inserted into List 2.\n");
                break;
            case 3:
                result = findUnion(list1, list2);
                printf("Union of List 1 and List 2 found.\n");
                break;
            case 4:
                printf("List 1:\n");
                displayList(list1);
                break;
            case 5:
                printf("List 2:\n");
                displayList(list2);
                break;
            case 6:
                printf("Union List:\n");
                displayList(result);
                break;
                case 7:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}

