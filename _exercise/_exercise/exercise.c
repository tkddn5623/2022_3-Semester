#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int Element;
typedef struct {
	Element item;
	int priority;
} HNode;
typedef struct {
	HNode* nodes;
	int capacity;
	int size;
} ArrayHeap;
ArrayHeap* AH_newHeap(const int max) {
	ArrayHeap* pheap;
	if ((pheap = malloc(sizeof(ArrayHeap))) == NULL) exit(1);
	if ((pheap->nodes = malloc((max + 1) * sizeof(HNode))) == NULL) exit(1);
	pheap->capacity = max + 1;
	pheap->size = 0;
	return pheap;
}
void AH_deleteHeap(ArrayHeap* pheap) {
	if (pheap == NULL || pheap->nodes == NULL) exit(1);
	free(pheap->nodes);
	free(pheap);
}
int AH_isEmpty(const ArrayHeap* pheap) {
	return pheap->size == 0;
}
int AH_isFull(const ArrayHeap* pheap) {
	return pheap->size == pheap->capacity - 1;
}
void AH_push(ArrayHeap* pheap, const Element item, const int priority) {
	HNode newNode;
	int index = pheap->size + 1;
	while (index > 1) {
		int parentIndex = index / 2;
		if (priority < pheap->nodes[parentIndex].priority) { 
			pheap->nodes[index] = pheap->nodes[parentIndex];
			index = parentIndex;
		}
		else break;
	}
	newNode.item = item;
	newNode.priority = priority;
	pheap->nodes[index] = newNode;
	pheap->size++;
}
Element AH_pop(ArrayHeap* pheap) {
	const Element topitem = pheap->nodes[1].item;
	const HNode last = pheap->nodes[pheap->size];
	const int size = pheap->size;
	int left, pickedChild, parentIndex = 1;
	while ((left = parentIndex * 2) <= size) {
		if (left == size) pickedChild = left;
		else if (pheap->nodes[left].priority < pheap->nodes[left + 1].priority) pickedChild = left; 
		else pickedChild = left + 1;

		if (last.priority > pheap->nodes[pickedChild].priority) {
			pheap->nodes[parentIndex] = pheap->nodes[pickedChild];
			parentIndex = pickedChild;
		}
		else break;
	}
	pheap->nodes[parentIndex] = last;
	pheap->size--;
	return topitem;
}
int main() {
	ArrayHeap* heap;
	int N;
	scanf("%d", &N);
	heap = AH_newHeap(N);
	for (int i = 0; i < N; i++) {
		int arg;
		scanf("%d", &arg);
		if (arg) {
			if(!AH_isFull(heap)) AH_push(heap, arg, arg);
		}
		else {
			if (!AH_isEmpty(heap)) printf("%d\n", AH_pop(heap));
			else printf("0\n");
		}
	}
	AH_deleteHeap(heap);
}