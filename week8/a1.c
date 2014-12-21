#include <stdio.h>

int main(){
	int i=0,j,num=0, house[1000],sum=0, point;
	char c;
	while(1){
		scanf("%d%c",&house[num++],&c);
		if(c == '\n'){
			break;
		}
	}

	for(i=0;i<num;i++){
		for(j=0;j<num-i-1;j++){
			if(house[j] > house[j+1]){
				point = house[j];
				house[j] = house[j+1];
				house[j+1] = point;
			}
		}
	}
	point = house[(num-1)/2];
	for(i=0;i<num;i++){
		j = house[i] - point;
		sum += (j>0) ? j : -j ;
	}
	printf("%d",sum);
	return 0;
}