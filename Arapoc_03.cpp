//Angel Grace P. Arapoc
// CMSC 28 QUEUE IMPLEMENTATION
//Programming Exercises 03 
//April 08, 2024

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Define structure for a queue node
struct QNode {
    char name[50];          // Customer's name
    float bill;             // Total bill amount
    struct QNode* next;     // Pointer to the next node in the queue
};

// Define structure for the queue
struct Queue {
    struct QNode *front, *rear;   // Pointers to the front and rear of the queue
};

// Function to initialize the queue
struct Queue* INIT(){
    // Allocate memory for the queue structure
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    // Set both front and rear pointers to NULL (empty queue)
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to add a customer to the queue
void ENQUEUE(struct Queue *queue, char CName[], float Cbill){
    // Allocate memory for a new node
    struct QNode *newNode = (struct QNode*)malloc(sizeof(struct QNode));
    // Copy customer's name and bill amount to the new node
    strcpy(newNode->name, CName);
    newNode->bill = Cbill;
    newNode->next = NULL;   // Initialize next pointer to NULL

    // Check if the queue is empty
    if (queue->rear == NULL) {
        // If empty, set both front and rear to newNode
        queue->front = queue->rear = newNode;
    } else {
        // If not empty, add newNode to the rear and update rear
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to check if the queue is empty
bool EMPTY(struct Queue *queue){
    return (queue->front == NULL);   // Return true if front pointer is NULL
}

// Function to remove and return the front customer from the queue
struct QNode* DEQUEUE(struct Queue *queue){
    // Check if the queue is empty
    if(EMPTY(queue)){
        return NULL;    // If empty, return NULL
    }
    struct QNode* temp = queue->front;  // Store front node temporarily
    queue->front = queue->front->next;  // Move front pointer to the next node
    
    // If front becomes NULL, set rear to NULL as well
    if(queue->front == NULL){
        queue->rear = NULL;
    }
    return temp;    // Return the front node
}

// Function to get the front customer from the queue
struct QNode* FRONT(struct Queue* queue){
    return queue->front;    // Return the front node
}

// Main Function
int main(){
    struct Queue *checkout = INIT();   // Initialize the checkout queue
    
    // Declaration of variables
    int choice;             // User's choice
    char CName[50];         // Customer's name
    float Cbill;            // Customer's bill amount
   
    // Main menu loop
    do {
        // Print menu options
        printf("\n[ Angel's Burjer ] Counter 0\n");
        printf("\n[1] Fall in line\n[2] Serve Customer\n[3] Next Customer\n[4] Closing time\n[0] Exit\nAnswer: ");
        scanf("%d", &choice);   // Get user's choice
        
        switch(choice) {
            // Falling in line
            case 1:
                printf("Enter name: ");
                scanf("%s", CName);
                printf("Enter total bill amount: ");
                scanf("%f", &Cbill);
                ENQUEUE(checkout, CName, Cbill);   // Add customer to the queue
                break;
                
            // Serve Customer
            case 2:
                {
                    struct QNode *serveCustomer = DEQUEUE(checkout);  // Remove front customer from the queue
                    if(serveCustomer == NULL){
                        printf("The QUEUE is EMPTY. No orders to serve.\n");
                    } else {
                        printf("Now serving %s with total amount payable %.4f.\n", serveCustomer->name, serveCustomer->bill);
                        free(serveCustomer);    // Free memory for served customer node
                    }
                }
                break;
                
            // Next Customer
            case 3:
                {
                    struct QNode *nextCustomer = FRONT(checkout);   // Get front customer from the queue
                    if(nextCustomer == NULL){
                        printf("The QUEUE is EMPTY. No order to serve.\n");
                    } else {
                        printf("Next order: For %s with total amount payable of %.4f\n", nextCustomer->name, nextCustomer->bill);
                    }
                }
                break;
                
            // Closing Time
            case 4:
                {
                	if(EMPTY(checkout)){
                		printf("The QUEUE is EMPTY. No orders to serve.\n");
                		break;
					}
                    while (!EMPTY(checkout)) {
                        struct QNode *serveCustomer = DEQUEUE(checkout);   // Remove and serve all customers in the queue
                        printf("Now serving %s with total amount payable %.4f.\n", serveCustomer->name, serveCustomer->bill);
                        free(serveCustomer);    // Free memory for served customer node
                    }
                    printf("All customers have been served.\n");
                }
                break;
                
            // Terminating the program
            case 0:
            	printf("Checkout system has been terminated.");
            	break;
            	
            // Invalid Inputs
            default:
            	printf("Invalid Input.");
            	break;
        }
    } while(choice != 0);   // Continue loop until user chooses to exit
    
    // Freeing the memory of the queue structure after use
    free(checkout);
    
    return 0;   // Exit the program
}

