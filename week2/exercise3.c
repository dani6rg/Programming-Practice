#include <stdio.h>
#include <math.h>
int main(){
  double a,b,c;
  scanf("%lf %lf", &a, &b);
  c = pow(a*a+b*b,0.5);
  printf("Side1 = %f, Side2 = %f, Hypotenuse = %f\n", a, b,c );
  return 0;
}
