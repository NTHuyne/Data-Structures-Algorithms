#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct StackNode{
    float item;
    struct StackNode *next;
}StackNode;

typedef struct{
    StackNode *top;
}Stack;

Stack *StackConstruct(){
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    if (s == NULL)
        return NULL;
    s -> top = NULL;
    return s;
}

int StackEmpty(const Stack *s){
    return (s -> top == NULL);
}

int StackFull(){
    printf("STACK is full\n");
    return 1;
}

void Disp(Stack *s){
    StackNode *node;
    int ct = 0; float m;
    printf("Printf \n");
    if(StackEmpty(s))
        printf("Empty\n");
    else{
        node = s->top;
        do{
            m = node ->item;
            printf("%f \n",m);
            node = node->next;
        }while (!(node == NULL));
        
    }
}

int StackPush(Stack *s, float item){
    StackNode *node;
    node = (StackNode *) malloc(sizeof(StackNode));
    if (node == NULL){
        StackFull();
        return 1;
    }
    node ->item = item;
    node ->next = s->top;
    s->top = node;
    return 0;
}

float StackPop(Stack *s){
    float data;
    StackNode *node;
    if(StackEmpty(s))
        return 0;
    node = s->top;
    data = node ->item;
    s->top = node->next;
    free(node);
    return data; 
}

void StackDestroy(Stack *s){
    while(!(StackEmpty(s)))
        StackPop(s);
    free(s);
}

int main(){
    int ch, n, i;
    float m;
    Stack* stackPtr;
    while(1){ 
        printf("\n\n======================\n");
        printf(" STACK TEST PROGRAM \n");
        printf("======================\n");
        printf(" 1.Create\n 2.Push\n 3.Pop\n 4.Display\n 5.Exit\n");
        printf("----------------------\n");
        printf("Input number to select the appropriate operation: ");
        scanf("%d",&ch); printf("\n\n");
        switch(ch) {
            case 1: printf("INIT STACK");
                    stackPtr = StackConstruct(); break;
            case 2: printf("Input float number to insert into stack: ");
                    scanf("%f",&m);
                    StackPush(stackPtr, m); break; 
            case 3: m=StackPop(stackPtr);
                if (m != 0)
                printf("\n Data Value of the popped node: %8.3f\n",m);
                else {
                printf("\n >>> Empty Stack, can't pop <<<\n");} 
                break;
            case 4: Disp(stackPtr); break;
            case 5: printf("\n Bye! Bye! \n\n"); 
                    exit(0); 
                    break;
            default: printf("Wrong choice");
        }
    }
    return 0;
}
