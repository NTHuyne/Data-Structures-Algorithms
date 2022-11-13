#include<stdio.h>
#include<time.h>
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
    printf("Result for the 1st solution is: %d\n", maxSum);
}

//brute force with better implement 
void solution_2(int n, int a[]){
    int maxSum = a[0]; 
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            sum += a[j];
            if (sum>maxSum)
                maxSum=sum;
        }
    }
    printf("Result for the 2nd solution is: %d\n", maxSum);
}

//dynamic programming 
void solution_3(int n, int a[]){
    int maxSum = a[0];
    int ei = a[0];
    for (int i=1; i<n; i++){
        int u = ei + a[i];
        int v = a[i];
        if (u>v)
            ei = u;
        else ei = v;
        if (ei>maxSum)
            maxSum = ei;
    }
    printf("Result for the 3rd solution is: %d\n", maxSum);
}

//Timming
void timming(clock_t start_time, clock_t end_time){
    clock_t clock_tick = end_time - start_time;
    double time_in_seconds = clock_tick/(double) CLOCKS_PER_SEC;
    printf("Total timming (in secs): %lf\n", time_in_seconds);
}

int main(){
    //Initializing a random array
    int n = 10; // change the value of numbers of elements in array
    int a[max];
    for (int i=0; i<n; i++){
        a[i] = rand();
    }
    //1st-solution implementation
    clock_t start_1, end_1, start_2, end_2, start_3, end_3;
    start_1 = clock();
    solution_1(n, a);
    end_1 = clock();
    timming(start_1, end_1);
    //2nd-solution implementation
    start_2 = clock();
    solution_2(n, a);
    end_2 = clock();
    timming(start_2, end_2);
    //3rd-solution implementation
    start_3 = clock();
    solution_3(n, a);
    end_3 = clock();
    timming(start_3, end_3);
    return 0;
}