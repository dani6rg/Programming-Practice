#include <stdio.h>
int main(){
  double yardw, yardh, housew, househ ,grass;
  scanf("%lf %lf %lf %lf", &yardw, &yardh, &housew, &househ);
  grass = yardw*yardh - housew*househ;
  printf("Area of Yard : %f\n", yardw*yardh);
  printf("Area of House : %f\n", housew*househ);
  printf("Area of Grass : %f\n", grass);
  printf("Time to Cut the Grass : %f\n", grass/3);
  return 0;
}
