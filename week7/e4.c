#include <stdio.h>

typedef struct point{
	int x;
	int y;
} point_t;

point_t addpoint(point_t p1, point_t p2){
	p1.x += p2.x;
	p1.y += p2.y;
	return p1;
}
int main(){
	point_t pt1 = {1,1}, pt2 = pt1, pt3;
	pt3 = addpoint(pt1,pt2);
	printf("pt1.x=%d, pt1.y=%d\n", pt1.x, pt1.y);
	printf("pt2.x=%d, pt2.y=%d\n", pt2.x, pt2.y);
	printf("pt3.x=%d, pt3.y=%d\n", pt3.x, pt3.y);
	return 0;
}