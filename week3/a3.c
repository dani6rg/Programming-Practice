#include <stdio.h>

int hanoi(int n, int a, int b){
    int c = 6-(a+b);
    if(n==1){printf("%d->%d\n",a,b);}
    else{hanoi(n-1,a,c);
	printf("%d->%d\n",a,b);
	hanoi(n-1,c,b);
	}
    return 0;
}


int main(){
	int n;
	scanf("%d",&n);
	hanoi(n,1,3);
	return 0;
}