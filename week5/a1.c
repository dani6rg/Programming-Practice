#include <stdio.h>

int main(){

	char input[5001] ;
	int a[200]; int i=0, j=0;

	scanf("%s",input);
	while(input[i] != 0){
		if(input[i] == '('){
			a[j++] = i++;
		}
		else if(input[i] == ')'){
			i++; 
			printf("%d %d\n",a[j-1]+1,i);	
			j--;
		}
	}
	return 0;

}