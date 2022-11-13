#include <stdio.h>
#include <stdlib.h>

static int *s;
static int maxSize;
static int numItems;

void STACKinit(int maxSize){
    s = (int *) malloc(maxSize*sizeof(int));
    numItems = 0;
}

int STACKempty(){
    return numItems == 0;
}

int STACKfull(){
    return numItems == maxSize;
}

void STACKpush(int item){
    if(STACKfull()){
        printf("ERROR! STACK is full");
    }
    else{
        s[numItems] = item;
        numItems++;
    }
}

int STACKpop(){
    if (STACKempty()) 
    printf("ERROR! Stack is empty");
    else{
        numItems--;
        return s[numItems+1];
    }
}

int main(){
    printf("Enter maxsize of the stack: "); scanf("%d", &maxSize);
    printf("\t STACK Implementation\n");
    printf("1. Initialize the stack\n");
    printf("2. Checking full\n");
    printf("3. Checking empty\n");
    printf("4. Push new item\n");
    printf("5. Pop the top item\n");
    printf("6. Printf the top element of the stack\n");
    printf("7. Exit!\n");
    int num;
    do{
        int temp;
        printf("Choose a function: "); scanf("%d", &num);
        switch (num){
        case 1: STACKinit(maxSize);
                break;
        case 2: if(STACKfull())
                    printf("Stack is full!\n");
                else    
                    printf("Stack is not full\n");
                break;
        case 3: if(STACKempty())
                    printf("Stack is empty!\n");
                else 
                    printf("Stack is not empty\n");
                break;
        case 4: printf("Enter a number to push into the STACK: "); scanf("%d", &temp);
                STACKpush(temp);
                break;
        case 5: STACKpop();
                break;
        case 6: printf("%d\n", s[numItems-1]);
                break;
        default: break;
        }
    } while(num != 7);
    return 0;
}