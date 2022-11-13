#include <stdio.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void selectionSort(int a[], int n){
    int index_min;
    for (int k=0; k<n-1; k++){
        index_min = k;
        for (int i = k+1; i<n; i++)
            if(a[i]<a[index_min])
                index_min=i;
        swap(&a[k], &a[index_min]);
    }
}

// void selectionSort(int a[],int n){
//     int min;
//     for(int i=0;i<n-1;++i)
//         for(int j=i+1;j<n;++j)
//             if(a[i]>a[j]) swap(&a[i],&a[j]);
    
// }

int main(){
    int a[5] = {6,3,5,8,9};
    selectionSort(a,5);
    for (int i=0; i<5; i++)
        printf("%d ", a[i]);
    return 0;
}