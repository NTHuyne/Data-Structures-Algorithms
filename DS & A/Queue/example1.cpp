#include <iostream>
#include <stack>
#include <queue>
#include <string.h>
using namespace std;

bool palindrome(char mystr[], int n){
    queue <char> s1;
    stack <char> s2;
    for (int i=0; i<n; i++){
        s1.push(mystr[i]);
        s2.push(mystr[i]);
    }
    while(!s1.empty() && !s2.empty()){
        if(s1.front() != s2.top()){
            return false;
            break;
        }
        s1.pop();
        s2.pop();
    }
    return true;
}

int main(){
    char mystr[]="MADAM"; int n=strlen(mystr);
    if(palindrome(mystr, n))
        printf("Is palindrome");
    else
        printf("No");
    return 0;
}