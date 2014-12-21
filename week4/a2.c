#include <stdio.h>
int main(){
	int n, i, j, k, l;
	char a[4][5];
	int loc[15000] = { 0 };
	char next[15000][2] = { 0 };
	scanf("%d\n", &n);
	for (i = 0; i < 4; i++){
		scanf("%s\n", a[i]);
	}
	if (n != 0){
		scanf("----\n");
		for (i = 0; i < n - 1; i++){
			scanf("%c %d %c\n", &next[i][0], &loc[i], &next[i][1]);
		}
		scanf("%c %d %c", &next[n - 1][0], &loc[n - 1], &next[n - 1][1]);
	}
	else{
		scanf("----");
	}
	/*�Է� �Ϸ�*/
	/*�׸��� �̴ϼ� ����*/
	for (j = 0; j < 4; j++){
		for (k = 0; k < 4; k++){
			printf("%c", a[j][k]);
		}
		printf("\n");
	}
	printf("----\n");
	for (i = 0; i < n; i++){
		/*�̵� �۾� ����*/
		switch (next[i][0]){
		case 'N':
			for (k = 0; k < 4; k++){
				/*���� ����*/
				for (j = 1; j < 4; j++){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j - 1][k] == '.'){
						a[j - 1][k] = a[j][k];
						a[j][k] = '.';
						j = 1;
					}
				}
				/*��ġ��*/
				for (j = 0; j < 3; j++){
					if (a[j][k] == a[j + 1][k] && a[j][k] != '.'){
						a[j][k] += 1;
						a[j + 1][k] = '.';
					}
				}
				/*���� ����*/
				for (j = 1; j < 4; j++){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j - 1][k] == '.'){
						a[j - 1][k] = a[j][k];
						a[j][k] = '.';
						j = 1;
					}
				}
			}
			break;
		case 'S':
			for (k = 0; k < 4; k++){
				/*���� ����*/
				for (j = 2; j >= 0; j--){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j + 1][k] == '.'){
						a[j + 1][k] = a[j][k];
						a[j][k] = '.';
						j = 2;
					}

				}
				/*��ġ��*/
				for (j = 3; j > 0; j--){
					if (a[j][k] == a[j - 1][k] && a[j][k] != '.'){
						a[j][k] += 1;
						a[j - 1][k] = '.';
					}
				}
				/*���� ����*/
				for (j = 2; j >= 0; j--){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j + 1][k] == '.'){
						a[j + 1][k] = a[j][k];
						a[j][k] = '.';
						j = 2;
					}
				}
			}
			break;
		case 'W':
			for (j = 0; j < 4; j++){
				/*���� ����*/
				for (k = 1; k < 4; k++){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j][k - 1] == '.'){
						a[j][k - 1] = a[j][k];
						a[j][k] = '.';
						k = 1;
					}

				}
				/*��ġ��*/
				for (k = 0; k < 3; k++){
					if (a[j][k] == a[j][k + 1] && a[j][k] != '.'){
						a[j][k] += 1;
						a[j][k + 1] = '.';
					}
				}
				/*���� ����*/
				for (k = 1; k < 4; k++){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j][k - 1] == '.'){
						a[j][k - 1] = a[j][k];
						a[j][k] = '.';
						k = 1;
					}

				}
			}
			break;

		case 'E':
			for (j = 0; j < 4; j++){
				/*���� ����*/
				for (k = 2; k >= 0; k--){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j][k + 1] == '.'){
						a[j][k + 1] = a[j][k];
						a[j][k] = '.';
						k = 2;
					}

				}
				/*��ġ��*/
				for (k = 3; k > 0; k--){
					if (a[j][k] == a[j][k - 1] && a[j][k] != '.'){
						a[j][k] += 1;
						a[j][k - 1] = '.';
					}
				}
				/*���� ����*/
				for (k = 2; k >= 0; k--){
					if (a[j][k] == '.'){
						continue;
					}
					else if (a[j][k + 1] == '.'){
						a[j][k + 1] = a[j][k];
						a[j][k] = '.';
						k = 2;
					}

				}
			}

			break;
		}
		/*���ο� Ÿ��*/
		j = loc[i] / 4; k = loc[i] % 4;
		if (a[j][k] == '.'){
			a[j][k] = next[i][1];
		}
		/*�̵� �� �׸��� ��Ȳ ���*/
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				printf("%c", a[j][k]);
			}
			printf("\n");
		}
		printf("----\n");
	}
	return 0;
}