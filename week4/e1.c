#include <stdio.h>

int main(void){
	char c[2][2] = { 'a', 'b', 'c', 'd'};

	printf("%c %c %c %c\n",c[0][0],c[0][1],c[1][0],c[1][1]);
	printf("%c %c %c %c\n",**c,*(*c+1),**(c+1),*(*(c+1)+1));
}