#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Data;
typedef struct _Node
{
	Data item;
	struct _Node* next;
	struct _Node* prev;
} Node;
typedef struct
{
	Node* tail;
	int len;
	int sum;
}List;

int isFail(List* plist, int c, int K, int T);
int isLeftDelete(List* plist, int K);
void InitList(List* plist);
void InsertInitItem(List* plist, Data item);
void RemoveInitItem(List* plist);
void InsertFirst(List* plist, Data item);
void RemoveFirst(List* plist);
void RemoveLast(List* plist);
Data ReadItem(List* plist, int pos);
void WriteItem(List* plist, int pos, Data item);
void Swap(Data* arr, int pos1, int pos2);
int Partition(Data* arr, int left, int right);
void Sort(Data* arr, int left, int right);
void PR(List* plist);

int main()
{
	List basket;
	int N, K, A;
	int T;
	InitList(&basket);
	int arr[100000];
	int count = 0;

	scanf("%d %d %d", &N, &K, &T);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A);
		arr[i] = A;
		//InsertFirst(&basket, A);
	}
	Sort(arr, 0, N - 1);
	for (int i = N - 1; i >= 0; i--)
		if (arr[i] != 0)
			InsertFirst(&basket, arr[i]);

	for (int i = 0; i < 2 * N; i++) {
		//PR(&basket); printf("Left count is %d\n", T - count);
		if (basket.len == 0) {
			printf("YES");
			break;
		}
		if (basket.len == 1 || isFail(&basket, count, K, T)) {
			printf("NO");
			break;
		}
		if (isLeftDelete(&basket, K)) {
			count += ReadItem(&basket, 0);
			WriteItem(&basket, basket.len - 1, ReadItem(&basket, 0) + ReadItem(&basket, basket.len - 1));
			RemoveFirst(&basket);
		}
		else {
			count += K - ReadItem(&basket, basket.len - 1);
			WriteItem(&basket, 0, ReadItem(&basket, 0) - (K - ReadItem(&basket, basket.len - 1)));
			WriteItem(&basket, basket.len - 1, K);
			RemoveLast(&basket);
			if (ReadItem(&basket, 0) == 0) {
				RemoveFirst(&basket);
			}
		}
		/*if (basket.len == 0) {
			printf("YES");
			break;
		}*/
	}

}

int isFail(List* plist, int c, int K, int T)
{
	int smaller = ReadItem(plist, 0) <= K - ReadItem(plist, plist->len - 1) ? ReadItem(plist, 0) : K - ReadItem(plist, plist->len - 1);
	/*if ((plist->sum < K && c != 0))
		printf("Third condition activated but not return 1\n");*/
	if (smaller > T - c || T - c <= 0  )
		return 1;
	else
		return 0;
}
int isLeftDelete(List* plist, int K)
{
	if (ReadItem(plist, 0) < K - ReadItem(plist, plist->len - 1))
		return 1;
	else
		return 0;
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
	newNode->prev = newNode;
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
		newNode->prev = plist->tail;
		plist->tail->next = newNode;
		newNode->next->prev = newNode;
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
		temp->next->prev = plist->tail;
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
		cur = plist->tail->prev;
		temp = cur->next;
		cur->next = temp->next;
		temp->next->prev = cur;
		plist->sum -= temp->item; //<<<!
		//printf("Vo!%d and sum:%d\n", temp->item, plist->sum);
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
	else if (pos == plist->len - 2) { //plz
		return plist->tail->prev->item;
	}
	for (int i = 0; i < pos; i++) {
		//printf("WTH\n");
		cur = cur->next;
	}
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
		return;
	}
	else if (pos == plist->len - 2) { //plz
		plist->tail->prev->item = item;
		return;
	}
	for (int i = 0; i < pos; i++) {
		//printf("WTH\n");
		cur = cur->next;
	}
	cur->item = item;
}
void Swap(Data* arr, int pos1, int pos2)
{
	Data temp = arr[pos1];
	arr[pos1] = arr[pos2];
	arr[pos2] = temp;
}
int Partition(Data* arr, int left, int right)
{
	int pivot = arr[left], temp;
	int low = left + 1, high = right;

	while (1) {
		while (low < right && arr[low] < pivot)
			low++;
		while (high > left && arr[high] >= pivot)
			high--;
		if (low < high)
			Swap(arr, low, high);
		else break;
	}
	Swap(arr, left, high);
	return high;
}
void Sort(Data* arr, int left, int right)
{
	if (left < right) {
		int mid = Partition(arr, left, right);
		Sort(arr, left, mid - 1);
		Sort(arr, mid + 1, right);
	}
}
void PR(List* plist)
{
	for (int i = 0; i < plist->len; i++) {
		printf("_%d_", ReadItem(plist, i));
	}
	printf("\n");
}