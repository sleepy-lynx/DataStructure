#include <stdio.h>
#include <stdlib.h>

typedef struct node* treePointer;
typedef struct node {
	treePointer leftChild;
	int data;
	treePointer rightChild;
}node;

void inorder(treePointer ptr){
	if(ptr) {
		inorder(ptr->leftChild);
		printf("%d", ptr->data);
		inorder(ptr->rightChild);
	}
}

void preorder(treePointer ptr) {
	if(ptr) {
		printf("%d", ptr->data);
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

void postorder(treePointer ptr) {
	if(ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		printf("%d", ptr->data);
	}
}

void iterInorder(treePointer node) {
	int top=-1;
	treePointer stack[1000];
	while(1) {
		for(; node; node = node->leftChild)
			push(node);
		node = pop();
		if(!node) break;
		printf("%d", node->data);
		node = node->rightChild;
	}
}

void levelOrder(treePointer ptr) {
	int front = rear = 0;
	treePointer queue[1000];
	if(!ptr) return;
	addq(ptr);
	for(;;) {
		ptr = deleteq();
		if(ptr) {
			printf("%d", ptr->data);
			if(ptr->leftChild)
				addq(ptr->leftChild);
			if(ptr->rightChild)
				addq(ptr->rightChild);
		}
		else break;
	}
}
