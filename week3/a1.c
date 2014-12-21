#include <stdio.h>

long long int po(int a,int b){
    if (b==0 || a==0){
        return 1;
    }
    return a * po(a,b-1);
    }

int main(){
    int a,b,y,i,j;
    long long int x;
    scanf("%d %d",&a,&b);
    x = po(a,b);
    y=1;
    while(x>0){
        x = x/10,y+=1;
    }
    for(i=0;i<a;i++){
        for(j=0;j<=b;j++){
            if(j==0){
                if(i==0){
                    printf("%*s",y,"");
                }else{
                    printf("%*d",y,i+1);
                }
            }else if(i==0){
                printf("%*d",y,j);
            }else{
                printf("%*lld",y,po(i+1,j));
            }
        }
        if(i!=a-1){
            printf("\n");
        }
    }
    return 0;
}
