#include <stdio.h>
#define abs(x) ((x) <0 ? -(x) : (x))

int main(){ int a,i,j,b, x = a*a; scanf("%d",&a);
for(i=0;i<=2*a;i++){
for(j=0;j<=2*a;j++){
b = (j-a)*(j-a) + (i-a)*(i-a);
if(x>b){printf("XX");}
else{printf("..");}
}printf("\n");
}
return 0;}