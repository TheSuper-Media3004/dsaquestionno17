#include <stdio.h>
#include <stdlib.h>
struct Node {
    int size;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int size) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->size = size;
    newNode->next = NULL;
    return newNode;
}

// Function to calculate the minimum number of bottles required
int minBottles(struct Node* head, int n) {
    int count = 0;
    struct Node* temp = head;

    // Traverse the linked list
    while (temp != NULL) {
        count += n / temp->size;  
        n = n % temp->size; 
        temp = temp->next;  
    }
    
    return count;
}

// Main function
int main() {
    struct Node* head = createNode(10);
    head->next = createNode(7);
    head->next->next = createNode(5);
    head->next->next->next = createNode(1);
    
    int t;
    printf("Enter the number of test cases: ");
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int demand;
        printf("Enter the demand for milk (in litres): ");
        scanf("%d", &demand);
        printf("%d\n", minBottles(head, demand));
    }
    
    return 0;
}