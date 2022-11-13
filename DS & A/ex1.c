#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
    int n=100, a[1000];
    clock_t begin, end; 
    begin = clock();
    for (int i=0; i<n; i++){
        a[i]=rand();
    }
    int smax = a[0], emax = a[0];
    for (int i=1; i<n; i++){
        int u = emax + a[i];
        if (u > a[i])
            emax = u;
            else emax = a[i];
        if (emax > smax)
            smax = emax;
    }
    printf("%d\n", smax);
    end = clock();
    double timeinsec = (double) (end - begin)/ CLOCKS_PER_SEC;
    printf("%lf", timeinsec);
    return 0;
}