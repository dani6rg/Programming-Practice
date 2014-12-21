#include <stdio.h>
#include <stdlib.h>
int main(){
	int **two = NULL;
	int row,col;
	int i,j;
	scanf("%d %d",&row, &col);
	two = (int**) malloc(sizeof(int*) * row);
	for(i=0;i<row;i++){
		two[i] = (int*) malloc (sizeof(int) * col);
		for(j=0;j<col;j++){
			two[i][j] = i+j;
			printf("%3d",*(*(two+i)+j));
		}
		printf("\n");
		free(two[i]);
	}
	free(two);

	return 0;
}