#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>

#define M 11
struct Chain{
	int key;
    struct Chain *next;
};

typedef struct Chain Node;
Node * T[M];

int h(int k){
	return k%M;
}


Node *insertList(Node *head, int k){
     Node *p=(Node*)malloc(sizeof(Node));
     p->key=k%M;
     p->next=head;
     return p;
}

Node *findList(Node* head, int k){
	Node *temp=head;
	while(temp!=NULL){
		if(temp->key==k%M)
			return temp;
		temp=temp->next;
	}
	return temp;
}

int find(int k){
	int i=h(k);
	Node *res=findList(T[i], k);
	if(res==NULL){
		return 0;
	}else {
		return 1;
	}
}

int insert(int k){
	int i=h(k);
	if(find(k)==0)
		return 0;

	T[i]=insertList(T[i],k);
	return 1;
}	

int main(){
	for(int i=0;i<M;i++){
	T[i]=NULL;
}
    n=10;
    int k;
    for(int i=0;i<n;i++){
    	scanf("%d", k);
    	insert();
    }
	return 0;
}
