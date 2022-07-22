#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Data;
typedef struct {
	Data* items;
	int size;
	int top;
} ArrayStack;
ArrayStack* AS_newStack(const int size);
void AS_deleteStack(ArrayStack* pstack);
int AS_isFull(const ArrayStack* pstack);
int AS_isEmpty(const ArrayStack* pstack);
Data AS_peek(const ArrayStack* pstack);
void AS_push(ArrayStack* pstack, const Data item);
Data AS_pop(ArrayStack* pstack);

int main()
{
	ArrayStack* stack = AS_newStack(9000);
	int N, argument;
	char cmdline[20];
	char* cmdarg;
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		fgets(cmdline, sizeof(cmdline), stdin);
		strtok(cmdline, "\n");
		cmdarg = strtok(cmdline, " ");
		if (!strcmp(cmdarg, "push")) {
			argument = atoi(strtok(NULL, " "));
			if (!AS_isFull(stack)) AS_push(stack, argument);
		}
		else if (!strcmp(cmdarg, "pop")) {
			if (AS_isEmpty(stack)) printf("-1\n");
			else printf("%d\n", AS_pop(stack));
		}
		else if (!strcmp(cmdarg, "size")) {
			printf("%d\n", stack->top + 1);
		}
		else if (!strcmp(cmdarg, "empty")) {
			printf("%d\n", AS_isEmpty(stack));
		}
		else if (!strcmp(cmdarg, "top")) {
			if (AS_isEmpty(stack)) printf("-1\n");
			else printf("%d\n", AS_peek(stack));
		}
		else if (!strcmp(cmdarg, "exit")) {
			break;
		}
	}
	AS_deleteStack(stack);
}

ArrayStack* AS_newStack(const int size) {
	ArrayStack* pstack;
	if ((pstack = malloc(sizeof(ArrayStack))) == NULL) exit(1);
	if ((pstack->items = malloc(size * sizeof(Data))) == NULL) exit(1);
	pstack->size = size;
	pstack->top = -1;
	return pstack;
}
void AS_deleteStack(ArrayStack* pstack) {
	if (pstack == NULL || pstack->items == NULL) exit(1);
	free(pstack->items);
	free(pstack);
}
int AS_isFull(const ArrayStack* pstack) {
	return pstack->top == pstack->size - 1;
}
int AS_isEmpty(const ArrayStack* pstack) {
	return pstack->top == -1;
}
Data AS_peek(const ArrayStack* pstack) {
	if (pstack->top == -1) exit(1);
	return pstack->items[pstack->top];
}
void AS_push(ArrayStack* pstack, const Data item) {
	if (pstack->top == pstack->size - 1) exit(1);
	pstack->items[++(pstack->top)] = item;
}
Data AS_pop(ArrayStack* pstack) {
	if (pstack->top == -1) exit(1);
	return pstack->items[(pstack->top)--];
}
