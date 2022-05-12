#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h> //<<NO NEED
#define MAX 5000

typedef struct List_ {
    int item[MAX + 2];
    int len;
}List;

typedef struct Field_ {
    bool fence;
    int nextZeroRow;
    int nextZeroCol;
}Field;

bool isConnected()
{
    return true;
}
void ListPush(List* plist, int item)
{
    plist->item[plist->len++] = item;
}
Field** newField()
{
    Field** pfield = (Field**)malloc(sizeof(Field*) * (MAX + 2));
    for (int i = 0; i < MAX + 2; i++) {
        pfield[i] = (Field*)malloc(sizeof(Field) * (MAX + 2));
        for (int j = 0; j < MAX + 2; j++) {
            pfield[i][j].fence = false;
            pfield[i][j].nextZeroRow = 0;
            pfield[i][j].nextZeroCol = 0;
        }
    }
    return pfield;
}
void fieldInit(Field pfield[][MAX + 2])
{
    for (int i = 0; i < MAX + 2; i++) {
        for (int j = 0; j < MAX + 2; j++) {
            pfield[i][j].fence = false;
            pfield[i][j].nextZeroRow = 0;
            pfield[i][j].nextZeroCol = 0;
        }
    }
}


Field field[MAX + 2][MAX + 2] = { 0 };
List listRowZero[MAX + 2] = { 0 };
List listColZero[MAX + 2] = { 0 };
int subtotalRow[MAX + 2] = { 0 };
int subtotalCol[MAX + 2] = { 0 };
char argument[MAX + 2] = { 0 };

int main()
{
    double RUNTIME = (double)clock() / CLOCKS_PER_SEC;
    double ENDTIME = (double)clock() / CLOCKS_PER_SEC;

    int N, M;
    char temp;
    scanf("%d %d", &N, &M); // INPUT PART1


    for (int i = 0; i < N + 2; i++)  // Imaginary 0 treated like real 0.
        ListPush(&listRowZero[i], 0);
    for (int j = 0; j < M + 2; j++)
        ListPush(&listColZero[j], 0);

    for (int i = 1; i <= N; i++) { // INPUT PART2
        for (int j = 1; j <= M; j++) {
            scanf(" %c", &temp);
            field[i][j].fence = temp - '0';
            if (temp == '0') {
                ListPush(&listRowZero[i], j); // Push to list
                ListPush(&listColZero[j], i);
            }
        }
    }
    for (int i = 0; i < N + 2; i++)  // Imaginary 0 treated like real 0.(Repeated)
        ListPush(&listRowZero[i], M + 1);
    for (int j = 0; j < M + 2; j++)
        ListPush(&listColZero[j], N + 1);






    ENDTIME = (double)clock() / CLOCKS_PER_SEC;
    printf("TIME : %f\n", ENDTIME - RUNTIME);
}
