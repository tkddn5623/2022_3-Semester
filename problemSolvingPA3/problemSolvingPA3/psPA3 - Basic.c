#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 5000
#define MAXCOLOR 256
#define area(r1, c1, r2, c2) ((r2 - r1 + 1) * (c2 - c1 + 1))
#pragma warning(disable : 4996)

int sort_Partition(const int* arr1, int* arr2, int left, int right);
void sort(const int* arr1, int* arr2, int left, int right);
void myInput(int* argPtr, int length);
void myInput(int* argPtr, int length)
{
    char input[11];
    for (int i = 0; i < length; i++) {
        scanf("%s", input);
        argPtr[i] = atoi(input);
    }
}
int sort_Partition(const int* arr1, int* arr2, int left, int right)
{
    int pivot = arr1[arr2[left]];
    int low = left + 1, high = right;
    int temp;

    while (1) {
        while (low < right && arr1[arr2[low]] > pivot)
            low++;
        while (high > left && arr1[arr2[high]] <= pivot)
            high--;
        if (low < high) {
            temp = arr2[low];
            arr2[low] = arr2[high];
            arr2[high] = temp;
        }
        else break;
    }
    temp = arr2[left];
    arr2[left] = arr2[high];
    arr2[high] = temp;
    return high;
}
void sort(const int* arr1, int* arr2, int left, int right)
{
    if (left < right) {
        int mid = sort_Partition(arr1, arr2, left, right);
        sort(arr1, arr2, left, mid - 1);
        sort(arr1, arr2, mid + 1, right);
    }
}



int pixel[MAXSIZE + 1][MAXSIZE + 1];
int countColor[MAXCOLOR];
int countRank[MAXCOLOR];

int main()
{
    int N = 0;
    char cmd_type[11];
    int cmd_arg[5];
    while (1)
    {
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {
            myInput(&N, 1);
            memset(pixel, -1, sizeof(pixel));
            memset(countColor, 0, sizeof(countColor));
            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++)
                    pixel[r][c] = 0;
            }
            for (int i = 0; i < MAXCOLOR; i++)
                countRank[i] = i;
            countColor[0] = N * N;
        }
        else if (!strcmp(cmd_type, "rect"))
        {
            myInput(cmd_arg, 5);
            for (int r = cmd_arg[0]; r <= cmd_arg[2]; r++) {
                for (int c = cmd_arg[1]; c <= cmd_arg[3]; c++) {
                    countColor[pixel[r][c]]--;
                    countColor[cmd_arg[4]]++;
                    pixel[r][c] = cmd_arg[4];
                }
            }
        }
        else if (!strcmp(cmd_type, "fill"))
        { //MAIN PART OF THE ASSIGNMENT
            
        }
        else if (!strcmp(cmd_type, "count"))
        {
            sort(countColor, countRank, 0, MAXCOLOR - 1);
            for (int i = 0; i < MAXCOLOR; i++) {
                if (!countColor[countRank[i]]) break;
                printf("%d:%d\n", countRank[i], countColor[countRank[i]]);
            }
        }
        else if (!strcmp(cmd_type, "exit"))
        {
            break;
        }
        else if (!strcmp(cmd_type, "print"))//DELETE
        {
            for (int r = 1; r <= N; r++) {
                for (int c = 1; c <= N; c++)
                    printf("%d ", pixel[r][c]);
                printf("\n");
            }
        }
    }
    return 0;
}
