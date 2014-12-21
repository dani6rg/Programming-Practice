#include <stdio.h>
#include <stdlib.h>

typedef struct node node_t;
struct node{
	int value;
	struct node *next;
};


int main(){
	char input[100];
	int count = 0, num;
	node_t*end, *curr, *imsi, *del, *start , *past;
	start = (node_t*)malloc(sizeof(node_t));
	imsi = (node_t*)malloc(sizeof(node_t));
	del = (node_t*)malloc(sizeof(node_t));
	start->next = NULL;
	curr = start;
	while (1){
		count = 0;
		gets(input);
		if (input[0] == 'a'){
			sscanf(input, "add %d", &num);
			curr = start;
			if(start->next != NULL){
				imsi = start->next;
				while (imsi != NULL){
					if(imsi->value == num){
						count = 1;
					}
					imsi = imsi->next;
					curr = curr->next;
				}
			}
			if(count == 0){
			end = (node_t*)malloc(sizeof(node_t));
			end->value = num;
			end->next = NULL;
			curr->next = end;
			curr = curr->next;
			}
		}
		if (input[0] == 'd'){
			sscanf(input, "delete %d", &num);
			imsi = start;
			while(imsi->next != NULL){
				if(imsi->next->value == num){
					del = imsi->next;
					imsi->next = imsi->next->next;
					free(del);
					break;
				}
				imsi = imsi->next;
			}
		}
		if (input[0] == 'p'){
			if (start->next != NULL){
				imsi = start->next;
				while (imsi != NULL){
					printf("%d ", imsi->value);
					imsi = imsi->next;
				}
				printf("\n");
			}
		}
		if (input[0] == 'e'){
			break;
		}
	}		return 0;
}