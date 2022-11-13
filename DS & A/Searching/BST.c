#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int key;
    struct TreeNode *left, *right, *parent; 
}TreeNode;

TreeNode *create_node(int newkey){
    TreeNode *N = (TreeNode *) malloc (sizeof(TreeNode));
    if(N==NULL){
        printf("ERROR: Out of memory! \n");
        exit(1);
    }
    else{
        N -> key = newkey;
        N->left = NULL; N->right = NULL; N->parent = NULL;
    }
    return N;
}

TreeNode *Search(int target, TreeNode *root){
    if(root == NULL)
        return NULL;
    else if (target == root ->key)
        return root;
    else if (target < root->key)
        return Search(target, root ->left);
    else
        return Search(target, root ->right);
}

TreeNode *find_min(TreeNode *root){
    if (root == NULL) return NULL;
    else
        if (root->left == NULL)
            return root;
        else
            return (find_min(root->left));
}

TreeNode *find_max(TreeNode *root){
    if (root == NULL) return NULL;
    else
        if (root->right == NULL)
            return root;
        else
            return (find_max(root->right));
}

void printInorder(TreeNode *root){
    if (root!=NULL){
        printInorder(root->left);
        printf("%d ", root -> key);
        printInorder(root ->right);
    }
}

void printPostorder(TreeNode *root){
    if (root!=NULL){
        printPostorder(root->left);
        printPostorder(root ->right);
        printf("%d ", root -> key);
    }
}

void printPreorder(TreeNode *root){
    if(root != NULL){
        printf("%d", root->key);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

TreeNode *Predecessor(TreeNode *root, TreeNode *x){
    if(x->left != NULL)
        return find_max(x->left);
    TreeNode *p = x->parent;
    while(p!=NULL && x == p->left){
        x=p;
        p=p->parent;
    }
    return p;
}

TreeNode *Successor(TreeNode *root, TreeNode *x){
    if(x->right != NULL)
        return find_min(x->right);
    TreeNode *p = x->parent;
    while(p!=NULL && x == p->right){
        x=p;
        p=p->parent;
    }
    return p;
}

TreeNode *insert (int x, TreeNode *root){
    if(root == NULL)
        return create_node(x);
    else if (x < root ->key){
        TreeNode *newNode = insert (x, root->left);
        root -> left = newNode;
        newNode -> parent = root;
    }
    else if (x > root->key){
        TreeNode *newNode = insert (x, root ->right);
        root -> right = newNode;
        newNode -> parent = root;
    }
    return root;
}

TreeNode* delete(int k, TreeNode *root) { 
    TreeNode *y; 
    if (root == NULL) printf("Not found\n"); 
    else if (k < root->key) root->left = delete(k, root->left);  
    else if (k > root->key) root->right = delete(k, root->right); 
    else
    if (root->left != NULL && root->right != NULL) { 
        y = find_min(root->right); 
        root->key = y->key; 
        root->right = delete(root->key, root->right); 
    } 
    else{ 
        y = root; 
    if (root->left== NULL) 
        root = root->right; 
    else if (root->right == NULL)
        root = root->left; 
    free(y); 
    } 
    return root; 
}

int main(){
    int A[]={9, 6, 7, 10, 15, 12};
    TreeNode *root;
    root = NULL;
    for (int i =0; i< 6; i++){
        root = insert(A[i], root); 
    }
    printInorder(root);
    return 0;
}