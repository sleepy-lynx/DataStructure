#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define TABLE_SIZE 26

typedef struct {
	int key;

}element;
element *ht[TABLE_SIZE];

int choose(int distance[], int n, short int found[]) {
	int i, min, minpos;
	min = 2e9;
	minpos = -1;
	for(i = 0;i<n;i++){
		if(distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void dijkstra(int v, int cost[][MAX_VERTICES], int distance[], int n, short int found[]) {
	int i, u, w;
	for(i = 0;i<n;i++){
		found = 0;
		distance[i] = cost[v][i];
	}
	found[v] = 1;
	distance[v] = 0;
	for(int i=0;i<n-2;i++){
		u = choose(distance, n, found);
		found[u] = 1;
		for(w = 0;w<n;w++){
			if(!found[w] && distance[u] + cost[u][w] < distance[w])
				distance[w] = distance[u] + cost[u][w];
		}
	}
}

unsigned int stringToInt(char *key) {
	int number = 0;
	while(*key)
		number += *key++;
	return number;
}

element *search(int k) {
	int homeBucket, currentBucket;
	homeBucket = h(k);
	for(currentBucket = homeBucket;
			ht[currentBucket] && ht[currentBucket]->key != k; ){
		currentBucket = (currentBucket + 1) % b;
		if(currentBucket == homeBucket) return NULL;
	}
	if(ht[currentBucket]->key == k)
		return ht[currentBucket];
	return NULL;
}

element *searchClosed(int k) {
	nodePointer current;
	int homeBucket = h(k);
	for(current = ht[homeBucket]; current; current = current->link) {
		if(current->data.key == k) return &current->data;
	}
	return NULL;
}
