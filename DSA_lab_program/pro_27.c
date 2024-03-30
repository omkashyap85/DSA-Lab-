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
    return newnode; // Added return statement
}

struct node* reverse(struct node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct node* newnode = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return newnode;
}

int ispalindrome(struct node* head1){
    struct node* head2 = reverse(head1);
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    while(temp1 != NULL && temp2 != NULL){
        if(temp1->key != temp2->key){
            return 0;
        }
        temp1 = temp1->next; // Move temp1 to the next node
        temp2 = temp2->next; // Move temp2 to the next node
    }
    return 1;
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(1);
    printf("%d ", ispalindrome(head));

    // Free allocated memory for all nodes in the list (optional)
    struct node* temp;
    while(head != NULL){
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
