//calculate the bionomial coefficient
#include <stdio.h>
#include <time.h>
#include <string.h>
#define Max 100
int M[Max][Max];

//Recursion without memmorization
int C_wo_mem(int n, int k){
    if (k==0 || k==n)
        return 1;
    else 
        return C_wo_mem(n-1,k-1) + C_wo_mem(n-1,k);
}

//Recursion with memorization
int C(int n, int k){
    if(k == 0 || k == n) M[n][k] = 1;
        else if(M[n][k] == 0) 
    M[n][k] = C(n-1,k-1) + C(n-1,k);
        return M[n][k];
}

void timming(clock_t start_time, clock_t end_time){
    clock_t clock_tick = end_time - start_time;
    long double time_in_seconds = clock_tick/(long double) CLOCKS_PER_SEC;
    printf("Total timming (in secs): %.8Lf\n", time_in_seconds);
}

int main(){
    memset(M, 0, sizeof(M));
    int k=40, n=50; //change the values of n and k
    clock_t start_1, start_2, end_1, end_2;
    start_1 = clock();
    C_wo_mem(n,k);
    end_1 = clock();
    timming(start_1, end_1);
    start_2 = clock();
    C(n,k);
    end_2 = clock();
    timming(start_2, end_2);
    return 0;
}