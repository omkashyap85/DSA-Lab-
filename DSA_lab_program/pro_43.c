#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow\n");
        return NULL;
    }
    newNode->data = key;
    newNode->next = NULL;
    return newNode;
}

void push(int key) {
    struct Node* newNode = createNode(key);
    if (newNode != NULL) {
        newNode->next = top;
        top = newNode;
    }
}

int isEmpty() {
    return top == NULL;
}

struct Node* pop() {
    if (!isEmpty()) {
        struct Node* temp = top;
        top = top->next;
        return temp;
    }
    else {
        printf("Stack Underflow\n");
        return NULL;
    }
}

struct Node* peek() {
    if (!isEmpty()) {
        return top;
    }
    else {
        return NULL;
    }
}

int main() {
    int choice, key;
    struct Node* temp;
    while (1) {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &key);
                push(key);
                break;
            case 2:
                temp = pop();
                if (temp != NULL)
                    printf("Popped element is %d\n", temp->data);
                break;
            case 3:
                temp = peek();
                if (temp != NULL)
                    printf("Top element is %d\n", temp->data);
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
