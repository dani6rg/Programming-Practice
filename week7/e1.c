#include <stdio.h>
#include <stdlib.h>
int main(){
	int *one = NULL;
	int size;
	int i;
	scanf("%d",&size);
	one = (int*) malloc(sizeof(int) * size);
	for(i=0;i<size;i++){
		*(one+i) = i;
		printf("%3d",one[i]);
	}
	printf("\n");
	free(one);

	return 0;
}