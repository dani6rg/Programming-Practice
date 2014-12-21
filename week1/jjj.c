#include <stdio.h>

int main(){ int a,i,j,b,c,d,x,y; scanf("%d %d",&a,&b);x=a*a;y = b*b;
for(i=0;i<=2*b;i++){
for(j=0;j<=2*b;j++){
d = (j-b)*(j-b) + (i-b)*(i-b);

if(x>=d){printf("..");}
else if(y>=d && x < d){printf("XX");}
else{printf("..");}
}printf("\n");
}
return 0;}