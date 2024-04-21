#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack {
    int top;
    unsigned int capacity;
    int *array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->array = (int*)malloc(sizeof(int) * capacity);
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int key) {
    if (!isFull(stack)) {
        stack->array[++stack->top] = key;
        printf("Key pushed\n");
    }
    else {
        printf("Stack is full\n");
    }
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

int main() {
    struct Stack* stack = createStack(10);
    push(stack, 10);
    push(stack, 20);
    int popped = pop(stack);
    printf("Popped element is %d\n", popped);
    return 0;
}
