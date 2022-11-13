#include <stdio.h>
#include <time.h>

int C(int n, int k){
    if (k==0 || k==n)
        return 1;
    else
        return C(n-1,k-1) + C(n-1,k);
}

int main(){
    clock_t start, end;
    start = clock();
    printf("%d\n", C(50,15));
    end = clock();
    long double t = (long double) (end -start)/CLOCKS_PER_SEC;
    printf("%.16Lf", t);
    return 0;
}