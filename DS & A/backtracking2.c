#include <stdio.h>
#include <string.h>
int n,m, count, a[100], used[100];

int check(int y, int k){
    for (int j=1; j<=k-1; j++)
        if (y==a[j])
            return 0; 
    return 1;
}
void printsolution(){
    count++;
    printf("P%d: ", count);
    for (int i=1; i<=n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void try(int k){
    for (int y=1; y<=n; y++)
        if(used[y]==0){
            a[k] = y; used[y]=1;
            if (k==n) printsolution();
            else try(k+1);
            used[y]=0;
        }
}

int main(){
    scanf("%d", &n);
    memset(used, 0, n);
    try(1);
    return 0;
}