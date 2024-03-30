#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct StackNode {
    struct Node* data;
    struct StackNode* next;
};

struct StackNode* newStackNode(struct Node* data) {
    struct StackNode* stackNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isEmpty(struct StackNode* root) {
    return !root;
}

void push(struct StackNode** root, struct Node* data) {
    struct StackNode* stackNode = newStackNode(data);
    stackNode->next = *root;
    *root = stackNode;
}

struct Node* pop(struct StackNode** root) {
    if (isEmpty(*root))
        return NULL;
    struct StackNode* temp = *root;
    *root = (*root)->next;
    struct Node* popped = temp->data;
    free(temp);
    return popped;
}

void preToPost(int pre[], int size) {
    struct Node* root = newNode(pre[0]);
    struct StackNode* stack = NULL;
    push(&stack, root);
    int i;
    for (i = 1; i < size; ++i) {
        struct Node* temp = NULL;
        while (!isEmpty(stack) && pre[i] > stack->data->data) {
            temp = pop(&stack);
        }
        if (temp != NULL) {
            temp->right = newNode(pre[i]);
            push(&stack, temp->right);
        } else {
            temp = stack->data;
            temp->left = newNode(pre[i]);
            push(&stack, temp->left);
        }
    }
    while (!isEmpty(stack)) {
        struct Node* temp = pop(&stack);
        printf("%d ", temp->data);
    }
}

int main() {
    int pre[] = {40, 30, 35, 80, 100};
    int size = sizeof(pre) / sizeof(pre[0]);
    preToPost(pre, size);
    return 0;
}
