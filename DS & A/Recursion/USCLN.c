#include <stdio.h>

int USCLN(int p, int q){
    int r = p%q;
    if (r == 0)
        return q;
    else{
        return USCLN(q,r);
    }
}

int main(){
    printf("%d", USCLN(1048, 24));
    return 0;
}