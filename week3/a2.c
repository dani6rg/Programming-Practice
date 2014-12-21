#include <stdio.h>

int max(int a,int b){
    if (a>b) return a;
    return b;
}
    

void DrawTri(int n,int m, char c){
    int i,j,x=n+m,y=(n+1)/2,z=(m+1)/2,k=max(y,z);
    for(i=0;i<k;i++){
        if(k==y){
            for(j=0;j<(n-1)/2 - i;j++){ 
                printf("%c",c);
                }
            for(j=0;j<2*i+1;j++){
                printf("*");
                }
            for(j=0;j<(n-1)/2 - i;j++){ 
                printf("%c",c);
                }
            if(i<k-z){
                for(j=0;j<m;j++){
                    printf("%c",c);
                }
            }else{
                for(j=0;j<(m-1)/2 - (i-(k-z));j++){ 
                    printf("%c",c);
                }
                for(j=0;j<2*(i-(k-z))+1;j++){
                    printf("*");
                }   
                for(j=0;j<(m-1)/2 - (i-(k-z));j++){ 
                    printf("%c",c);
                }
            }
        }
       else{
            if(i<k-y){
                for(j=0;j<n;j++){
                    printf("%c",c);
                }
            }else{
                for(j=0;j<(n-1)/2 - (i-(k-y));j++){ 
                    printf("%c",c);
                }
                for(j=0;j<2*(i-(k-y))+1;j++){
                    printf("*");
                }   
                for(j=0;j<(n-1)/2 - (i-(k-y));j++){ 
                    printf("%c",c);
                }
            }
            for(j=0;j<(m-1)/2 - i;j++){ 
                printf("%c",c);
                }
            for(j=0;j<2*i+1;j++){
                printf("*");
                }
            for(j=0;j<(m-1)/2 - i;j++){ 
                printf("%c",c);
                }
        }
        if(i!=k){
            printf("\n");
        }
    }
}

int main(){
    int n,m,flag;
    char c;
    while(1){
        scanf("%d",&flag);
        if(flag == 0){
            break;
        }
        
        scanf("%d %d %c",&n,&m,&c);
        DrawTri(n,m,c);
    }
    return 0;
}
