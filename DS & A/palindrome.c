#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool palindrome(char S[],int start,int end){
    if (start>=end)
        return true;
    else
        if (S[start] == S[end])
            palindrome(S, start+1, end-1);
        else 
            return false;
}

int main(){
    printf("Enter a string: ");
    char S[1000];
    scanf("%s", S);
    int end = strlen(S) - 1;
    if (palindrome(S, 0, end))
        printf("YES");
    else    
        printf("NO");
    return 0;
}