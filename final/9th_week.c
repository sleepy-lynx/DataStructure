#include <stdio.h>
#include <stdlib.h>

typedef struct listNode *listPointer;
typedef struct listNode {
	int data;
	listPointer link;
}listNode;

void insert(listPointer *first, listPointer x) {
	listPointer temp;
	temp = (listPointer)malloc(sizeof(listNode));
	temp->data = 50;
	if (*first) {
		temp->link = x->link;
		x->link = temp;
	}
	else {
		temp->link = NULL;
		*first = temp;
	}
}

void delete_node(listPointer *first, listPointer trail, listPointer x) {
	if(trail) 
		trail->link = x->link;
	else
		*first = (*first)->link;
	free(x);
}

void printList(listPointer first) {
	printf("The list contains: ");
	for(; first; first = first->link)
		printf("%4d", first->data);
	printf("\n");
}

void insert_with_header(listPointer x) {
	listPointer temp;
	temp = (listPointer)malloc(sizeof(listNode));
	temp->data = 50;
	temp->link = x->link;
	x->link = temp;
}

int main() {
	
}
