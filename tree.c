#include <stdio.h>
#include <stdlib.h>

struct _node{
    int value;
    struct _node *left, *right;   
};
typedef struct _node Node;

Node *addNode(Node *root, int v){
    if(root == NULL){
        Node *new = malloc(sizeof(Node));
        new->value = v;
        new->left = NULL; new->right = NULL;
        return new;
    }
    if(root->value >= v){
        root->left = addNode(root->left, v);
    }else{
        root->right = addNode(root->right, v);
    }

    return root;
}


void print(Node *root){
    if(root == NULL)
        return;
    print(root->left);
    printf("%d, ", root->value);
    print(root->right); 
}

int searchBST(Node *root, int key){
    if(root == NULL){
        return -1;
    }
    if(key == root->value)
        return key;
    if(key > root->value)
        return searchBST(root->right, key);
    else
        return searchBST(root->left, key);
}

int heightTree(Node *root){
    int left, right;
    if(root == NULL)
        return 0;
    left = heightTree(root->left);
    right = heightTree(root->right);
    return 1 + (left>right ? left:right);
    
}

int main(){
    Node *root = malloc(sizeof(Node));
    root->left = NULL; root->right = NULL;



    return 0;
}
