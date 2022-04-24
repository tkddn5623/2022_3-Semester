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
List listRowZero = { 0 };
List listColZero = { 0 };
int subtotalRow[MAX + 2] = { 0 };
int subtotalCol[MAX + 2] = { 0 };

int main()
{
    double RUNTIME = (double)clock() / CLOCKS_PER_SEC;
    double ENDTIME = (double)clock() / CLOCKS_PER_SEC;


    /*Field** field;
    field = newField();*/
    int ar[5] = { 1, 2, 3, 4, 5 };
    
    printf("%d\n", listRowZero.item[5]);



    ENDTIME = (double)clock() / CLOCKS_PER_SEC;
    printf("TIME : %f\n", ENDTIME - RUNTIME);
}
