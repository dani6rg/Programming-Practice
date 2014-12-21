#include <stdio.h>

int main(){
  double first, last, permile = 0.45;
  scanf("%lf %lf", &first,&last );
  printf("You travelled %f miles. At $%f per mile,\nyour reimbursement is $%f\n", last-first,permile,permile * (last-first));
  return 0;
}

