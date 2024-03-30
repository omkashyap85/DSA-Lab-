#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node* left;
	struct Node* right;
	int hd;
	int data;
};

struct Node* newNode(int key)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->left = node->right = NULL;
	node->data = key;
	return node;
}

struct Pair {
	struct Node* node;
	int line;
};

struct QueueNode {
	struct Pair pair;
	struct QueueNode* next;
};

struct Queue {
	struct QueueNode* front, * rear;
};

void initQueue(struct Queue* q)
{
	q->front = q->rear = NULL;
}

int isEmpty(struct Queue* q)
{
	return q->front == NULL;
}

void enqueue(struct Queue* q, struct Pair pair)
{
	struct QueueNode* temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
	temp->pair = pair;
	temp->next = NULL;
	if (isEmpty(q))
	{
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

struct Pair dequeue(struct Queue* q)
{
	if (isEmpty(q))
	{
		struct Pair temp;
		temp.node = NULL;
		temp.line = -1;
		return temp;
	}
	struct QueueNode* temp = q->front;
	struct Pair pair = temp->pair;
	q->front = q->front->next;
	free(temp);
	return pair;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int min(int a, int b)
{
	return (a < b) ? a : b;
}

void bottomView(struct Node* root)
{
	if (root == NULL)
		return;
	int min_line = 0, max_line = 0;
	struct Queue q;
	initQueue(&q);
	enqueue(&q, (struct Pair) { root, 0 });
	while (!isEmpty(&q))
	{
		struct Pair it = dequeue(&q);
		struct Node* node = it.node;
		int line = it.line;
		min_line = min(min_line, line);
		max_line = max(max_line, line);
		if (node->left != NULL)
			enqueue(&q, (struct Pair) { node->left, line - 1 });
		if (node->right != NULL)
			enqueue(&q, (struct Pair) { node->right, line + 1 });
	}
	int* bottomView = (int*)malloc(sizeof(int) * (max_line - min_line + 1));
	for (int i = 0; i < max_line - min_line + 1; ++i)
	{
		bottomView[i] = 0;
	}
	initQueue(&q);
	enqueue(&q, (struct Pair) { root, -min_line });
	while (!isEmpty(&q))
	{
		struct Pair it = dequeue(&q);
		struct Node* node = it.node;
		int line = it.line;
		bottomView[line] = node->data;
		if (node->left != NULL)
			enqueue(&q, (struct Pair) { node->left, line - 1 });
		if (node->right != NULL)
			enqueue(&q, (struct Pair) { node->right, line + 1 });
	}
	for (int i = 0; i < max_line - min_line + 1; ++i)
	{
		printf("%d ", bottomView[i]);
	}
	free(bottomView);
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(4);
	root->right = newNode(31);
	root->left->right = newNode(8);
	root->left->right->right = newNode(5);
	bottomView(root);
	return 0;
}
