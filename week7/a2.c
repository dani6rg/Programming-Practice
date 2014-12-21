#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int arraycmp(int a[], int b[], int len){
	int k;
	for (k = 0; k <= len; k++){
		if (a[k] != b[k]) return 1;
	}
	return 0;
}

void unspace(char a[]){
	int i = 0, j = 0, k = 0; int space = 0;
	char b[100000];
	while (a[i] != 0){
		if (a[i] != ' '){
			b[j] = a[i];
			j++;
		}
		i++;
	}
	for (i = 0, k = 0; i < j; i++, k++){
		if (i>0 && b[i - 1] == ','){
			a[k++] = ' ';
		}
		a[k] = b[i];
	}
	a[k] = 0;
}
void flush(char x[], int len){
	int i;
	for (i = 0; i < len; i++){
		x[i] = 0;
	}
}
int main(){
	char arr[100000];
	gets(arr);
	unspace(arr);
	while (1){
		char find[1000];
		char buffer[10];
		char output[100000]; int outputcount = 0;
		int i, j;
		int inputnest, currnest;
		int isnested = 0;
		int inputnum[100], currnum[100];
		inputnest = -1; currnest = -1;
		flush(find, 1000);
		flush(buffer, 10);
		flush(output, 100000);
		for (i = 0; i < 100; i++){
			inputnum[i] = -1;
			currnum[i] = -1;
		}
		gets(find);
		if (strcmp(find, "exit") == 0){
			break;
		}
		else if (strcmp(find, "arr") == 0){
			printf("%s\n", arr);
		}
		else{
			/* 1. parse the input
			2. find the parsing place from arr*/
			for (i = 0;; i++){
				if (find[i] == 0){
					break;
				}
				if (find[i] == '['){
					j = 0;
					while (find[i + 1] != ']'){
						buffer[j] = find[++i];
						j++;
					}
					buffer[j] = 0;
					inputnum[++inputnest] = atoi(buffer);
				}
			}
			isnested = 0;
			for (i = 0;; i++){
				if (arr[i] == '['){
					currnest++; currnum[currnest] = 0;
				}
				if (arr[i] == ']') {
					currnum[currnest] = -1;
					currnest--;
				}
				if (arr[i] == ','){
					currnum[currnest]++;
				}
				if (arraycmp(inputnum, currnum, inputnest) == 0){
					while (1){
						i++;
						if (arr[i] == '['){
							isnested += 1;
						}
						if (arr[i] == ']'){
							isnested -= 1;
						}
						if (isnested <= 0 && (arr[i] == ',' || arr[i] == ']')){
							if (arr[i] == ']' && ((arr[i + 1] == ',' )||( arr[i+1] == 0 )||( arr[i+1] = ']') )&&isnested == 0){
								output[outputcount++] = ']';
							}
							break;
						}
						else{
							output[outputcount++] = arr[i];
						}
					}
					output[outputcount] = 0;
					unspace(output);
					printf("%s\n", output);
					break;
				}
			}
		}
	}
	return 0;
}