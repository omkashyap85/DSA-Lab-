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

struct node* cycledetection(struct node* head){
    struct node* slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

void removal(struct node* head){
    struct node* common = cycledetection(head);
    struct node* temp = head;
    while(temp != common){
        temp = temp->next;
        common = common->next;
    }
    common->next = NULL;
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);

    removal(head);
    
    // Free the memory of all nodes after removing the cycle (optional)
    struct node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
