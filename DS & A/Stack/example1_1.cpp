#include <iostream>
#include <stack>
using namespace std;

bool isPair(char closeStr, char openStr){
    if (closeStr == ')' && openStr == '(')
        return true;
    if (closeStr == ']' && openStr == '[')
        return true;
    if (closeStr == '}' && openStr == '{')
        return true; 
    return false;
}

bool isMatching(char X[], int n){
    stack<char> S;
    for (int i=0; i<n; i++){
        if (X[i] == '(' || X[i] == '[' || X[i] == '{')
            S.push(X[i]);
        else if (X[i] == ')' || X[i] == ']' || X[i] == '}'){
            if(S.empty())
                return false;
            else{
                char tmp = S.top();
                S.pop();
                if(!isPair(X[i], tmp))
                    return false;
            }
        }
    }
    if (S.empty())
        return true;
    return false; 
}

int main(){
    char X[] = "[](){}[]";
    if (isMatching(X, 8))
        cout<<"Balanced";
    else
        cout<<"Not Balanced";
    return 0;
}