#include <stdio.h>
long long int comb(int n, int k){ if(k==0 || k==n){return 1;} return comb(n-1,k) + comb(n-1,k-1);}
int main(){int a,b;scanf("%d %d",&a,&b);printf("%llu",comb(a,b));return 0;}