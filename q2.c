#include <stdio.h>
#include <stdlib.h>

//node structure
typedef struct Node {
    int value;              //value in the array
    int frequency;          //frequency of the value
    struct Node *next;      //pointer to the next node
} Node;

//function create new node
Node* create_node(int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->frequency = 1;
    newNode->next = NULL;
    return newNode;
}

//function to add value to the list
void add_to_list(Node **head, int value) {
    Node *current = *head;
    //check if the value already exist in the list
    while (current != NULL) {
        if (current->value == value) {
            current->frequency++; //increase frequency if found
            return;
        }
        current = current->next;
    }
    //if not found, create a new node and add to the list
    Node *newNode = create_node(value);
    newNode->next = *head;  //insert at the beginning
    *head = newNode;
}

//function to display list
void display_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("Value: %d, Frequency: %d\n", current->value, current->frequency);
        current = current->next;
    }
}

//function to free the list
void free_list(Node *head) {
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp); //free memory of the current node
    }
}

//main funtion
int main() {
    // sample array
    int array[] = {1, 13, 539, 41, 59, 13, -82, 79, 121, 20, 1, 4, 13, -19};
    int size = sizeof(array) / sizeof(array[0]);

    //create the linked list
    Node *head = NULL;

    //add elements from the array to the list
    for (int i = 0; i < size; i++) {
        add_to_list(&head, array[i]);
    }

    //display the list
    printf("Unique value and their frequency:\n");
    display_list(head);

    //free the list
    free_list(head);

    return 0;
}
