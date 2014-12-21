#include <stdio.h>
int main(){
  char a,b,c;
  scanf("%c %c",&a, &b);
  c = (a+b)/2 -'A'+'a';
  printf("%c",c);
  return 0;
}
