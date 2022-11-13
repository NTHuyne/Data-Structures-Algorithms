#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node *makeTreeNode(int val){
    node *newNode = NULL;
    newNode = (node *) malloc(sizeof(node));
    if(newNode == NULL){
        printf("Memory Allocation failed!\n");
        exit(1);
    }
    else{
        newNode -> data = val;
        newNode -> left = NULL;
        newNode -> right = NULL;
    }
    return newNode;
}

node *insertNode(node *root, int val, bool LEFT){
    node *newNode, *p;
    newNode = makeTreeNode(val);
    if(root == NULL)
        return newNode;
    if(LEFT){
        p = root;
        while (p -> left != NULL)
            p = p -> left;
        p->left = newNode;
    }
    else{
        p = root;
        while (p -> right != NULL)
            p = p -> right;
        p -> right = newNode;   
    }
    return root;
}

int depth(node *root){
    if(root == NULL) return 0;
    int ldepth = depth(root -> left);
    int rdepth = depth(root -> right);
    return (ldepth >= rdepth)? ldepth : rdepth;
}

int countNodes(node *root){
    if(root == NULL)
        return 0;
    else{
        int ld = countNodes(root->left);
        int rd = countNodes(root ->right);
        return 1+ ld + rd;
    }
}

void freeTree(node *root){
    if(root == NULL)
        return;
    freeTree(root -> left);
    freeTree(root->right);
    free(root);
}

void printInorder(node *root){
    if (root!=NULL){
        printInorder(root->left);
        printf("%d ", root -> data);
        printInorder(root ->right);
    }
}

void printPostorder(node *root){
    if (root!=NULL){
        printPostorder(root->left);
        printPostorder(root ->right);
        printf("%d ", root -> data);
    }
}

void printPreorder(node *root){
    if(root != NULL){
        printf("%d", root->data);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

int main(){
    node *tree = NULL;
    tree = insertNode(tree, 60, 0);
    tree = insertNode(tree, 50, 1);
    tree = insertNode(tree, 70, 0);
    tree = insertNode(tree, 10, 1);
    tree ->left = insertNode(tree->left, 30, 0);
    tree = insertNode(tree, 40, 0);
    tree ->right = insertNode(tree->right, 20, 1);
    printPostorder(tree);
    freeTree(tree);
    return 0;
}