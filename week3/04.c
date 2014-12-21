#include <stdio.h>

int main(){
    int a,i;
	scanf("%d",&a);
	for (i=2;i<1000000000;i++){
		if (a==1){
            break;
            }
        if (a%i == 0){
			printf("%d\n",i);
			a = a/i;
			i=1;
		}
	}return 0;
}
