#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int Element;
typedef struct {
	Element* items;
	int capacity;
	int front;
	int rear;
} ArrayDeque;
ArrayDeque * AD_newDeque(const int max) {
	ArrayDeque* pdeque;
	if ((pdeque = malloc(sizeof(ArrayDeque))) == NULL) exit(1);
	if ((pdeque->items = malloc((max + 1) * sizeof(Element))) == NULL) exit(1);
	pdeque->capacity = max + 1;
	pdeque->front = 0;
	pdeque->rear = 0;
	return pdeque;
}
void AD_deleteDeque(ArrayDeque* pdeque) {
	if (pdeque == NULL || pdeque->items == NULL) exit(1);
	free(pdeque->items);
	free(pdeque);
}
int AD_isFull(const ArrayDeque* pdeque) {
	return pdeque->front == (pdeque->rear + 1) % pdeque->capacity;
}
int AD_isEmpty(const ArrayDeque* pdeque) {
	return pdeque->front == pdeque->rear;
}
int AD_size(const ArrayDeque* pdeque) {
	const int subtract = pdeque->rear - pdeque->front;
	if (subtract >= 0) return subtract;
	else return pdeque->capacity + subtract;
}
Element AD_front(const ArrayDeque* pdeque) {
	const int front = pdeque->front;
	if (front == pdeque->rear) exit(1);
	return pdeque->items[front];
}
Element AD_back(const ArrayDeque* pdeque) {
	const int rear = pdeque->rear, capacity = pdeque->capacity;
	if (pdeque->front == rear) exit(1);
	return pdeque->items[(rear + capacity - 1) % capacity];
}
void AD_pushFront(ArrayDeque* pdeque, const Element item) {
	const int capacity = pdeque->capacity, behind = (pdeque->front + capacity - 1) % capacity;
	if (pdeque->front == (pdeque->rear + 1) % capacity) exit(1);
	pdeque->items[behind] = item;
	pdeque->front = behind;
}
void AD_pushBack(ArrayDeque* pdeque, const Element item) {
	const int rear = pdeque->rear, capacity = pdeque->capacity;
	if (pdeque->front == (rear + 1) % capacity) exit(1);
	pdeque->items[rear] = item;
	pdeque->rear = (rear + 1) % capacity;
}
Element AD_popFront(ArrayDeque* pdeque) {
	const int front = pdeque->front;
	if (front == pdeque->rear) exit(1);
	pdeque->front = (front + 1) % pdeque->capacity;
	return pdeque->items[front];
}
Element AD_popBack(ArrayDeque* pdeque) {
	const int rear = pdeque->rear, capacity = pdeque->capacity;
	const int behind = (rear + capacity - 1) % capacity;
	if (pdeque->front == rear) exit(1);
	pdeque->rear = behind;
	return pdeque->items[behind];
}
int main() {
	ArrayDeque* deque = AD_newDeque(10000);
	int N, argument;
	char cmdline[20];
	char* cmdarg;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		fgets(cmdline, sizeof(cmdline), stdin);
		strtok(cmdline, "\n");
		cmdarg = strtok(cmdline, " ");
		if (!strcmp(cmdarg, "push_front")) {
			argument = atoi(strtok(NULL, " "));
			if (!AD_isFull(deque)) AD_pushFront(deque, argument);
		}
		else if (!strcmp(cmdarg, "push_back")) {
			argument = atoi(strtok(NULL, " "));
			if (!AD_isFull(deque)) AD_pushBack(deque, argument);
		}
		else if (!strcmp(cmdarg, "pop_front")) {
			if (AD_isEmpty(deque)) printf("-1\n");
			else printf("%d\n", AD_popFront(deque));
		}
		else if (!strcmp(cmdarg, "pop_back")) {
			if (AD_isEmpty(deque)) printf("-1\n");
			else printf("%d\n", AD_popBack(deque));
		}
		else if (!strcmp(cmdarg, "size")) {
			printf("%d\n", AD_size(deque));
		}
		else if (!strcmp(cmdarg, "empty")) {
			printf("%d\n", AD_isEmpty(deque));
		}
		else if (!strcmp(cmdarg, "front")) {
			if (AD_isEmpty(deque)) printf("-1\n");
			else printf("%d\n", AD_front(deque));
		}
		else if (!strcmp(cmdarg, "back")) {
			if (AD_isEmpty(deque)) printf("-1\n");
			else printf("%d\n", AD_back(deque));
		}
	}
	AD_deleteDeque(deque);
}