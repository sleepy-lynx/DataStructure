#include <stdio.h>
#include <stdlib.h>

typedef struct polyNode* polyPointer;
typedef struct polyNode {
	int coef;
	int expon;
	polyPointer link;
}polyNode;

typedef struct element {
	int data;
}element;

typedef struct node *nodePointer;
typedef struct node {
	nodePointer llink;
	element data;
	nodePointer rlink;
}node;

int COMPARE(int a, int b){
	if(a < b) return -1;
	else if (a == b) return 0;
	return 1;
}

void attach(int coef, int expon, polyPointer *ptr) {
	polyPointer temp = (polyPointer)malloc(sizeof(polyNode));
	temp->coef = coef;
	temp->expon = expon;
	(*ptr)->link = temp;
	*ptr = temp;
}

polyPointer padd(polyPointer a, polyPointer b) {
	polyPointer c, rear, temp;
	int sum;
	rear = (polyPointer)malloc(sizeof(polyNode));
	c = rear;
	while(a && b) {
		switch(COMPARE(a->expon, b->expon)) {
			case -1:
				attach(b->coef, b->expon, &rear);
				b = b->link;
				break;
			case 0:
				sum = a->coef + b->coef;
				if(sum) attach(sum, a->expon, &rear);
				break;
			case 1:
				attach(a->coef, a->expon, &rear);
				a = a->link;
		}
	}
	for(; a; a=a->link) attach(a->coef, a->expon, &rear);
	for(; b; b=b->link) attach(b->coef, b->expon, &rear);
	rear->link = NULL;
	temp = c; c = c->link; free(temp);
	return c;
}

polyPointer cpadd(polyPointer a, polyPointer b) {
	polyPointer startA, c, lastC;
	int sum, done = 0;
	startA = a;
	a = a->link;
	b = b->link;
	c = (polyPointer)malloc(sizeof(polyNode));
	c->expon = -1; lastC = c;
	do {
		switch(COMPARE(a->expon, b->expon)) {
			case -1:
				attach(b->coef, b->expon, &lastC);
				b = b->link;
				break;
			case 0:
				if(startA == a) done=1;
				else {
					sum = a->coef + b->coef;
					if(sum) attach(sum, a->expon, &lastC);
					a = a->link; b = b->link;
				}
				break;
			case 1:
				attach(a->coef, a->expon, &lastC);
				a = a->link;
		}
	} while(!done);

	lastC->link = c;
	return c;
}

