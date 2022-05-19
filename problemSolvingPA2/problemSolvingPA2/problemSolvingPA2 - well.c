#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> //<<NO NEED
#define MAX 500 //<<5000
#define getMAX(a,b) a > b? a : b

typedef struct List_ {
    int item[MAX + 2];
    int len;
}List;
typedef struct Field_ {
    int subtotalRow;
    int subtotalCol;
    bool fence;
}Field;
typedef struct MaxArea_ {
    int value;
    int row1;
    int row2;
    int col1;
    int col2;
}MaxArea;
typedef struct AreaStack_ {
    int row[MAX * MAX];
    int col[MAX * MAX];
    int top;
}AreaStack;

Field** newField()
{
    Field** pfield = (Field**)malloc(sizeof(Field*) * (MAX + 2));
    for (int i = 0; i < MAX + 2; i++) {
        pfield[i] = (Field*)malloc(sizeof(Field) * (MAX + 2));
        for (int j = 0; j < MAX + 2; j++) {
            pfield[i][j].subtotalRow = 0;
            pfield[i][j].subtotalCol = 0;
            pfield[i][j].fence = false;
        }
    }
    return pfield;
}
void fieldInit(Field pfield[][MAX + 2])
{
    for (int i = 0; i < MAX + 2; i++) {
        for (int j = 0; j < MAX + 2; j++) {
            pfield[i][j].subtotalRow = 0;
            pfield[i][j].subtotalCol = 0;
            pfield[i][j].fence = false;
        }
    }
}
void Swap(int* a, int* b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
int QuickSort_part(AreaStack* pstack, int left, int right)
{
    //printf("add2 : %d\n", pstack);
    int areaList[MAX * MAX];
    for (int i = 0; i < (pstack->top) + 1; i++)
        areaList[i] = pstack->row[i] * (pstack->col[i]);
    int pivot = areaList[left];
    int low = left + 1, high = right;
    while (true) {
        while (low < right && areaList[low] < pivot)
            low++;
        while (high > left && areaList[high] >= pivot)
            high--;
        if (low < high) {
            Swap(&areaList[low], &areaList[high]);
            Swap(&pstack->row[low], &pstack->row[high]);
            Swap(&pstack->col[low], &pstack->col[high]);
        }
        else break;
    }
    Swap(&areaList[left], &areaList[high]);
    Swap(&pstack->row[left], &pstack->row[high]);
    Swap(&pstack->col[left], &pstack->col[high]);
    return high;
}
void QuickSort(AreaStack* pstack, int left, int right)
{
    if (left < right) {
        int mid = QuickSort_part(pstack, left, right);
        QuickSort(pstack, left, mid - 1);
        QuickSort(pstack, mid + 1, right);
    }
}


Field field[MAX + 2][MAX + 2] = { 0 };
MaxArea maxArea = { 0 };
AreaStack areaStack;
int subtotalRow[MAX + 2] = { 0 };
int subtotalCol[MAX + 2] = { 0 };


int main()
{
    double RUNTIME = (double)clock() / CLOCKS_PER_SEC;
    double ENDTIME = (double)clock() / CLOCKS_PER_SEC;

    bool esc = false;
    int N, M;
    int maxsubRow = 0, maxsubCol = 0;
    int rowCount, colCount;
    char temp2;
    scanf("%d %d", &N, &M);        // INPUT PART1 : N, M
    for (int i = 1; i <= N; i++) {  // INPUT PART2 : fence, subtotal
        rowCount = 0;
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &temp2);   // INPUT
            field[i][j].fence = temp2 - '0';
            field[i][j].subtotalRow = field[i][j].fence + field[i][j - 1].subtotalRow; // Sj = aj + Sj-1
            field[i][j].subtotalCol = field[i][j].fence + field[i - 1][j].subtotalCol; // Si = ai + Si-1
            if (field[i][j].subtotalRow <= field[i][j - 1].subtotalRow) {
                rowCount = 0;
            }
            else {
                rowCount++;
                maxsubRow = getMAX(rowCount, maxsubRow); // loop getting maxsubRow
            }
        }
    }
    for (int j = 1; j <= M; j++) {
        colCount = 0;
        for (int i = 1; i <= N; i++) {
            if (field[i][j].subtotalCol <= field[i - 1][j].subtotalCol) {
                colCount = 0;
            }
            else {
                colCount++;
                maxsubCol = getMAX(colCount, maxsubCol); // loop getting maxsubCol
            }
        }
    }
    areaStack.top = -1; // Make Stack empty
    for (int i = 1; i <= maxsubRow; i++) {
        for (int j = 1; j <= maxsubCol; j++) { // loop pushing item in Stack
            areaStack.row[++areaStack.top] = j;
            areaStack.col[areaStack.top] = i;
        }
    }
    QuickSort(&areaStack, 0, areaStack.top);
    while (areaStack.top > -1 && esc == false) {
        int height = areaStack.row[areaStack.top]; // poping item in Stack
        int length = areaStack.col[areaStack.top--];
        for (int i = 1; i <= N - height + 2 && esc == false; i++) {
            for (int j = 1; j < M - length + 2; j++) {
                if (field[i + height - 1][j].subtotalCol - field[i - 1][j].subtotalCol < height) 
                    continue;
                if (field[i + height - 1][j + length - 1].subtotalCol - field[i - 1][j + length - 1].subtotalCol < height) 
                    continue;
                if (field[i][j + length - 1].subtotalRow - field[i][j - 1].subtotalRow < length) 
                    continue;
                if (field[i + height - 1][j + length - 1].subtotalRow - field[i + height - 1][j - 1].subtotalRow < length) 
                    continue;
                maxArea.value = height * length;
                maxArea.row1 = i;
                maxArea.col1 = j;
                maxArea.row2 = i + height - 1;
                maxArea.col2 = j + length - 1;
                esc = true;
                break;
            }
        }
    }
    printf("%d %d %d %d\n", maxArea.row1, maxArea.col1, maxArea.row2, maxArea.col2);

    ENDTIME = (double)clock() / CLOCKS_PER_SEC;
    printf("TIME : %.3f\n", ENDTIME - RUNTIME);
}
