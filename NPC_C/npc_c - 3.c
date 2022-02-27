#define _CRT_SECURE_NO_WARNINGS
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

void InitList(List* plist);
void InsertInitItem(List* plist, Data item);
void RemoveInitItem(List* plist);
void InsertFirst(List* plist, Data item);
void RemoveFirst(List* plist);
void RemoveLast(List* plist);
Data ReadItem(List* plist, int pos);
void WriteItem(List* plist, int pos, Data item);
void Swap(List* plist, int pos1, int pos2);
int Partition(List* plist, int left, int right);
void Sort(List* plist, int left, int right);
void PR(List* plist);

int main()
{
	List basket;
	int N, K, T, A;
	InitList(&basket);

	scanf("%d %d %d", &N, &K, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		InsertFirst(&basket, A);
	}
	Sort(&basket, 0, N - 1);

	for (int i = 0; i < T; i++) {
		if (basket.sum % K != 0) {
			printf("NO\n");
			break;
		}
		WriteItem(&basket, 0, ReadItem(&basket, 0) - 1);
		WriteItem(&basket, basket.len - 1, ReadItem(&basket, basket.len - 1) + 1);
		if (ReadItem(&basket, 0) == 0)
			RemoveFirst(&basket);
		if (ReadItem(&basket, basket.len - 1) == K)
			RemoveLast(&basket);

		if (basket.len == 0) {
			printf("YES\n");
			break;
		}
		else if (basket.sum < K || i == T - 1) {
			printf("NO\n");
			break;
		}
	}

}

void InitList(List* plist)
{
	plist->tail = NULL;
	plist->len = 0;
	plist->sum = 0;
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
		plist->sum = 0; //<<<!
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
	plist->sum += item; //<<<!
}
void RemoveFirst(List* plist)
{
	if (plist->len == 1)
		RemoveInitItem(plist);
	else {
		Node* temp = plist->tail->next;
		plist->tail->next = temp->next;
		//plist->sum -= temp->item; //<<<!
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
		plist->sum -= temp->item; //<<<!
		free(temp);
		plist->tail = cur;
		plist->len--;
	}
}
Data ReadItem(List* plist, int pos)
{
	Node* cur;
	if (plist->len == 0 || pos < 0 || pos >= plist->len)
		exit(1);
	cur = plist->tail->next;
	if (pos == plist->len - 1) {
		return plist->tail->item; //To reduce time
	}
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	return cur->item;
}
void WriteItem(List* plist, int pos, Data item)
{
	Node* cur;
	if (plist->len == 0 || pos < 0 || pos >= plist->len)
		exit(1);
	cur = plist->tail->next;
	if (pos == plist->len - 1) {
		plist->tail->item = item; //To reduce time
	}
	for (int i = 0; i < pos; i++)
		cur = cur->next;
	cur->item = item;
}
void Swap(List* plist, int pos1, int pos2)
{
	Data temp = ReadItem(plist, pos1);
	WriteItem(plist, pos1, ReadItem(plist, pos2));
	WriteItem(plist, pos2, temp);
}
int Partition(List* plist, int left, int right)
{
	int pivot = ReadItem(plist, left), temp;
	int low = left + 1, high = right;

	while (1) {
		while (low < right && ReadItem(plist, low) < pivot)
			low++;
		while (high > left && ReadItem(plist, high) >= pivot)
			high--;
		if (low < high)
			Swap(plist, low, high);
		else break;
	}
	Swap(plist, left, high);
	return high;
}
void Sort(List* plist, int left, int right)
{
	if (left < right) {
		int mid = Partition(plist, left, right);
		Sort(plist, left, mid - 1);
		Sort(plist, mid + 1, right);
	}
}
void PR(List* plist)
{
	for (int i = 0; i < plist->len; i++) {
		printf("_%d_", ReadItem(plist, i));
	}
	printf("\n");
}