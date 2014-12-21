#include <stdio.h>
int main(){
  int a,b; double c;
  scanf("*%d*,*%lf*,*%d*", &a, &c, &b);
  a = (a%100-a%10)/10;
  b = b%10;
  printf("\"%04d\"<%011.5f>\"%04d\"",a,c,b);
  return 0;
}
