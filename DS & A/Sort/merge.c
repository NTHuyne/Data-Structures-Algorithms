#include <stdio.h>
#define max 500

void merge(int A[], int first, int mid, int last){
    int tempA[max];
    int first1 = first; int last1 = mid;
    int first2 = mid+1; int last2 = last;
    int index = first1;
    for(;(first1<=last1)&&(first2<=last2); ++index){
        if(A[first1]<A[first2]){
            tempA[index] = A[first1];
            ++first1;
        }
        else{
            tempA[index] = A[first2];
            ++first2;
        }
    }
    for(;first1<=last1; ++first1, ++index)
        tempA[index] = A[first1];
    for(;first2<=last2; ++first2, ++index)
        tempA[index] = A[first2];
    for (index = first; index <=last; ++index)
        A[index]=tempA[index];
}

void mergesort(int a[], int start, int end){
    int mid;
    if(start<end){
        mid = (start+end)/2;
        mergesort(a,start, mid);
        mergesort(a,mid+1,end);
        merge(a, start, mid, end);
    }
}

int main(){
    int a[] = {4, 8, 2, 0, 15, 27, 58, 10, 7, 6};
    int last = sizeof(a)/sizeof(int) - 1;
    mergesort(a, 0, last);
    for (int i = 0; i<=last; i++)
        printf("%d ", a[i]);
    return 0;
}