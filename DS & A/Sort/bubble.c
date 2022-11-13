#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubbleSort(int a[], int n){
    bool sorted = false;
    for (int i=0; i<=n-1; i++){
        sorted = true;
        for (int j=0; j<n-i-1; j++)
            if(a[j]>a[j+1]){
                swap(&a[j], &a[j+1]);
                sorted = false;
                }
        if(sorted == true) break;
    }
}

int main(){
    int a[5]={6,7,3,4,9};
    bubbleSort(a,5);
    for (int i=0; i<5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}

