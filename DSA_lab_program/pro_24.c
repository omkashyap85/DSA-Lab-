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

struct node* insertatposition(struct node* head, int key, int position){
    if(position <= 0){
        return head;
    }
    struct node* newnode = createnode(key);
    struct node *temp = head;
    if(position == 1){
        if (head != NULL) {
            newnode->next = head;
            head->prev = newnode;
        }
        return newnode;
    }
    int count = 1;
    while(temp != NULL && count != position - 1){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        return head;
    }
    newnode->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}

struct node* deleteatposition(struct node* head, int position){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    struct node* temp = head;
    if(position == 1){
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        return head;
    }
    int count = 1;
    while(temp != NULL && count != position){
        temp = temp->next;
        count++;
    }
    if(temp == NULL){
        return head;
    }
    if(temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if(temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);
    return head;
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->prev = head;
    head = insertatposition(head, 4, 2);
    head = deleteatposition(head, 2);

    // Free allocated memory for all nodes in the list (optional)
    struct node* temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
