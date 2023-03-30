#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Doubly Linked List Node */
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

/* a utility function to create & allocate memory space for a new node*/
struct Node *createNode(int data){
    
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
    
};

/* Add Node to the Head of the Linked List */
void addToHead(struct Node **head, int data){

    /* allocating memory space for the new node */
    struct Node *newNode = createNode(data);
    newNode->next = (*head);

    if( (*head) != NULL){
        (*head)->prev = newNode;
    }

    /* updating the head of linked list */
    (*head) = newNode;
    
}

/* Add Node after a given prevoius node */
void addAfterNode(struct Node **head,int prevNodeData, int data){

    /* check if list is empty */
    if(*head == NULL){
        printf("Doubly Linked List is empty. Therefore, you cannot delete any node.\n");
        return;
    }

    /* checking if the provided prevNodeData exists in list */
    struct Node *temp = *head;
    while(temp->next != NULL){
        if(temp->data == prevNodeData){
            break;
        }
        temp = temp->next;
    }

    if(temp->next == NULL){
        printf("Provided previous node data does\'nt exists in the list!");
        return;
    }

     /* Allocating memory space for the new node */
    struct Node *newNode = createNode(data);
    
    /* Make next of new node as next of prevoius node */
    newNode->next = temp->next;

    /* Make the next of prevoius node as newNode */
    temp->next = newNode;

    /* Make prevoius node as prevoius of the newNode */
    newNode->prev = temp;

    /* changing prevoius of newNode's next node */
    if(newNode->next != NULL){
        newNode->next->prev = newNode;
    }
    
}

/* Add a node to the end of the Linked List */
void addToEnd(struct Node **head, int data){

    /* Allocating memory space for the new node */
    struct Node *newNode = createNode(data);

    /* defining a utility variable : used for finding the last node of Linked List*/
    struct Node *lastNode = *head;

    /* checking if the Linked List is empty, then make the new node as head */
    if((*head) == NULL){
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    /* Traversing to find the last element of the Linked List */
    while(lastNode->next != NULL){
        lastNode = lastNode->next;
    }

    /* changing the next property of the last node */
    lastNode->next = newNode;

    /* making the last node as prevoius of the newNode */
    newNode->prev = lastNode;
    
}

/* Delete node from starting node of the linked list*/
void deleteFromStart(struct Node **head){
    
    /* checking if Doubly Linked List is empty */
    if(*head == NULL){
        printf("Doubly Linked List is empty. Therefore, you cannot delete any node.\n");
        return;
    }

    /* a utility variable */
    struct Node *temp = *head;
    *head = temp->next;

    /* updating the head pointer to the next node */
    if(*head != NULL){
        (*head)->prev = NULL;
    }

    /* Free the memory allocated to the old head node */
    free(temp);
    
}

/* Deleting the node from the ending node of the Doubly Linked List */
void deleteFromEnd(struct Node **head){

    /* checking if the Doubly Linked List is empty */
    if(*head == NULL){
        printf("Dobule Linked List is empty. Therefore, this operation can\'t be done...");
        return;
    }

    /* traversing to find the node before the last node in list */
    struct Node *tempNode = *head;
    while(tempNode->next->next != NULL){
        tempNode = tempNode->next;
    }

    /* deleting the last element */
    free(tempNode->next);
    tempNode->next = NULL;
    
}

/* Delete a Node by proving the node data */
void deleteANode(struct Node **head, int nodeData){

    /* check if list is empty */
    if(*head == NULL){
        printf("Dobule Linked List is empty. Therefore, this operation can\'t be done...");
        return;
    }

    /* a utility variable */
    struct Node *temp = *head;
    while(temp->next != NULL){
        if(temp->data == nodeData){
            break;
        }
        temp = temp->next;
    }

    /* checking if the node data exists in list */
    if(temp->next == NULL){
        printf("The provided node data does not exits in the list");
        return;
    }
    
    struct Node *prevNode = NULL;
    struct Node *nextNode = NULL;

    prevNode = temp->prev;
    nextNode = temp->next;

    /* free */
    free(temp);
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    
}

/* a utility function to print the content of the Linked List in both forward and backward style */
void print_linkedListForwardBackward(struct Node *node){

    /* check if Linked List is empty */
    if(node == NULL){
        printf("\nLinked List is empty: {}\n");
        return;
    }
    
    struct Node* last;
    printf("\nLinked List in Forward Style: ");
    
    while (node != NULL) {
        printf("%d ", node->data);
        last = node;
        node = node->next;
    }
  
    printf("\nLinked List in Backward Style: ");
    
    while (last != NULL) {
        printf("%d ", last->data);
        last = last->prev;
    }
    
}

/* a utility function to print the content of the linked list */
void print_linkedList(struct Node *node){

    /* check if Linked List is empty */
    if(node == NULL){
        printf("\nLinked List is empty: {}\n");
        return;
    }
    
    printf("\nDoubly Linked List: {");
    
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    
    printf("}\n");
    
}

int get_choice(){
    
    int choice;
    
    printf("\n0 -Exit.");
    printf("\n1 -Adding Element to Doubly Linked List.");
    printf("\n2 -Adding Element to th End of Doubly Linked List.");
    printf("\n3 -Add Element After a Node");
    printf("\n4 -Delete Node From Head of Doubly Linked List.");
    printf("\n5 -Delete Node From End of Doubly Linked List");
    printf("\n6 -Delete a node by providing the node data.");
    printf("\n7 -Print Linked List in both forward & backward style.");

    /* getting user's choice */
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
    
}
int main(void) {

    /* default defined variables */
    struct Node *head = NULL;
    int number, user_choice, node_data;
    bool shouldContinue = true;
    
    while(shouldContinue){

        /* getting user choice according to the menu provided for user inside the get_choice() function */
        user_choice = get_choice();
        switch(user_choice){
            case 0:
                printf("\nSuccesssfully exit...\n");
                shouldContinue = false;
                break;
            
            case 1:
                printf("\nEnter the number you want to add to the head: ");
                scanf("%d", &number);
                addToHead(&head, number);
                print_linkedList(head);
                break;
            
            case 2:
                printf("\nEnter the number you want to add to the end: ");
                scanf("%d", &number);
                addToEnd(&head, number);
                print_linkedList(head);
                break;

            case 3:
                printf("Enter the node you want to add after: ");
                scanf("%d", &node_data);
                printf("Enter the number to be added to list: ");
                scanf("%d", &number);
                addAfterNode(&head, node_data, number);
                print_linkedList(head);
                break;

            case 4:
                deleteFromStart(&head);
                print_linkedList(head);
                break;

            case 5:
                deleteFromEnd(&head);
                print_linkedList(head);
                break;

            case 6:
                printf("Enter the node to be deleted: ");
                scanf("%d", &node_data);
                deleteANode(&head, node_data);
                break;

            case 7:
                print_linkedListForwardBackward(head);
                break;

            default:
                printf("\nSuccesssfully exit...\n");
                shouldContinue = false;
                break;
            
        }
    }
    
    return 0;
}
