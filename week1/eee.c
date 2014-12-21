#include <stdio.h>
int main(){ int a,i,j=0,x=1; scanf("%d",&a);
for(i=0;i<a;i++){
printf("F(%d) = %d",i,j);
j = j^x;
x = j^x;
j = j^x;
x = j+x;
}
return 0;}