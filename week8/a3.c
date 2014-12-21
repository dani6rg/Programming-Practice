#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swapav(double *a, double *b){
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int **dpa = NULL; int size = 4; int pointnum = 0; int curr = 0;
	int *arrsize; double *average;
	int i, j, k; int* temp;
	char input[10]; int num;
	char numbers[5000]; char tem[50]; int tempcount = 0; int numberscount;

	dpa = (int**)malloc(sizeof(int*)*size);
	arrsize = (int*)malloc(sizeof(int));
	average = (double*)malloc(sizeof(double));
	while (1){
		scanf("%s", input);
		arrsize[curr] = 0;
		average[curr] = 0;
		tempcount = 0;
		numberscount = 0;
		if (strcmp(input, "insert") == 0){
			dpa[curr] = (int*)malloc(sizeof(int) * (arrsize[curr] + 1));
			arrsize = (int*)realloc(arrsize, sizeof(int)*(curr + 2));
			average = (double*)realloc(average, sizeof(double)*(curr + 2));
			gets(numbers);
			for (numberscount = 1; (numbers[numberscount - 1] != '\0'); numberscount++){
				if (numbers[numberscount] == ' '){
					tem[tempcount] = '\0';
					num = atoi(tem);
					tempcount = 0;
					dpa[curr] = (int*)realloc(dpa[curr], sizeof(int) * (arrsize[curr] + 1));
					dpa[curr][arrsize[curr]++] = num;
					average[curr] = (average[curr] * (arrsize[curr] - 1) + num) / arrsize[curr];
				}
				else{
					tem[tempcount++] = numbers[numberscount];
				}
			}
			tem[tempcount] = '\0';
			num = atoi(tem);
			tempcount = 0;
			dpa[curr] = (int*)realloc(dpa[curr], sizeof(int) * (arrsize[curr] + 1));
			dpa[curr][arrsize[curr]++] = num;
			average[curr] = (average[curr] * (arrsize[curr] - 1) + num) / arrsize[curr];
			curr++;
			if (curr >= size && size >= 4){
				size *= 2;
				dpa = realloc(dpa, sizeof(int*)*size);
			}
		}
		if (strcmp(input, "delete") == 0){
			scanf("%d", &num);
			for (j = num - 1; j < curr - 1; j++){
				dpa[j] = dpa[j + 1];
				arrsize[j] = arrsize[j + 1];
				average[j] = average[j + 1];
			}
			curr -= 1;
			if (curr < size / 4 && size>4){
				size /= 2;
				dpa = realloc(dpa, sizeof(int*)*size);
			}
		}
		if (strcmp(input, "size") == 0){
			printf("%d\n", size);
		}
		if (strcmp(input, "print") == 0){
			scanf("%d", &num);
			if (num <= curr && num>0){
				for (i = 0; i < arrsize[num - 1]; i++){
					printf("%d ", dpa[num - 1][i]);
				}
				printf("\n");
			}
		}
		if (strcmp(input, "printdpa") == 0){
			for (i = 0; i < curr; i++){
				for (j = 0; j < arrsize[i]; j++){
					printf("%d ", dpa[i][j]);
				}
				printf("\n");
			}
		}
		if (strcmp(input, "sort") == 0){
			scanf("%d", &num);
			for (i = 0; i < arrsize[num - 1]; i++){
				for (j = 0; j < arrsize[num - 1] - i - 1; j++){
					if (dpa[num - 1][j] > dpa[num - 1][j + 1]){
						swap(&dpa[num - 1][j], &dpa[num - 1][j + 1]);
					}
				}
			}
		}
		if (strcmp(input, "sortdpa") == 0){
			for (i = 0; i < curr; i++){
				for (j = 0; j<curr - i - 1; j++){
					if (average[j]>average[j + 1]){
						swap(&(dpa[j]), &(dpa[j + 1]));
						swap(&arrsize[j], &arrsize[j + 1]);
						swapav(&average[j], &average[j + 1]);
					}
				}
			}
		}
		if (strcmp(input, "sortall") == 0){
			for (i = 0; i < curr; i++){
				for (j = 0; j<curr - i - 1; j++){
					if (average[j]>average[j + 1]){
						swap(&(dpa[j]), &(dpa[j + 1]));
						swap(&arrsize[j], &arrsize[j + 1]);
						swapav(&average[j], &average[j + 1]);
					}
				}
			}
			for (k = 0; k < curr; k++){
				for (i = 0; i < arrsize[k]; i++){
					for (j = 0; j < arrsize[k] - i - 1; j++){
						if (dpa[k][j] > dpa[k][j + 1]){
							swap(&dpa[k][j], &dpa[k][j + 1]);

						}
					}
				}
			}

		}
		if (strcmp(input, "exit") == 0){
			break;
		}

	}
	return 0;
}