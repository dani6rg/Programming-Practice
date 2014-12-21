#include <stdio.h>

int main(){
    int n,m;
	int a[101][101];
	int i,j;
	int count=1, dir=0;
	int len;
    
	scanf("%d %d",&m,&n);


	for(i=0;i<101;i++){
		for(j=0;j<101;j++){
			a[i][j] = -1;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			a[i][j] = 0;
		}
	}

	i=n;j=1;

	while(count<=n*m){
		a[i][j] = count++;
		switch(dir){
			case 0:
			if(a[i-1][j]==0){
				i--;
			}
			else{
				dir +=1;
                j+=1;
			}
			break;
			
			case 1:
			if(a[i][j+1]==0){
				j++;
			}
			else{
				dir +=1;
                i+=1;
			}
			break;

			case 2:
			if(a[i+1][j]==0){
				i++;
			}
			else{
				dir +=1;
                j-=1;
			}
			break;

			case 3:
			if(a[i][j-1]==0){
				j--;
			}
			else{
				dir=0;
                i-=1;
			}
			break;
		}
	}

	i = n*m;
	len = 1;
	
	while(i !=0){
		i /= 10;
		len++;
	}
    
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			printf("%*d",len,a[i][j]);
		}
		printf("\n");
	}

	return 0;
}