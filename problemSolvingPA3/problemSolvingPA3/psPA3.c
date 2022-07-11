#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 5000
#define MAXCOLOR 256
#define area(r1, c1, r2, c2) ((r2 - r1 + 1) * (c2 - c1 + 1))
#pragma warning(disable : 4996)

typedef struct {
    int row;
    int col;
} Position;
typedef struct {
    Position items[MAXSIZE * MAXSIZE];
    int front;
    int rear;
} Queue;
int sort_Partition(const int* arr1, int* arr2, int left, int right);
void sort(const int* arr1, int* arr2, int left, int right);
void myInput(int* argPtr, int length);
bool queue_isFull(Queue* pq);
bool queue_isEmpty(Queue* pq);
int queue_peekRow(Queue* pq);
int queue_peekCol(Queue* pq);
void queue_enQueue(Queue* pq, int row, int col);
void queue_deQueue(Queue* pq);

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
void myInput(int* argPtr, int length)
{
    char input[11];
    for (int i = 0; i < length; i++) {
        scanf("%s", input);
        argPtr[i] = atoi(input);
    }
}
bool queue_isFull(Queue* pq)
{
    return pq->front == (pq->rear + 1) % (MAXSIZE * MAXSIZE);
}
bool queue_isEmpty(Queue* pq)
{
    return pq->front == pq->rear;
}
int queue_peekRow(Queue* pq) {
    if (queue_isEmpty(pq)) exit(1);
    return pq->items[pq->front].row;
}
int queue_peekCol(Queue* pq) {
    if (queue_isEmpty(pq)) exit(1);
    return pq->items[pq->front].col;
}
void queue_enQueue(Queue* pq, int row, int col)
{
    if (queue_isFull(pq)) exit(1);
    pq->items[pq->rear].row = row;
    pq->items[pq->rear].col = col;
    pq->rear = (pq->rear + 1) % (MAXSIZE * MAXSIZE);
}
void queue_deQueue(Queue* pq)
{
    if (queue_isEmpty(pq)) exit(1);
    pq->front = (pq->front + 1) % (MAXSIZE * MAXSIZE);
}

int pixel[MAXSIZE + 2][MAXSIZE + 2];
int countColor[MAXCOLOR];
int countRank[MAXCOLOR];
Queue queue;
bool visited[MAXSIZE + 2][MAXSIZE + 2] = { 0 };

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
            queue.front = queue.rear = 0;
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
            myInput(cmd_arg, 3);
            queue_enQueue(&queue, cmd_arg[0], cmd_arg[1]);
            int colorOld = pixel[cmd_arg[0]][cmd_arg[1]];
            int colorNew = cmd_arg[2];
            for (int i = 0; i < MAXSIZE + 2; i++)
                for (int j = 0; j < MAXSIZE + 2; j++)
                    visited[i][j] = false;
            while (!queue_isEmpty(&queue)) {
                int row = queue_peekRow(&queue);
                int col = queue_peekCol(&queue);
                queue_deQueue(&queue);
                if (visited[row][col]) continue;
                else {
                    visited[row][col] = true;
                    countColor[pixel[row][col]]--;
                    countColor[colorNew]++;
                    pixel[row][col] = colorNew;
                }
                if (!visited[row - 1][col] && pixel[row - 1][col] == colorOld)
                    queue_enQueue(&queue, row - 1, col);
                if (!visited[row + 1][col] && pixel[row + 1][col] == colorOld)
                    queue_enQueue(&queue, row + 1, col);
                if (!visited[row][col - 1] && pixel[row][col - 1] == colorOld)
                    queue_enQueue(&queue, row, col - 1);
                if (!visited[row][col + 1] && pixel[row][col + 1] == colorOld)
                    queue_enQueue(&queue, row, col + 1);
            }
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
