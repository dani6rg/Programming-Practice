#include <stdio.h>
#define big -1
int m, n, a, b, c, d;
char maze[32][32];
int state[32][32]; // memoization 0 no, above 0 yes, -1 wall
int start[2], end[2];

int min(int p, int q, int r, int s){
	int k = 100000;
	if (k > p && p > 0){ k = p; }
	if (k > q && q > 0){ k = q; }
	if (k > r && r > 0) {
		k = r;
	}if (k > s && s > 0){
		k = s;
	}
	return k;
}

int main(){
	int i, j, count = 1, check;
	scanf("%d %d\n", &m, &n);
	for (i = 1; i <= n; i++){
		for (j = 1; j <= m; j++){
			scanf("%c", &maze[i][j]);
			if (maze[i][j] == '1'){
				state[i][j] = big;
			}
			scanf("\n");
		}
	}
	for (i = 0; i < 32; i++){
		maze[0][i] = '1';
		maze[i][0] = '1';
		maze[i][n + 1] = '1';
		maze[m + 1][i] = '1';
		state[0][i] = big;
		state[i][0] = big;
		state[i][m + 1] = big;
		state[n + 1][i] = big;
	}
	scanf("%d %d %d %d", &a, &b, &c, &d);
	state[a][b] = 1; 
	for (count = 2;; count++){
		check = 1;
		for (i = 1; i <= n; i++){
			for (j = 1; j <= m; j++){
				if (((state[i][j + 1] == count - 1) || (state[i][j - 1] == count - 1) || (state[i + 1][j] == count - 1) || (state[i - 1][j] == count - 1)) && state[i][j] == 0){
					state[i][j] = min(state[i][j + 1], state[i][j - 1], state[i - 1][j], state[i + 1][j]) + 1;
				}
				check *= state[i][j];
			}
		}
		if (state[c][d] != 0){
			break;
		}
	}
	printf("%d", state[c][d]);
	return 0;
}