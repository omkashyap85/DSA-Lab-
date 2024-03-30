#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *prev, *next;
};

struct node* createnode(int key){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}

struct node* middle(struct node* head){
    struct node* slow = head;
    struct node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    printf("%d\n", middle(head)->key);

    // Free allocated memory for all nodes in the list (optional)
    struct node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
