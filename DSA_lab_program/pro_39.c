#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *left, *right;
};

struct Node* newNode(int item)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = item;
	temp->left = temp->right = NULL;
	return temp;
}

void recursion(struct Node *root, int level, int* res, int* res_size)
{
	if (root == NULL) return;
	if (*res_size == level) {
		res[*res_size] = root->data;
		(*res_size)++;
	}
	recursion(root->right, level + 1, res, res_size);
	recursion(root->left, level + 1, res, res_size);
}

int* rightSideView(struct Node *root, int* returnSize) {
	if (root == NULL) {
		*returnSize = 0;
		return NULL;
	}
	int* res = (int*)malloc(sizeof(int) * 1000);
	int res_size = 0;
	recursion(root, 0, res, &res_size);
	*returnSize = res_size;
	return res;
}

int main()
{
	struct Node* root = newNode(10);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(7);
	root->left->right = newNode(8);
	root->right->right = newNode(15);
	root->right->left = newNode(12);

	int returnSize;
	int* result = rightSideView(root, &returnSize);

	printf("Right side view of the binary tree:\n");
	for (int i = 0; i < returnSize; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");

	free(result);

	return 0;
}
