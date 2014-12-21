#include <stdio.h>

int main(){
	int a=10,b=5,c=3;
	printf("%3d%3d%3d\n",a,b,c);
	{
		int b=7;
		float c=1.0;

		printf("%3d%3d%5.1f\n",a,b,c);
		a=b;
		{
			int c;
			c=b;
			printf("%3d%3d%3d\n",a,b,c);
		}
		printf("%3d%3d%5.1f\n",a,b,c);
		}
	printf("%3d%3d%3d\n",a,b,c);
	return 0;
}