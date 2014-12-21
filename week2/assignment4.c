#include <stdio.h>
int main(){
  char a,b,c,d,e,f='E';
  double z;
  scanf("%c %c %c %c %c",&a,&b,&c,&d,&e);
  z = (f-a)+(f-b)+(f-c)+(f-d)+(f-e);
  z = z/5;
  printf("Result = \"%.1f\"",z); 
  return 0;
}
