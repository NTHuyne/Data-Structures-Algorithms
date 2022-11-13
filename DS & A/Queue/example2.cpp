#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

long double convert(char mystr[], int n){
    long double num = 0;
    queue <char> S1;
    for (int i=0; i<n; i++){
        if(isdigit(mystr[i]))
            S1.push(mystr[i]);
    }
    do{
        num = 10*num + S1.front()-'0';
        S1.pop();
    }while(!S1.empty());
    return num;
}

int main(){
    char mystr[]= "2 0 ! 5 9 4 3"; int n = strlen(mystr);
    printf("%.0Lf", convert(mystr,n));
    return 0;
}