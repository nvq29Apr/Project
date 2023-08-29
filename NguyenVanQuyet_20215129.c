#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/* 
	NOTE
	Invalid order is all people in an order are kids or kid > people
	An order contain: code, amount of peoples, room number, hotel code, date order, amount of kids
	Created by Nguyen Van Quyet 20215129 - 03/03/2023
*/
void menu(){
	printf("\nBOOKING ORDER PROGRAM \n");
	printf("Select an option: \n");
	printf("1, Read data from .txt file\n");
	printf("2, Print all exist order\n");
	printf("3, Check amount of invalid order\n");
	printf("4, Search by code\n");
	printf("5, Modifie order\n");
	printf("6, Cancel order\n");
	printf("7, Save order list to .txt file\n");
	printf("0, Exit!\n");
}

//Linked list
struct node{
	char code[7];
	int people;
	int room;
	char hotel[4];
	char date[10];
	int kid;
	struct node *next;
};
typedef struct node node;
int countLL(node *head){
	int cnt = 0;
	while(head != NULL){
		cnt++;
		head = head->next;
	}
	return cnt;
}
node* makeNode(char *code, int people, int room, char *hotel, char *date, int kid){
    node *newNode = (node*)malloc(sizeof(node));
	
	strcpy(newNode->code, code);
	strcpy(newNode->hotel, hotel);
	strcpy(newNode->date, date);
	newNode->people = people;
	newNode->room = room;
	newNode->kid = kid;
    newNode->next = NULL;
    return newNode;
}

void insertLast(node **head, node **newNode){
	if(*head == NULL){
		*head = *newNode;
		return;
	}
	node *tmp = *head;
	while(tmp->next != NULL){
		tmp = tmp->next;
	}
	tmp->next = *newNode;
}
int loadFromFile(node **head){
	FILE *f = fopen("booking_orders.txt", "r");
	if (f == NULL) {
	    printf("File not found\n");
	    return 0;
    }
    int o;
	char line[50];
	fgets(line, 50, f);
	sscanf(line, "%d", &o);
	while(fgets(line, 50, f) != NULL){
		char code[7];
		int people;
		int room;
		char hotel[4];
		char date[10];
		int kid;
		sscanf(line, "%s %d %d %s %s %d", code, &people, &room, hotel, date, &kid);
		node *newNode = makeNode(code, people, room, hotel, date, kid);
		insertLast(head, &newNode);
	}
	fclose(f);
	printf("Doc thanh cong!\n");
	return o;
}
void print(node *head){
	if(head == NULL) return;
	while(head != NULL){
		printf("%s %d %d %s %s %d\n", head->code, head->people, head->room, head->hotel, head->date, head->kid);
		head = head->next;
	}
}
int invalid(node *head){
	if(head == NULL) return 0;
	int cnt = 0;
	while(head != NULL){
		if(head->people == head->kid){
			cnt++;
		}
		head = head->next;
	}
	return cnt;
}

