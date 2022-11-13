#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#define max 1000000

//brute force
void solution_1(int n, int a[]){
    int maxSum = a[0]; 
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for (int k=i; k<j; k++){
                sum += a[k];
                if (sum>maxSum)
                maxSum=sum;
            }
        }
    }
    printf("%d\n", maxSum);
}

void timming(clock_t start_time, clock_t end_time){
    clock_t clock_tick = end_time - start_time;
    double time_in_seconds = clock_tick/(double) CLOCKS_PER_SEC;
    printf("%lf\n", time_in_seconds);
}

int main(){
    //Initializing a random array
    int n = 10;
    int a[max];
    for (int i=0; i<n; i++){
        a[i] = rand();
    }
    //1st-solution implementation
    clock_t start_1, end_1;
    start_1 = clock();
    printf("Result for the 1st solution is: "); solution_1(n, a);
    end_1 = clock();
    double total = (double) (end_1 - start_1)/CLOCKS_PER_SEC;
    printf("Total timming: %f\n", total);
    return 0;
}