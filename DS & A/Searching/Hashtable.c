#include <stdio.h>
#include <stdlib.h>
#define ULL unsigned long long
#define M 1007

typedef struct Node{
    ULL key;
    struct Node *next;
}Node;

Node *T[M];

int h(ULL k){
    return k%M;
}

Node *insertList(Node *head, ULL k){
    Node *p = (Node *) malloc (sizeof(Node));
    if (p==NULL) return NULL;
    p->key = k;
    p->next = head;
    head = p;
    return head;
}

Node *findList(Node *head, ULL k){
    Node *cur = head;
    while (cur != NULL){
        if(cur->key == k) return cur;
        cur = cur -> next;
    }
    return cur;
}

int find(ULL k){
    int i = h(k);
    Node *res = findList(T[i], k);
    if (res == NULL)
        return 0;
    else    
        return 1;
}

int insert(ULL k){
    int i = h(k);
    Node* res=findList(T[i],k);
    if(res==NULL){
        T[i]=insertList(T[i],k);
        return 1;
    } 
    else 
        return 0;
}

int main(){
    for (int i=0; i<M; i++) T[i] =NULL;
    ULL p;
    printf("\nInput 10 number: ");
    for (int i=0; i<10; i++){
        scanf("%d", &p);
        insert(p);
    }
    int tmp;
    printf("\nInput a number to find key = ");
    scanf("%d", &tmp);
    if(find(tmp))
        printf("\nIn the table");
    else
        printf("\nNOT in the table");
    return 0;
}