#include <stdio.h>

long long int fact(int x){
    if (x==0) return 1;
    if (x>20) return 0;
    return x*fact(x-1);
}

int main(){
    long long int a;
    scanf("%lld",&a);
    printf("%lld",fact(a));
    return 0;
}
