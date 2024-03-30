#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* next;
};

struct node* createnode(int key){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}

struct node* insertionatposition(struct node* head, int position, int key){
    if(head == NULL) {
        return NULL;
    }
    struct node* newnode = createnode(key);
    if(position == 1){
        newnode->next = head;
        return newnode;
    }
    struct node* temp = head;
    for(int i = 1; i < (position - 1) && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL) {
        return head;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

struct node* deleteatposition(struct node* head, int position){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    struct node* temp = head;
    if(position == 1){
        head = head->next;
        free(temp);
        return head;
    }
    struct node* prev = NULL;
    for(int i = 1; temp != NULL && i < position; i++){
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        return head;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = head;
    
    head = insertionatposition(head, 2, 4);
    head = deleteatposition(head, 3);
    
    // Free allocated memory for all nodes in the list (optional)
    struct node* temp;
    while(head != NULL && head->next != NULL && head->next != head) {
        temp = head;
        head = head->next;
        free(temp);
    }
    free(head);

    return 0;
}
