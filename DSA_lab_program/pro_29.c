#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

struct node* createnode(int key){
    struct node* newnode = (struct node*) malloc (sizeof(struct node));
    newnode->key = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* createbinary(struct node* root){
    int key;
    printf("Enter the data: ");
    scanf("%d ", &key);
    if(key == -1){
        return NULL;
    }
    root = createnode(key);
    printf("Enter data in left of %d", key);
    root->left = createbinary(root->left);
    printf("Enter data in right of %d", key);
    root->right = createbinary(root->right);
    return root;
}

int main(){
    struct node* root =NULL;
    root = createbinary(root);
    return 0;
}
