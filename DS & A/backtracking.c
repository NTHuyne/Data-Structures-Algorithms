#include <stdio.h>

int a[100], n;

void PrintSolution(){
    for (int i=1; i<=n;i++){
        printf("%d", a[i]);
    }
}

void try(int k){
    for (int y=0; y<=1; y++){
        a[k] = y;
        if (k==n) {
            PrintSolution();
            printf("\n");
        }
        else try(k+1);
    }
}

int main(){
    n=3;
    try(1);
    return 0;
}