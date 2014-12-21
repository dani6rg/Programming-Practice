#include <stdio.h>
#include <stdlib.h>

int main(){
	char input[50];
	int* da; int i, j,loc=0,size=4,num,check;
	da = malloc(sizeof(int) * size);
	while (1){
		check = 0;
		gets(input);
		if (input[0] == 'i'){
			//insert
			sscanf(input, "insert %d", &num);
			for (i = 0; i < loc; i++){
				if (da[i] == num){
					check = 1;
					break;
				}
			}
			if (check == 0){
				if (loc == size){
					size *= 2;
					da = realloc(da, sizeof(int) * size);
				}
				da[loc] = num;
				loc++;
			}
		}
		if (input[0] == 'd'){
			//delete
			sscanf(input, "delete %d", &num);
			for (i = 0; i < loc; i++){
				if (da[i] == num){
					for (j = i; j < loc; j++){
						da[j] = da[j + 1];
					}
					loc--;
					if (loc < size / 4 && size>4){
						size /= 2;
						da = realloc(da, sizeof(int)*size);
					}
					break;
				}
			}
		}
		if (input[0] == 'p'){
			if (loc != 0){
				for (i = 0; i < loc-1; i++){
					printf("%d ", da[i]);
				}
				printf("%d\n",da[loc-1]);
			}
		}
		if (input[0] == 's'){
			printf("%d\n", size);
		}
		if (input[0] == 'e'){
			break;
		}
		//array size control
	}

	return 0;
}