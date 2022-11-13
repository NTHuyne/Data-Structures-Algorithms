#include <stdio.h>

void insertionSort(int a[], int size){
    int pos, temp;
    for (int k=1;k<size; k++){
        temp = a[k];
        pos = k;
        while ((pos>0) && (a[pos-1]>temp)){
            a[pos] = a[pos-1];
            pos --;
        }
        a[pos] = temp;
    }
}

int main(){
    int a[5] = {5,8,7,2,9};
    insertionSort(a,5);
    for (int i=0; i<5; i++){
        printf("%d ", a[i]);
    }
    return 0;
}