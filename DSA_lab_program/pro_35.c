
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

struct node* LCA(struct node* root, struct node* node1, struct node* node2){
    if(root==NULL || root == node1 || root == node2){
        return root;
    }
    struct node* left = LCA(root->left, node1, node2);
    struct node* right = LCA(root->right, node1, node2);
    if(left==NULL){
        return right;
    }
    else if(right == NULL){
        return left;
    }
    else{
        return root;
    }
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
    LCA(root, root->left, root->right);
    return 0;
}
