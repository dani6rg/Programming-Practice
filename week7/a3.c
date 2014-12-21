#include <stdio.h>
typedef struct operation{
	int num;
	char op;
	char norop; // num or op .. 0 or 1
} stack;
int isnum(char a){
	if (a >= '0' && a <= '9'){
		return 1;
	}
	return 0;
}
int isop(char a){
	if ((a == '+') || (a == '-') || (a == '/') || (a == '*')){
		return 1;
	}
	return 0;
}
int isunary(char a){
	if ((a == '+') || (a == '-')){
		return 1;
	}
	return 0;
}
int isparen(char a){
	if ((a == '(') || (a == ')')){
		return 1;
	}
	return 0;
}
int prec(char a){
	if (a == '+' || a == '-'){
		return 1;
	}
	if (a == '*' || a == '/'){
		return 2;
	}
	if (a == '('){
		return 0;
	}
	return 3;
}
int opercheck(char in, char oper){
	if (prec(in) <= prec(oper)){
		return 1;
	}
	return 0;
}
double cal(double a, double b, char op){
	if (op == '+') return a + b;
	if (op == '-') return a - b;
	if (op == '*') return a * b;
	if (op == '/') return a / b;
}
int main(){
	char input[10000];
	char oper[10000] = { 0 }; int opernum = 0;
	stack postfix[10000]; int postnum = 0;
	double calc[10000]; int calcnum = 0;
	char numbuffer[15] = { 0 }; int bufcount = 0; int num;
	double val1, val2, result;
	int i = 0;
	gets(input);
	for (i = 0;; i++){
		if (isnum(input[i])){
			bufcount = 0;
			while (isnum(input[i])){
				numbuffer[bufcount++] = input[i++];
			}
			i--;
			numbuffer[bufcount] = 0;
			sscanf(numbuffer, "%d", &num);
			postfix[postnum].norop = 0;
			postfix[postnum++].num = num;
		}
		else if (((i==0 || (isop(input[i-1])  ||input[i-1] == '(' )))&& isunary(input[i])){
				oper[opernum++] = ((input[i] == '+') ? 'p' : 'n');
		}
		else if (isop(input[i])){
			while ((opernum != 0) && (opercheck(input[i], oper[opernum-1]))){
				postfix[postnum].norop = 1;
				postfix[postnum++].op = oper[--opernum];

			}
			oper[opernum++] = input[i];
		}
		else if (input[i] == '('){
			oper[opernum++] = '(';
		}
		else if (input[i] == ')'){
			while (oper[opernum - 1] != '('){
				postfix[postnum].norop = 1;
				postfix[postnum++].op = oper[--opernum];
			}
			opernum--;
		}
		else if (input[i] == 0){
			while (opernum != 0){
				postfix[postnum].norop = 1;
				postfix[postnum++].op = oper[--opernum];
			}
			break;
		}
	}
	for (i = 0; i < postnum; i++){
		if (postfix[i].norop == 0){
			calc[calcnum++] = (double)postfix[i].num;
		}
		else if (postfix[i].op == 'n' || postfix[i].op == 'p'){
			calc[calcnum-1] *= ((postfix[i].op == 'p') ? 1 : -1);
		}
		else{
			val2 = calc[--calcnum];
			val1 = calc[--calcnum];
			result = cal(val1, val2, postfix[i].op);
			calc[calcnum++] = result;
		}
	}
	printf("%.4lf", calc[0]);
	return 0;
}