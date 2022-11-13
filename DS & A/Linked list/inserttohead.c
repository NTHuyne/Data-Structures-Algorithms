#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}node;

node *makenode(int v){
    node *p = (node *) malloc(sizeof(node));
    p->data = v; p->next = NULL;
    return p;
}

node *insert_to_head(node *head, int X){
    node *new_node=makenode(X);
    new_node->next=head;
    head = new_node;
    return head; 
}

void insert_to_head2(node **head_reaf, int X){
    node *new_node=makenode(X);
    new_node ->next = *head_reaf;
    *head_reaf = new_node;
}

int main(){
    int n, temp;
    node *head=NULL;
    printf("Enter n = "); scanf("%d", &n);
    for (int i=1; i<=n; i++){
        printf("Enter number %d:", i); scanf("%d", &temp);
        //head = insert_to_head(head, temp);  
        insert_to_head2(&head, temp);
    }
    node *cur=head;
    while(cur != NULL){
        printf("%d ", cur->data);
        cur = cur->next;
    }
    return 0;
}