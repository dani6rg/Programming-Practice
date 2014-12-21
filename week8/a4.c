#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node{
	struct _Node* next;
	struct _Node* prev;
	int value;
} Node;

int inlist(Node *start, int num){
	Node *cu;
	cu = start->next;
	while (cu != start){
		if (num == cu->value){
			return 0;
		}
		cu = cu->next;
	}
	return 1;
}

int main(){
	char input[50]; char token[10]; int num; int todel; char dir;
	Node *head, *add, *del, *read, *temp, *sort, *rev;
	head = (Node*)malloc(sizeof(Node));
	head->next = head; head->prev = head;
	temp = (Node*)malloc(sizeof(Node));
	rev = (Node*)malloc(sizeof(Node));
	while (1){
		gets(input);
		sscanf(input, "%s", token);
		if (strcmp(token, "exit") == 0){
			break;
		}
		if (strcmp(token, "add") == 0){
			sscanf(input, "add %d", &num);
			if (inlist(head, num)){
				add = (Node*)malloc(sizeof(Node));
				if (head->next == head){
					head->next = add;
					head->prev = add;
					add->next = head;
					add->prev = head;
					add->value = num;
				}
				else{
					add->value = num;
					head->prev->next = add;
					add->prev = head->prev;
					head->prev = add;
					add->next = head;
				}
			}
		}
		if (strcmp(token, "delete") == 0){
			sscanf(input, "delete %d", &num);
			todel = 0;
			del = head->next;
			while (del != head){
				if (del->value == num){
					if (head->prev == head->next){
						head->next = head;
						head->prev = head;
					}
					else{
						del->prev->next = del->next;
						del->next->prev = del->prev;
					}
					free(del);
					break;
				}
				del = del->next;
			}
		}
		if (strcmp(token, "print") == 0){
			read = head->next;
			if (head != head->next){
				while (read != head){
					printf("%d ", read->value);
					read = read->next;
				}
				printf("\n");
			}
		}
		if (strcmp(token, "rotate") == 0){
			sscanf(input, "rotate %c %d",&dir, &num);
			while (num > 0){
				if (dir == 'r'){
					rev = head->prev;
					temp = head;
					rev->prev->next = temp;
					temp->next->prev = rev;
					rev->next = temp->next;
					temp->next = rev;
					temp->prev = rev->prev;
					rev->prev = temp;
				}
				if (dir == 'l'){
					rev = head;
					temp = head->next;
					rev->prev->next = temp;
					temp->next->prev = rev;
					rev->next = temp->next;
					temp->next = rev;
					temp->prev = rev->prev;
					rev->prev = temp;
				}
				num--;
			}

		}
		if (strcmp(token, "reverse") == 0){
			read = head;
			do{
				temp = read->prev;
				read->prev = read->next;
				read->next = temp;
				read = read->prev;
			} while (read != head);
		}
		if (strcmp(token, "sort") == 0){
			read = head->next;
			temp = head->prev;
			while (temp != read){
				sort = read;
				while (sort != temp){
					if (sort->value > sort->next->value){
						num = sort->value;
						sort->value = sort->next->value;
						sort->next->value = num;
					}
					sort = sort->next;
				}
				temp = temp->prev;
			}
		}
	}
	return 0;
}