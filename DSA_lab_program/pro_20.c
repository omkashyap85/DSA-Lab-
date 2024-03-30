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

struct node* reversebyrecursion(struct node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    struct node* newhead = reversebyrecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return newhead;
}

struct node* reverse(struct node* head){
    struct node* prev = NULL;
    struct node* curr = head;
    struct node* front = NULL;
    while(curr != NULL){
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    head = prev;
    return head;
}

void printList(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct node* head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    
    printf("Original list: ");
    printList(head);
    
    head = reverse(head); // or head = reversebyrecursion(head);
    
    printf("Reversed list: ");
    printList(head);
    
    return 0;
}
