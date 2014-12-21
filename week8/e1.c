#include <stdio.h>

void double_space(FILE *infile, FILE *outfile){
	char c;
	while((c = fscanf(infile, "%c",&c)) != EOF){
		fprintf(outfile,"%c",c);
		if(c == '\n')
			fprintf(outfile, '\n');
	}
}

int main(int argc, char* argv[]){
	FILE *infile, *outfile;

	if(argc != 3)
		return 0;
	infile = fopen(argv[1] , "r");
	outfile = fopen(argv[2], "w");
	if(infile == NULL){
		return 0;
	}
	double_space(infile,outfile);
	fclose(infile);
	fclose(outfile);
	return 0;
}