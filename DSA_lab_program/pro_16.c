#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node* next;
};

struct node* head;

struct node* createnode(int key) {
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}

void insertatbegning(int key) {
    struct node* temp = createnode(key);
    temp->next = head;
    head = temp;
}

void deleteatbegning() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    head = temp->next;
    free(temp); 
}

int main() {
    head = NULL;
    head = createnode(1);
    head->next = createnode(2);
    return 0;
}
