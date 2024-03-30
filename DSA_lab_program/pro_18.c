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

void insertatbeginning(int key){
    struct node* temp = createnode(key);
    if(head == NULL){
        head = temp;
    }
    temp->next = head;
    head = temp;
}

void deleteatbeginning(){
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
    if(temp == NULL){
        head = newnode;
        return;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newnode;
}

int deletionatend(){
    struct node* temp = head;
    struct node* prev = NULL;
    if(head == NULL){
        return 0;
    }
    if(temp->next == NULL){
        free(head);
        head = NULL;
        return 1;
    }
    while(temp->next != NULL){
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
    return 1;
}

void insertatposition(int position, int key){
    struct node* temp = head;
    struct node* prev = NULL;
    if(position == 1){
        insertatbeginning(key);
    }
    else{
        int count = 1; // Start count from 1
        while(temp != NULL && count != position){
            count++;
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL){
            struct node* newnode = createnode(key);
            newnode->next = temp;
            if(prev != NULL)
                prev->next = newnode;
        }
        else if(prev != NULL){ // If temp is NULL and prev is not NULL, insert at the end
            prev->next = createnode(key);
        }
        
    }
}

void deleteatposition(int position){
    struct node* temp = head;
    struct node* prev = NULL;
    if(position == 1){
        deleteatbeginning();
    }
    else{
        int count = 1; // Start count from 1
        while(temp != NULL && count != position){
            count++;
            prev = temp;
            temp = temp->next;
        }
        if(temp != NULL && temp->next != NULL){
            prev->next = temp->next;
            free(temp);
        }
        else if(temp != NULL && temp->next == NULL){
            free(temp);
            if(prev != NULL)
                prev->next = NULL;
            else
                head = NULL;
        }
    }
}

int main(){
    head = createnode(1); // Initialize head with a newly created node
    head->next = createnode(2);
    return 0;
}
