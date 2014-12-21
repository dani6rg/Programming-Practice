#include <stdio.h>

int main(void){
	int b[3][2] = { {0,1}, {2,3}, {4,5} };
	int (*bpp)[2] = b;
	int *bp = b[0];
	int i,j;

	printf("b  : %p\t*b  : %p\t**b  : %d\n", b,*b,**b);
	printf("bpp: %p\t*bpp: %p\t**bpp: %d\n", bpp,*bpp,**bpp);

	for (i=0;i<3;++i){
		bp = b[i];

		printf("\t*b[%d]: %d\tb[%d]: %p\tbpp+%d: %p\t*(bpp+%d): %p\n",i,*b[i],i,bpp+i,i,*(bpp+i));

		for(j=0;j<2;++j){
			printf("\t\t&b[%d][%d]: %p\t*(bpp+%d)+%d: %p\t*(*(bpp+%d))[%d]: %d\n",i,j,&b[i][j],i,j,*(bpp+i)+j,i,j,*(*(bpp+i)+j),i,j,(*(bpp+i))[j]);
		}

	}

}