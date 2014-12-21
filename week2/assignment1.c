#include <stdio.h>
#define PI 3.141592
int main(){
  int r;
  double parameter;
  scanf("%d",&r);
  parameter = 2*r + 2*r*PI/3;
  printf("Radius : \"%d\"\nResult : \"%.3f\"",r,parameter);
  return 0;
}
