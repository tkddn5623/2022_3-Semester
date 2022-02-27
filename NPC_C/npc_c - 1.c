#define _CRT_NO_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
} Node;
typedef struct
{
	Node* tail;
	int len;
	int sum;
}List;

void InsertInitItem(List* plist, Data item);
void RemoveInitItem(List* plist);
void InsertFirst(List* plist, Data item);
void RemoveFirst(List* plist);
void RemoveLast(List* plist);

int main()
{

}

void InsertInitItem(List* plist, Data item)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->next = newNode;
	plist->tail = newNode;
	plist->len++;
}
void RemoveInitItem(List* plist)
{
	if (plist->len == 0)
		exit(1);
	else if (plist->len == 1) {
		free(plist->tail);
		plist->len--;
		plist->tail = NULL;
	}
}
void InsertFirst(List* plist, Data item)
{
	if (plist->len == 0)
		InsertInitItem(plist, item);
	else {
		Node* newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->len++;
	}
}
void RemoveFirst(List* plist)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else {
		Node* temp = plist->tail->next;
		plist->tail->next = temp->next;
		free(temp);
		plist->len--;
	}
}
void RemoveLast(List* plist)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else {
		Node* cur, * temp;
		cur = plist->tail;
		for (int i = 0; i < plist->len - 1; i++)
			cur = cur->next;
		temp = cur->next;
		cur->next = temp->next;
		free(temp);
		plist->tail = cur;
		plist->len--;
	}
}