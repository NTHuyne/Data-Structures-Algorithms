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

void inserttolast(node **head_ref, int x){
    node *new_node = makenode(x);
    if(*head_ref == NULL)
        *head_ref = new_node;
    else{
        node *last = *head_ref;
        while (last ->next!=NULL){
            last = last ->next;
        }
        last ->next = new_node;
    }
}

node *insert_tolast(node *head, int x){
    node *newnode = makenode(x);
    if (head == NULL)
        head = newnode;
    else{
        node *last = head;
        while (last -> next != NULL)
            last = last ->next;
        last -> next = newnode;
    }
    return head;

}

node *deletelist(node *head){
    node *del = head;
    while (del!=NULL){
        head = head->next;
        free (del);
        del = head;
    }
    return head;
}

int isempty(node *head){
    if(head==NULL)
        return 1;
    else    
        return 0;
}

int main(){
    int n, temp;
    node *head=NULL;
    printf("Enter n = "); scanf("%d", &n);
    for (int i=1; i<=n; i++){
        printf("Enter number %d:", i); scanf("%d", &temp);
        //inserttolast(&head, temp);
        head = insert_tolast(head, temp);
    }
    node *cur = head;   
    while (cur!=NULL){
        printf("%d ", cur->data);
        cur = cur -> next;
    }
    printf("\n");
    head = deletelist(head);
    if(isempty(head))
        printf("Yes");
        else
        printf("No");
    return 0;
}
