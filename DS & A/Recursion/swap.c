#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 100

void reverse(char str[],int start,int end){
    if (start >= end)
        return ;
    char tmp;
    tmp = str[start];
    str[start] = str[end];
    str[end] = tmp;
    return reverse(str, start +1, end -1);
}

int main(){
    char str[] = "Hello";
    int n = strlen(str);
    reverse(str, 0, n-1);
    printf("%s", str);
    return 0;
}