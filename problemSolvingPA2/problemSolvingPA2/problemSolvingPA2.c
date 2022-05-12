#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> //<<NO NEED
#define MAX 500 //<<5000

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


Field field[MAX + 2][MAX + 2] = { 0 };
int subtotalRow[MAX + 2] = { 0 };
int subtotalCol[MAX + 2] = { 0 };


int main()
{
    double RUNTIME = (double)clock() / CLOCKS_PER_SEC;
    double ENDTIME = (double)clock() / CLOCKS_PER_SEC;

    int N, M;
    char temp;
    scanf("%d %d", &N, &M);        // INPUT PART1 : N, M
    for (int i = 1; i <= N; i++)  // INPUT PART2 : fence, subtotal
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &temp);   // INPUT
            field[i][j].fence = temp - '0';
            field[i][j].subtotalRow = field[i][j].fence + field[i][j - 1].subtotalRow; // Sj = aj + Sj-1
            field[i][j].subtotalCol = field[i][j].fence + field[i - 1][j].subtotalCol; // Si = ai + Si-1
        }
    //이제 5000x5000부터 확인만 하면 됨
    //일단 짜고싶은 대로 짜고 시간재시오.
    for (int a = 5000; a >= 2; a--) {
        for (int b = 5000; b >= 2; b--) {

        }
    }





    ENDTIME = (double)clock() / CLOCKS_PER_SEC;
    printf("TIME : %.3f\n", ENDTIME - RUNTIME);
}
