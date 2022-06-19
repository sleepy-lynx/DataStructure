#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int key;
}element;

typedef struct node* treePointer;
typedef struct node {
	element data;
	treePointer leftChild;
	treePointer rightChild;
}node;

treePointer copy(treePointer original) {
	treePointer temp;
	if(original) {
		temp = (treePointer)malloc(sizeof(node));
		temp->leftChild = copy(original->leftChild);
		temp->rightChild = copy(original->rightChild);
		return temp;
	}
	return NULL;
}

int equal(treePointer first, treePointer second) {
	return((!first && !second) || (first && second && 
				(first->data.key == second->data.key) &&
				equal(first->leftChild, second->rightChild) && 
				equal(first->rightChild, second->rightChild)));
}

element *search(treePointer root, int k) {
	if(!root) return NULL;
	if(k == root->data.key) return &(root->data);
	if(k < root->data.key) return search(root->leftChild, k);
	return search(root->rightChild, k);
}

element *iterSearch(treePointer tree, int k){
	while(tree){
		if(k == tree->data.key) return &(tree->data);
		if(k < tree->data.key)
			tree = tree->leftChild;
		else
			tree = tree->rightChild;
	}
	return NULL;
}

void insert(treePointer *node, int k) {
	treePointer ptr; temp = modifiedSearch(*node ,k);
	if(temp || !(*node)) {
		ptr = (treePointer)malloc(sizeof(node));
		ptr->data.key = k;
		ptr->leftChild = NULL;
		ptr->rightChild = NULL;
		if(*node)
			if(k < temp->data.key) temp->leftChild = ptr;
			else temp->rightChild = ptr;
		else *node = ptr;
	}
}
