#include <stdio.h>
int main(){ int a,b,i; scanf("%d %d",&a, &b); if (a > b){ b = a+b; a = b-a; b = b-a;} for(i=a;i<=b;i++){ if ((i%7 == 0) || (i%6 == 0)){ printf("%d\n",i);}} return 0;}