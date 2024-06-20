// Written by: APOLINARIO, ARAPOC, BAUTISTA | MARCH 20, 2024 
// This program is a simple implementation of a stack data structure using a linked list.
// The program simulates a kitchenware washing machine. The user can add kitchenware to be washed, wash kitchenware, check the next kitchenware to be washed, wash all kitchenware, and exit the program.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char kitchenware[20]; // Stores the name of the kitchenware
    struct Node* next;    // Pointer to the next node in the stack
} Node;

typedef struct Stack {
    Node* top;  // Pointer to the top of the stack
} Stack;

// Function for initializing the stack
void initialize(Stack* stack) {
    stack->top = NULL;
}

// Function for checking if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Function to push kitchenware onto the stack
void push(Stack* stack, char* kitchenware) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocate memory for the new node
    if (newNode == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newNode->kitchenware, kitchenware); // Copy the kitchenware name to the kitchenware member of the  node
    newNode->next = stack->top;                // Set the next pointer to the current top
    stack->top = newNode;                      // Update the top pointer
}

// Function to pop kitchenware from the stack
char* pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. No more kitchenware to wash.\n");
        return NULL;
    }
    Node* temp = stack->top;                // Store the top node
    stack->top = stack->top->next;          // Update the top pointer to the next node
    char* kitchenware = strdup(temp->kitchenware); // Copy the kitchenware name
    if (kitchenware == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(EXIT_FAILURE);
    }
    free(temp);                             // Free memory allocated for the popped node
    return kitchenware;
}

// Function to get the top kitchenware without removing it from the stack
char* top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("The stack is empty. No kitchenware to wash.\n");
        return NULL;
    }
    return stack->top->kitchenware;
}

// Function to wash all kitchenware and free memory
void makeNull(Stack* stack) {
    while (!isEmpty(stack)) {
        free(pop(stack)); // Free memory allocated for kitchenware strings
    }
}

// Function to print the menu options
void printMenu() {
    printf("\nKitchenware Washing Machine\n");
    printf("[1] Add kitchenware\n");
    printf("[2] Wash kitchenware\n");
    printf("[3] Top kitchenware\n");
    printf("[4] Wash all\n");
    printf("[0] Exit\n");
    printf("Enter choice: ");
}

// Main function
int main() {
    Stack stack;
    initialize(&stack); // Initialize the stack

    int choice;
    char kitchenware[20];

    // Main menu loop
    do {
        printMenu();
        scanf("%d", &choice); // Read user choice

        switch (choice) {
            case 1:
                printf("Enter kitchenware to be washed: ");
                if (scanf("%19s", kitchenware) != 1) { // Scans kitchenware name
                    printf("Invalid input. Please try again.\n");
                    while (getchar() != '\n'); // Clear input buffer
                } else {
                    push(&stack, kitchenware); // Add kitchenware to the stack
                }
                break;
                
            case 2: // Wash specific kitchenware
                printf("\n");
                if (!isEmpty(&stack)) {
                    printf("%s is being washed.\n", pop(&stack));
                } else {
                    printf("The stack is empty. No more kitchenware to wash.\n");
                }
                break;
                
            case 3: // Get next kitchenware
                printf("\n");
                if (!isEmpty(&stack)) {
                    printf("%s is next to be washed.\n", top(&stack));
                } else {
                    printf("The stack is empty. No kitchenware to wash.\n");
                }
                break;
                
            case 4: // Wash all kitchenware
                printf("\nWashing all kitchenware:\n");
                while (!isEmpty(&stack)) { 							
                    printf("\n%s is being washed.\n", pop(&stack));
                }
                printf("\nAll kitchenware has been washed.\n");
                break;
                
            case 0: //Termination of washing machine
                printf("\nThe washing machine process has been terminated.\n");
                break;
                
            default: //Invalid Choice
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    makeNull(&stack); // Free memory allocated for the stack

    return 0;
}

