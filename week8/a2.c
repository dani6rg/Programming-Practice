#include <stdio.h>
#include <string.h>
int n, m; int found;
char grid[51][51];
char input[51];
struct dir{
	int x;
	int y;
};
struct dir di[8];
int abs(int x){
	if (x > 0) return x;
	return -x;
}
int maxlen(int a, int b, struct dir v){
	int i; int j;
	for (j = 1;; j++){
		a += v.x;
		b += v.y;
		if ((a <= 0 || b <= 0 || a > n || b > m)){
			return j;
		}
	}
	return 0;
}
int canfind(int a, int b, int stlen){
	int mlen[8]; char buffer[51];
	int i, j;
	for (i = 0; i < 8; i++){
		mlen[i] = maxlen(a, b, di[i]);
		if (mlen[i] >= stlen){
			for (j = 0; j < stlen; j++){
				buffer[j] = grid[a + (di[i].x)*j][b + (di[i].y)*j];
				buffer[stlen] = 0;
			}
			if (strcmp(buffer, input) == 0){
				return 1;
			}
		}
	}
	return 0;
}
char decap(char a){
	if (a >= 'A' && a <= 'Z'){
		return a + 'a' - 'A';
	}
	else if (a >= 'a' && a <= 'z'){
		return a;
	}
	return 0;
}
int main(){
	int i, j; int len;
	for (i = 0; i < 8; i++){
		di[i].x = (i % 4 != 0) * (1 - 2 * (i / 4));
		di[i].y = (i % 4 != 2) * (1 - 2 * (abs(i - 4) < 2));
	}
	scanf("%d %d\n", &n, &m);
	for (i = 0; i < m + 2; i++){
		grid[0][i] = 0;
		grid[n + 1][i] = 0;
	}
	for (i = 1; i <= n; i++){
		scanf("%s\n", grid[i]);
		for (j = m; j > 0; j--){
			grid[i][j] = decap(grid[i][j - 1]);
		}
		grid[i][0] = 0; grid[i][m + 1] = 0;
	}
	while (1){
		found = 0;
		gets(input);
		if (!strcmp(input, "exit")){
			break;
		}
		len = strlen(input);
		for (i = 0; i < len; i++){
			input[i] = decap(input[i]);
		}
		for (i = 1; i <= n; i++){
			for (j = 1; j <= m; j++){
				found = canfind(i, j, len);
				if (found == 1) {
					printf("%d,%d\n", i, j);
					break;
				}
			}
			if (found == 1){
				break;
			}
		}
		if (found == 0){
			printf("-1\n");
		}
	}
	return 0;
}