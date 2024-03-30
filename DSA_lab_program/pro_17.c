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

void insertatbegnning(int key){
    struct node* temp = createnode(key);
    if(head == NULL){
        head = temp;
    }
    temp->next = head;
    head = temp;
}

void deleteatbegnning(){
    struct node* temp = head;
    if(temp == NULL){
        return;
    }
    head = temp->next;
    free(temp); 
}

void insertionatend(int key){
    struct node* newnode = createnode(key);
    struct node* temp = head;
    if(temp==NULL){
        head = temp;
    }
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

int deletionatend(){
    struct node* temp = head;
    struct node* prev;
    if(head == NULL){
        return 0;
    }
    if(temp->next==NULL){
        free(head);
    }
    while(temp->next!=NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);

}

int main(){
    struct node* head = NULL;
    head->key = 1;
    head->next = createnode(2);
}
