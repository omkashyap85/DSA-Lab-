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

struct node* commonnode(struct node* head1, struct node* head2){
    struct node *temp1 = head1; 
    struct node *temp2 = head2;
    int l1=0, l2 =0, moves = 0;
    while(temp1!=NULL){
        l1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        l2++;
        temp2=temp2->next;
    }
    temp1 = head1;
    temp2 = head2;
    if(l1>l2){
    	int i;
        moves=l1-l2;
        for( i=0;i<moves;i++){
            temp1=temp1->next;
        }
    }
    else{
        moves = l2-l1;
        for(int i=0;i<moves;i++){
            temp2=temp2->next;
        }
    }
    while(temp1!=NULL && temp2!=NULL){
        if(temp1 == temp2){ // Changed = to ==
            return temp1;
        }
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return NULL; // Return NULL if no common node is found
}

int main(){
    struct node* head1 = createnode(1);
    head1->next = createnode(2);
    head1->next->next = createnode(3);

    struct node* head2 = createnode(4);
    head2->next = head1->next; // Creating a common node
    
    struct node* result = commonnode(head1, head2);
    if(result)
        printf("Common node key: %d\n", result->key);
    else
        printf("No common node found.\n");
        
    return 0;
}
