#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* next;
};

struct node* head;

void createnode(int key){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
}

void insertatbegning(int key){
    struct node* temp = createnode(key);
    temp->next = head;
    head = temp;
}

void deleteatbegning(){
    struct node* temp = head;
    head = temp->next;
    free(temp); 
}

int main(){
    struct node* head = NULL;
    head->key = 1;
    head->next = createnode(2);
}
