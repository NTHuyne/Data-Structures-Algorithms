#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// int Partition(int A[], int left, int right){
//     int i = left; int j = right+1;
//     int pivot = A[left];
//     while(true){
//         i = i+1;
//         while(i<= right && pivot>=A[j])
//             i = i+1; 
//         j -= 1;
//         while(j>= left && pivot<A[j]) 
//             j = j-1;
//         if(i>=j) break;
//         swap(&A[i], &A[j]);
//     }
//     swap(&A[j], &A[left]);
//     return i;
// }

// int Partition(int A[], int left, int right){
//     int pivot = A[(left+right)/2];
//     while(left<right){
//         while(A[left] <pivot)
//             left++;
//         while(A[right]>pivot)
//             right--;
//         if(left<right){
//             swap(&A[left],&A[right]);
//             left++;right--;
//         }
//     }
//     return left+1;
// }

int Partition(int A[], int left, int right){
    int pivot = A[right];
    int j = left -1;
    for(int i = left; i<right; i++){
        if(pivot>=A[i]){
            j = j+1;
            swap(&A[i], &A[j]);
        }
    }
    A[right] = A[j+1];
    A[j+1] = pivot;
    return j+1;
}

void QuickSort(int A[], int left, int right){
    int index_pivot;
    if (left<right){
        index_pivot = Partition(A, left, right);
        QuickSort(A, left, index_pivot-1);
        QuickSort(A, index_pivot+1, right);
    }
}

int main(){
    int A[]={7,4,6,9,10,8};
    QuickSort(A,0,5);
    for (int i=0; i<6; i++)
        printf("%d ", A[i]);
    return 0;
}