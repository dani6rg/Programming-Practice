#include <stdio.h>

int main(int argc, char* argv[]){

	FILE* input = fopen(input_ex2.txt, "r");
	FILE* output = fopen(output_ex2.txt,"w");
	char c;
	fseek(input,-1,SEEK_END);
	while((c=fgetc(input)) != EOF){
		fputc(c,output);
		fseek(input,-2);
	}
	fseek(input,0,SEEK_SET);
	fputc(fgetc(input),output);
	fclose(input);
	fclose(output);
	return 0;
}