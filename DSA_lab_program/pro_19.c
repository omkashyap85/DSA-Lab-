#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* next;
};

struct node* head;

struct node* createnode(int key){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
    return newnode; // Return the newly created node
}

struct node* search(int key){
    struct node* temp = head;
    while(temp != NULL){
        if(temp->key == key){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void print(){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->key);
        temp = temp->next;
    }
}

int main(){
    head = createnode(1); // Initialize head with a newly created node
    head->next = createnode(2);
    struct node* newnode = search(2);
    print();
    return 0;
}
