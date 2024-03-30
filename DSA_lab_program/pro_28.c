
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node* next;
};

struct node* createnode(int key){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
}

struct node* nthnode(struct node* head, int n){
    struct node* temp = head;
    int length = 0, var = 0, i =0;
    while(temp!=NULL){
        length++;
        temp = temp->next;
    }
    temp = head;

    var = (length+1)-n;
    while(i!=var){
        temp=temp->next;
        i++;
    }
    struct node* del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return temp;
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(1);
    struct node* ans = nthnode(head, 2);
}
