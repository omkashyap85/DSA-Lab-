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

void topView(struct Node* root)
{
	if (root == NULL)
		return;
	int mpp[1000] = { 0 };
	struct Queue q;
	initQueue(&q);
	enqueue(&q, (struct Pair) { root, 0 });
	while (!isEmpty(&q))
	{
		struct Pair it = dequeue(&q);
		struct Node* node = it.node;
		int line = it.line;
		if (mpp[line] == 0)
			mpp[line] = node->data;
		if (node->left != NULL)
			enqueue(&q, (struct Pair) { node->left, line - 1 });
		if (node->right != NULL)
			enqueue(&q, (struct Pair) { node->right, line + 1 });
	}
	for (int i = 0; i < 1000; ++i)
	{
		if (mpp[i] != 0)
			printf("%d ", mpp[i]);
	}
}

int main()
{
	struct Node* root = newNode(1);
	root->left = newNode(4);
	root->right = newNode(31);
	root->left->right = newNode(8);
	root->left->right->right = newNode(5);
	topView(root);
	return 0;
}
