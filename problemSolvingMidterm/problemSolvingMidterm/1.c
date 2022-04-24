#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int arr[500][500];

void pushRight(int arr[500][500], int size)
{
	int temp;
	for (int i = 0; i < size; i++) {
		temp = arr[i][size - 1];
		for (int j = size - 1; j >= 0; j--) {
			if(j - 1 >= 0)
				arr[i][j] = arr[i][j - 1];
		}
		arr[i][0] = temp;
	}
}
void pushLeft(int arr[500][500], int size)
{
	int temp;
	for (int i = 0; i < size; i++) {
		temp = arr[i][0];
		for (int j = 0; j < size; j++) {
			if (j + 1 < size)
				arr[i][j] = arr[i][j + 1];
		}
		arr[i][size - 1] = temp;
	}
}
void pushDown(int arr[500][500], int size)
{
	int temp;
	for (int j = 0; j < size; j++) {
		temp = arr[size - 1][j];
		for (int i = size - 1; i >= 0; i--) {
			if (i - 1 >= 0)
				arr[i][j] = arr[i - 1][j];
		}
		arr[0][j] = temp;
	}
}
void pushUp(int arr[500][500], int size)
{
	int temp;
	for (int j = 0; j < size; j++) {
		temp = arr[0][j];
		for (int i = 0; i < size; i--) {
			if (i + 1 < size)
				arr[i][j] = arr[i + 1][j];
		}
		arr[size - 1][j] = temp;
	}
}


int main()
{
	int size;
	int X = 0;
	int Y = 0;
	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			scanf("%d", &(arr[i][j]));
		}
	}
	scanf("%d %d", &X, &Y);

	if (X > 0) 
		for (X; X > 0; X--) 
			pushRight(arr, size);
	else if (X < 0) 
		for (X; X < 0; X++) 
			pushLeft(arr, size);
		
	if (Y > 0) 
		for (Y; Y > 0; Y--) 
			pushDown(arr, size);
	else if (Y < 0) {
		for (Y; Y < 0; Y++) 
			pushUp(arr, size);

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}