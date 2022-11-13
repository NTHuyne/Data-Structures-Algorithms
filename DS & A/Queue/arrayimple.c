#include <stdio.h>
#include <stdlib.h>

static int *s;
static int maxSize; 
static int numItems;

void QUEUEinit(int maxSize){
    s = (int *) malloc(sizeof(int)*maxSize);
    numItems = 0;
}

int QUEUEempty(){
    return (numItems == 0);
}

int QUEUEfull(){
    return (numItems == maxSize);
}

void enQUEUE(int item){
    if (QUEUEfull()){
        printf("QUEUE is full\n");
    }
    else 
        s[numItems]=item;
        numItems++;
}

int deQUEUE(){
    if (QUEUEempty()){
        printf("QUEUE is empty\n");
        return 1;
    }
    else{
        int temp;
        temp = s[numItems-1];
        for (int i=0; i<=numItems-1; i++)
            s[i] = s[i+1];
        numItems --;
        return temp;
    }
}

void QUEUEprint(){
    for (int i=0; i<=numItems-1; i++)
        printf("%d ", s[i]);
    printf("\n");
}

int main(){
    printf("Enter the max size of QUEUE: "); scanf("%d", &maxSize);
    int numpop, num;
    while(1){
        printf("\tQUEUE Array Implemementation\n");
        printf("1. Initialize the queue\n");
        printf("2. Check full\n");
        printf("3. Check empty\n");
        printf("4. Enqueue\n");
        printf("5. Dequeue\n");
        printf("6. Print queue\n");
        printf("7. EXIT\n");
        int ch;
        printf("Enter the number of funtion: "); scanf("%d", &ch);
        switch(ch){
            case 1: QUEUEinit(maxSize);
                    break;
            case 2: if(QUEUEfull())
                        printf("Queue is full\n");
                    else 
                        printf("Queue is not full\n");
                    break;
            case 3: if(QUEUEempty())
                        printf("Queue is empty\n");
                    else
                        printf("Queue is not empty\n");
                    break;
            case 4: num;
                    printf("Enter the number to push in queue: "); scanf("%d", &num);
                    enQUEUE(num);
                    break;
            case 5: deQUEUE();
                    break;
            case 6: QUEUEprint();
                    break;
            case 7: printf("End!!!\n");
                    exit(0);
                    break;
            default: printf("Unavailable input!\n");
                    break;
        }
    }
    return 0;
}