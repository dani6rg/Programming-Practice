#include <stdio.h>
char parse[100];
char input[1000];
int num = 0, len[100] = { 0 }, order[100];
int i, j;
int inParse(char c){
	int k;
	for (k = 0; parse[k] != 0; k++){
		if (parse[k] == c){
			return 1;
		}
	}
	return 0;
}
int stcmp(char a[], char b[]){
	int l;
	char c[500], d[500];
	for (l = 0; l < 500; l++){
		c[l] = a[l];
		d[l] = b[l];
	}
	for (l = 0; l < 500; l++){
		if (c[l] >= 'A' && c[l] <= 'Z'){
			c[l] = c[l] + 'a' - 'A';
		}
		if (d[l] >= 'A' && d[l] <= 'Z'){
			d[l] = d[l] + 'a' - 'A';
		}
	}
	for (l = 0; l < 500; l++){
		if (c[l]>d[l]){
			return 2;
		}
		else if (c[l] < d[l]){
			return 1;
		}
		else{
			continue;
		}
	}
	return 1;
}
int main(){
	char out[100][1000];
	gets(parse);
	gets(input);
	for (i = 0; input[i] != 0; i++){
		if (inParse(input[i]) == 0){
			out[num][len[num]++] = input[i];
			if (inParse(input[i + 1]) == 1){
				num++;
			}
		}
	}
	if (inParse(input[i - 1]) == 0){
		num++;
	}
	for (i = 0; i < num; i++){
		order[i] = i;
	}
	for (i = 0; i < num; i++){
		for (j = 0; j < num - 1- i; j++){
			if (stcmp(out[order[j]], out[order[j + 1]]) == 2){
				order[j] = order[j] + order[j + 1];
				order[j+1] = order[j] - order[j + 1];
				order[j] = order[j] - order[j + 1];
			}
		}
	}
	for (i = 0; i < num; i++){
		for (j = 0; j < len[order[i]]; j++){
			printf("%c", out[order[i]][j]);
		}
		if (i != num-1){
			printf(" ");
		}
	}
	return 0;
}