Building a double-ended queue (deque) in C involves creating a structure for the deque node, and then creating functions
to add and remove elements from both ends of the deque. Here's a simple implementation:

```c
#include <stdio.h>
#include <stdlib.h>

// Define the deque node structure
typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

// Function to create a new node
Node* newNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = node->prev = NULL;
    return node;
}

// Function to insert at the front of the deque
void insertFront(Node** front, Node** rear, int data) {
    Node* node = newNode(data);
    if (*front == NULL) {
        *front = *rear = node;
    } else {
        node->next = *front;
        (*front)->prev = node;
        *front = node;
    }
}

// Function to insert at the rear of the deque
void insertRear(Node** front, Node** rear, int data) {
    Node* node = newNode(data);
    if (*rear == NULL) {
        *front = *rear = node;
    } else {
        node->prev = *rear;
        (*rear)->next = node;
        *rear = node;
    }
}

// Function to delete from the front of the deque
void deleteFront(Node** front, Node** rear) {
    if (*front == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = *front;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    } else {
        (*front)->prev = NULL;
    }
    free(temp);
}

// Function to delete from the rear of the deque
void deleteRear(Node** front, Node** rear) {
    if (*rear == NULL) {
        printf("Deque is empty\n");
        return;
    }
    Node* temp = *rear;
    *rear = (*rear)->prev;
    if (*rear == NULL) {
        *front = NULL;
    } else {
        (*rear)->next = NULL;
    }
    free(temp);
}
```

This code defines a `Node` structure with `data`, `next`, and `prev` fields. The `newNode` function creates a new node
with the given data. The `insertFront` and `insertRear` functions add a node to the front and rear of the deque,
respectively. The `deleteFront` and `deleteRear` functions remove a node from the front and rear of the deque,
respectively.