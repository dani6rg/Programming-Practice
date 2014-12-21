#include <stdio.h>


int sizecompare(int x[], int y[]){
	int i;
	for (i = 0; i < 120; i++){
		if (x[i] < y[i]){
			return -1;
		}
		else if (x[i] > y[i]){
			return 1;
		}
	}
	return 1;
}

int main(){

	char input[501] = { 0 }, rawin[501] = { 0 };
	char a[120] = { 0 }, b[120] = { 0 }, c[3] = { 0 }, sign;
	int x[120] = { 0 }; int y[120] = { 0 }; int result[250] = {0};
	int p = 0, h = 0, i = 0, j = 0, k = 0, chnum = 0, pn = 0, buf = 0, ansize = 0, ansign = 1, swap;;
	gets(rawin);

	while (rawin[i] != 0){
		if (rawin[i] != ' '){
			input[p] = rawin[i];
			p++;
		}
		i++;
	}

	i = 0;
	while (input[i] != 0){
		if (input[i] >= '0' && input[i] <= '9'){
			switch (chnum){
			case 0:
				a[j] = input[i];
				j++; i++;
				break;
			case 1:
				b[k] = input[i];
				k++; i++;
				break;
			}
		}
		else if ((input[i] == '+') || (input[i] == '-') || (input[i] == '*')){
			if (i == 0){
				c[0] = input[i];
				i++;
			}
			else if (input[i - 1] >= '0' && input[i - 1] <= '9'){
				c[1] = input[i];
				chnum++; i++;
			}
			else if (((input[i - 1] == '+') || (input[i - 1] == '-') || (input[i - 1] == '*')) && (input[i + 1] >= '0' && input[i + 1] <= '9')){
				c[2] = input[i];
				i++;
			}
		}
	}
	if (c[0] == 0){
		c[0] = '+';
	}
	if (c[2] == 0){
		c[2] = '+';
	}
	for (i = 0; i < j; i++){
		x[119 - i] = a[j - 1 - i] - 48;
	}
	for (i = 0; i < k; i++){
		y[119 - i] = b[k - 1 - i] - 48;
	}
	for (i = 0; i < 3; i++){
		if (c[i] == '-'){
			pn++;
		}
	}
	// parsing complete
	// j is len of a, k is len of b
	// c indicates the signs and operators


	if (c[1] == '*'){ //multiply
		if (pn == 1){
			ansign = -1;
		}
		else if (pn == -1){
			ansign = 1;
		}
		for (i = 0; i < j; i++){
			for (h = 0; h < k; h++){
				buf = x[119 - i] * y[119 - h];
				result[i + h] += buf % 10;
				if (result[i + h] >= 10){
					result[i + h + 1] += result[i + h] / 10;
					result[i + h] %= 10;
				}
				result[i + h + 1] += buf / 10;
				if (result[i + h + 1] >= 10){
					result[i + h + 2] += result[i + h + 1] / 10;
					result[i + h + 1] %= 10;
				}
			}
		}
	}
	else if ((pn % 2 == 0)){ //add
		for (i = 0; i < 120; i++){
			result[i] += x[119 - i] + y[119 - i];
			if (result[i] >= 10){
				result[i + 1] += result[i] / 10;
				result[i] %= 10;
			}
		}
		if (c[0] == '-'){
			ansign = -1;
		}
		else{
			ansign = 1;
		}
	}
	else if ((pn % 2 == 1)){ //subtract
		if (c[0] == '-'){
			ansign = -1 * sizecompare(x,y);
		}
		else{
			ansign = 1 * sizecompare(x, y);
		}
		if (sizecompare(x, y) == -1){
			for (i = 0; i < 120; i++){
				swap = x[i];
				x[i] = y[i];
				y[i] = swap;
			}
		}
		for (i = 0; i < 120; i++){
			result[i] += x[119 - i] - y[119 - i];
			if (result[i] < 0){
				result[i + 1]--;
				result[i] += 10;
			}
		}
	}

	for (i = 249; i > 0; i--){
		if (result[i] != 0){
			ansize = i;
			break;
		}
	}
	if (ansign == 1){
		sign = '+';
	}
	else{
		sign = '-';
	}

	if (ansize == 0 && result[0] == 0){
		printf("0");
	}
	else{
		if (sign == '-'){
			printf("%c", sign);
		}
		for (i = 0; i <= ansize; i++){
			printf("%d", result[ansize - i]);
		}
	}
	return 0;
}