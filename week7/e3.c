#include <stdio.h>

typedef struct{
	int x;
	int y;
} point_t;

int main(){
	point_t pt1 = {1,1} , pt2 = {.y=1, .x=2}, pt3 = pt1;
	pt1.x = 1, pt1.y = 2;
	printf("pt1.x=%d, pt1.y=%d\n",pt1.x,pt1.y);
	printf("pt2.x=%d, pt2.y=%d\n",pt2.x,pt2.y);
	printf("pt3.x=%d, pt3.y=%d\n",pt3.x,pt3.y);
	return 0;
}