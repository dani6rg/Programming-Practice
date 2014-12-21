#include <stdio.h>

int main(){

	int stack[1000],  cur = 0, in, out,i;
	char func[50];

	while (1){
		char func[50] = {0};
		gets(func);
		if (func[1] == 'x'){
			break;
		}
		else if (func[1] == 'u'){
			sscanf(func, "push %d", &in);
			stack[cur++] = in;
		}
		else if (func[0] == 't'){
			printf("%d\n", stack[cur - 1]);
		}
		else if (func[4] == 'y'){
			if (cur == 0){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
		else if (func[2] == 'p'){
			printf("%d\n", stack[--cur]);
		}
		else if (func[4] == 't'){
			for (i = 0; i < cur; i++){
				printf("%d ", stack[i]);
			}
			printf("\n");
		}
	}

	return 0;

}