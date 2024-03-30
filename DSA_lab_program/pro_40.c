#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void postorderToPreorder(int postorder[], int n) {
    reverseArray(postorder, 0, n - 1);
    for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
            int temp = postorder[i];
            postorder[i] = postorder[i + 1];
            postorder[i + 1] = temp;
        }
    }
    printf("Preorder traversal: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", postorder[i]);
    }
}

int main() {
    int postorder[] = {4, 5, 2, 6, 7, 3, 1};
    int n = sizeof(postorder) / sizeof(postorder[0]);
    postorderToPreorder(postorder, n);
    return 0;
}
