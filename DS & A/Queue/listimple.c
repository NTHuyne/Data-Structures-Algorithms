#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    float item;
    struct Node *next;
}Node;

typedef struct Queue{
    Node *head, *tail;
}Queue;

Queue *QueueInit(){
    Queue *s;
    s = (Queue *) malloc(sizeof (Queue));
    if (s == NULL)
        return NULL;
    else{
        s->head = NULL;
        s->tail = NULL;
    }
    return s;
}

int QueueEmpty(Queue *s){
    return (s->head == NULL);
}

int QueueFull(){
    printf("\n No memory! Queue is full!\n");
}

Node *newnode(float k){
    Node *tmp = (Node*) malloc (sizeof(Node));
    if (tmp == NULL)
        QueueFull();
    tmp -> item = k;
    tmp -> next = NULL;
    return tmp;
}

void enQueue(Queue *s, float item){
    Node *node = newnode(item);
    if(node == NULL)
        return;
    if (s -> tail == NULL)
        s-> head = s-> tail = node;
    else{
        s -> tail -> next = node;
        s-> tail = node;
    }
}

void deQueue(Queue *s){
    if (QueueEmpty(s))
        printf("Queue is empty\n");
    else{
        Node *temp = s -> head;
        s->head = s->head->next;
        if (s-> head == NULL)
            s->tail = NULL;
        free(temp);
    }
}

void QueuePrint(Queue *s){
    Node *nodecount;
    float m;
    printf("\nPrint\n");
    if(QueueEmpty(s))
        printf("Queue is empty\n");
    else{
        nodecount = s-> head;
        if(s->head == s->tail){
            printf("%.1f", nodecount->item);
        }
        else{
            do{
                m = nodecount->item;
                printf("%.1f ", m);
                nodecount = nodecount -> next;
            }while (nodecount != NULL);
        }        
    }
    printf("\n");
}

int main(){
    int ch; float m;
    Queue *ptr;
    while(1){
        printf("\t QUEUE list implement \n1. Initialize QUEUE\n2. Check empty\n3. enQUEUE\n4. deQUEUE\n5. Print QUEUE\n6. Exit \n");
        printf("Call a function: "); scanf("%d", &ch);
        switch(ch){
            case 1: ptr = QueueInit();
                    break;
            case 2: if(QueueEmpty(ptr))
                        printf("Empty\n");
                    else
                        printf("Non empty\n");
                    break;
            case 3: printf("Enter a number to add to QUEUE: "); scanf("%f", &m);
                    enQueue(ptr, m);
                    break;
            case 4: deQueue(ptr);
                    break;
            case 5: QueuePrint(ptr);
                    break;
            case 6: printf("Exiting...\n");
                    exit(0);
                    break;
            default: printf("Wrong choice\n");
                    break;
        }
    }
    return 0;
}