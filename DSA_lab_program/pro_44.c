#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

bool isValid(char ch[], int size) {
    char stack[MAX_SIZE];
    int top = -1;
    for (int i = 0; i < size; i++) {
        if ((top != -1 && stack[top] == '(' && ch[i] == ')') || 
            (top != -1 && stack[top] == '[' && ch[i] == ']') || 
            (top != -1 && stack[top] == '{' && ch[i] == '}')) {
            top--;
        }
        else {
            stack[++top] = ch[i];
        }
    }
    if (top == -1) {
        return true;
    }
    return false;
}

int main() {
    char ch[] = "[()]{}{[()()]()}";
    int size = strlen(ch);
    if (isValid(ch, size)) {
        printf("Valid\n");
    }
    else {
        printf("Invalid\n");
    }
    return 0;
}
