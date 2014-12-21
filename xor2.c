#include <stdio.h>
short grid[502][502];
short point[501][501];
typedef struct _rect{
	int x1;
	int x2;
	int y1;
	int y2;
} rect;
int n;
int q,p;
int k;
int area;
int iswhole(){
	int i,j;
	for(i=q;i<=n;i++){
		for(j=0;j<=n;j++){
			if(point[i][j] == 1){
				return 0;
			}
		}
	}
	return 1;
}

int flip(rect a){
	point[a.y1-1][a.x1-1] ^= 1;
	point[a.y1-1][a.x2] ^= 1;
	point[a.y2][a.x1-1] ^= 1;
	point[a.y2][a.x2] ^= 1;
	area += (a.y2-a.y1+1)*(a.x2-a.x1+1);
	return 0;
}

int ticks(int n){
	if(n<=300){
		return 2*n;
	}
	if(n>=450){
		return 4;
	}
}

rect find(){
	int i,j; int check=0; 
	rect ans; int tick=0;
	int xodd[501];
	int yodd[501];

	for(i=q;i<=n;i++){
		for((check==0)?(j=p):(j=0);j<=n;j++){
			check=1;
			if(point[i][j]==1){
				ans.x1 = j+1;
				ans.y1 = i+1;
			
				q = i;
				p = j;

				i = ans.y1 ;
				j = ans.x1-1;
				while(point[i][j] == 0){
					i++;
				}
				ans.y2 = i;

				i = ans.y1-1;
				j = ans.x1;
				while(point[i][j] == 0){
					j++;
				}
				ans.x2 = j;
				if(point[ans.y2][ans.x2] == 1){
					return ans;
				}
				while(1){
						if(point[ans.y2][ans.x2] == 1){
							return ans;
						}

						if(ans.y2>=n || ans.x2>=n){
							return ans;
						}
						if(tick >= ticks(n)){
							return ans;
						}
						if((tick%2 == 0) ){
							i = ans.y2+1;
							j = ans.x1-1;
							while(point[i][j] == 0){
								i++;
								if(i>=n){
									return ans;
								}
							}
							ans.y2 = i;
						}else{
							i = ans.y1-1;
							j = ans.x2+1;
							while(point[i][j]==0){
								j++;
								if(j>=n){
									return ans;
								}
							}
							ans.x2=j;
						}
						tick++;
					}
				}
			}
		}
	}



int main(){

	rect output[50000];
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			scanf("%hd",&grid[i][j]);
		}
	}
	for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			point[i][j] = ((grid[i][j] + grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1]) %2);
		}
	}
	while(iswhole() == 0){
		output[k] = find();
		flip(output[k]);
		k++;
		
	}
	printf("%d\n",k);
	for(i=0;i<k;i++){
		printf("%d %d %d %d\n",output[i].y1,output[i].x1,output[i].y2,output[i].x2);
	}
	return 0;
}
