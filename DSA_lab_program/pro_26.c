#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *next;
};

struct node* createnode(int key){
    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}

struct node* merge(struct node* head1, struct node* head2){
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    struct node* head3 = NULL;
    struct node* temp3;

    if(temp1 == NULL)
        return head2;
    if(temp2 == NULL)
        return head1;

    if(temp1->key < temp2->key){
        head3 = createnode(temp1->key);
        temp1 = temp1->next;
    }
    else{
        head3 = createnode(temp2->key);
        temp2 = temp2->next;
    }
    
    temp3 = head3;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->key < temp2->key){
            temp3->next = createnode(temp1->key);
            temp1 = temp1->next;
        }
        else{
            temp3->next = createnode(temp2->key);
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
    }

    while(temp1 != NULL){
        temp3->next = createnode(temp1->key);
        temp1 = temp1->next;
        temp3 = temp3->next;
    }

    while(temp2 != NULL){
        temp3->next = createnode(temp2->key);
        temp2 = temp2->next;
        temp3 = temp3->next;
    }
    
    return head3;
}

int main(){
    struct node* head1 = createnode(1);
    struct node* head2 = createnode(1);
    head1->next = createnode(2);
    head1->next->next = createnode(4);
    head2->next = createnode(3);
    
    struct node* merged_head = merge(head1, head2);    

    // Free allocated memory for all nodes in the merged list (optional)
    struct node* temp;
    while(merged_head != NULL){
        temp = merged_head;
        merged_head = merged_head->next;
        free(temp);
    }
    
    return 0;
}