//BST
struct node2{
	char code[7];
	int people;
	int room;
	char hotel[4];
	char date[10];
	int kid;
	struct node2 *left;
	struct node2 *right;
};
typedef struct node2 node2;
node2* makeNode2(char *code, int people, int room, char *hotel, char *date, int kid){
    node2 *newNode = malloc(sizeof(node2));
    
    strcpy(newNode->code, code);
	strcpy(newNode->hotel, hotel);
	strcpy(newNode->date, date);
	newNode->people = people;
	newNode->room = room;
	newNode->kid = kid;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

node2* insertNode2(node2 *root, char *code, int people, int room, char *hotel, char *date, int kid){
    if(root == NULL) return makeNode2(code, people, room, hotel, date, kid);
    
    int c = strcmp(root->code, code);
    if(c == 0){
    	//do nothing
    }
    else if(c < 0){
        root->right = insertNode2(root->right, code, people, room, hotel, date, kid);
    }
    else{
        root->left = insertNode2(root->left, code, people, room, hotel, date, kid);
    }
    return root;
}
node2* linkedListToBST(node *head){
    node2 *root = NULL;
    while(head != NULL){
    	root = insertNode2(root, head->code, head->people, head->room, head->hotel, head->date, head->people);
        head = head->next;
    }
    return root;
}
void inOrder(node2 *root){
	if(root != NULL){
		inOrder(root->left);
		printf("%s %d %d %s %s %d\n", root->code, root->people, root->room, root->hotel, root->date, root->kid);
		inOrder(root->right);
	}	
}
int searchNode(node2 *root, char *code) {
    if(root != NULL){
    	int found  = 0;
    	if(strcmp(root->code, code) == 0){
    		found  = 1;
    		printf("%s %d %d %s %s %d\n", root->code, root->people, root->room, root->hotel, root->date, root->kid);
		}
		else if(strcmp(root->code, code) < 0){
			searchNode(root->right, code);
		}
		else searchNode(root->left, code);
		return found;
	}
}
void update(node2 *root, char *code, int people, int kid, char *date){
	if(root != NULL){
		if(strcmp(root->code, code) == 0){
			root->people = people;
			root->kid = kid;
			strcpy(root->date, date);
		}
		else if(strcmp(root->code, code) < 0){
			update(root->right, code, people, kid, date);
		}
		else update(root->left, code, people, kid, date);
	}
}
void printOrderToFile(node2 *root){
	FILE *f = fopen("booking_output.txt", "a");
	if(root == NULL) return;
	printOrderToFile(root->left);
	fprintf(f, "%s %d %d %s %s %d\n", root->code, root->people, root->room, root->hotel, root->date, root->kid);
	printOrderToFile(root->right);
	fclose(f);
}
node2* findMin(node2 *root){
	while(root->left != NULL) root = root->left;
	return root;
}
node2* deleteNode2(node2 *root, char *code){
    // Cay rong
    if (root == NULL) return root;

    // Tim kiem node can xoa
    int cmp = strcmp(code, root->code);
    if (cmp < 0) {
        root->left = deleteNode2(root->left, code);
    } else if (cmp > 0) {
        root->right = deleteNode2(root->right, code);
    } else {
        // 0 con || 1 con
        if (root->left == NULL) {
            node2 *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node2 *temp = root->left;
            free(root);
            return temp;
        }

        // 2 con
        node2 *temp = findMin(root->right);
        strcpy(root->code, temp->code);
        strcpy(root->hotel, temp->hotel);
        strcpy(root->date, temp->date);
        root->people = temp->people;
        root->room = temp->room;
        root->kid = temp->kid;
        root->right = deleteNode2(root->right, temp->code);
    }
    return root;
}
int count(node2 *root){
	if(root != NULL){
		int cnt = 1;
		cnt += count(root->right);
		cnt += count(root->left);
		return cnt;
	}
}

int main() {
	node *head = NULL;
	node2 *root;
	int input, res;
	FILE *f_clear;
	while(1){
		menu();
		int n;
		char code[7];
		int people, kid;
		char date[10];
		
		node *current = head;
		node *next;
		do{
			printf("Your select: "); scanf("%d", &n);
			if(n < 0 || n > 7){
				printf("Please choose an valid option!\n");
			}
		}
		while(n < 0 || n > 7);
		switch(n){
			case 1:
				input = loadFromFile(&head);
				printf("Number of read order: %d\n", input);
				print(head);
				root = linkedListToBST(head);
				break;
			case 2:
				printf("Existing order: %d\n", count(root));
				inOrder(root);
				break;
			case 3:
				printf("Number of invalid order: %d\n", invalid(head));
				break;
			case 4:
				printf("Enter code: "); scanf("%s", code);
				res = searchNode(root, code);
				if(res == 0){
					printf("Not found!\n");
					break;
				}
				break;
			case 5:
				printf("Code: "); scanf("%s", code);
				res = searchNode(root, code);
				if(res == 0){
					printf("Not found!\n");
					break;
				}
				printf("People: "); scanf("%d", &people);
				printf("Kid: "); scanf("%d", &kid);
				printf("Date: "); scanf("%s", date);
				if(people <= kid){
					printf("Invalid!\n");
					break;
				}
				update(root, code, people, kid, date);
				printf("Updated!\n");
				break;
			case 6:
				printf("Code: "); scanf("%s", code);
				if(searchNode(root, code) == 0) {
					printf("Not found!\n");
					break;
				}
				deleteNode2(root, code);
				printf("Deleted!\n");
				break;
			case 7:
				f_clear = fopen("booking_output.txt", "w");
				printOrderToFile(root);
				printf("Write %d orders to booking_output.txt file !\n", count(root));
				break;
			case 0:
				//free linked list
				while(current != NULL){
					next = current->next;
					free(current);
					current = next;
				}
				return 0;				
		}
	}
	return 0;
}


