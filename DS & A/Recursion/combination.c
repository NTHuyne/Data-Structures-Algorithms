#include <stdio.h>

int combination(int n, int k){
    if (n == k)
        return 1;
    if (k == 0)
        return 1;
    return combination(n-1, k-1) + combination(n-1, k); 
}

int main(){
    printf("%d", combination(6,4));
    return 0;
}