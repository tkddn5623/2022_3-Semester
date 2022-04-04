#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 200
#define M 200
#define MAX 10000
#pragma warning(disable : 4996)

typedef struct cell_t_ {
    char terrian;
    unsigned int height;
    unsigned int population;

} cell_t;

void cellInit(cell_t cPtr[N][M], int ROW_, int COL_);
int isOut(int ROW_, int COL_);
char gett(cell_t cptr[N][M], int ROW_, int COL_);
unsigned int geth(cell_t cptr[N][M], int ROW_, int COL_);
unsigned int getp(cell_t cptr[N][M], int ROW_, int COL_);
void inputArgument1(int* argPtr, int length);
void inputArgument2(char* argTerPtr);
int area(const int* argPtr);
void move(cell_t cptr[N][M], int ROW_, int COL_, int toROW, int toCOL, int amount)
{
    if (isOut(toROW, toCOL)) return;
    else {
        cptr[ROW_ - 1][COL_ - 1].population -= amount;
        cptr[toROW - 1][toCOL - 1].population += amount;
    }
}


//cell_t cell[N][M];
//char cmd_arg[11][N * M];
int cell_ROW, cell_COL;

int main()
{
    char cmd_type[11];
    int cmd_arg[4];
    char cmd_argTer[MAX];
    int cmd_argNum[MAX];

    cell_t cell[N][M];
    while (1)
    {
        int count;
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {
            inputArgument1(cmd_arg, 2);
            cellInit(cell, cmd_arg[0], cmd_arg[1]);
        }
        else if (!strcmp(cmd_type, "sett"))
        {
            inputArgument1(cmd_arg, 4);
            inputArgument2(cmd_argTer);
            count = 0;
            for (int i = cmd_arg[0]; i <= cmd_arg[2]; i++) 
                for (int j = cmd_arg[1]; j <= cmd_arg[3]; j++) 
                    cell[i - 1][j - 1].terrian = cmd_argTer[count++];
        }
        else if (!strcmp(cmd_type, "seth"))
        {
            inputArgument1(cmd_arg, 4);
            inputArgument1(cmd_argNum, area(cmd_arg));
            count = 0;
            for (int i = cmd_arg[0]; i <= cmd_arg[2]; i++)
                for (int j = cmd_arg[1]; j <= cmd_arg[3]; j++)
                    cell[i - 1][j - 1].height = cmd_argNum[count++];
        }
        else if (!strcmp(cmd_type, "setp"))
        {
            inputArgument1(cmd_arg, 4);
            inputArgument1(cmd_argNum, area(cmd_arg));
            count = 0;
            for (int i = cmd_arg[0]; i <= cmd_arg[2]; i++)
                for (int j = cmd_arg[1]; j <= cmd_arg[3]; j++)
                    cell[i - 1][j - 1].population = cmd_argNum[count++];
        }
        else if (!strcmp(cmd_type, "climb"))
        {
            count = 0;
            for (int i = 1; i <= cell_ROW; i++)
                for (int j = 1; j <= cell_COL; j++) {
                    char direction = 'X';
                    if (geth(cell, i, j) < geth(cell, i - 1, j))
                        direction = 'N';
                    if (geth(cell, i, j) < geth(cell, i + 1, j))
                        direction = 'S';
                    if (geth(cell, i, j) < geth(cell, i, j + 1))
                        direction = 'W';
                    if (geth(cell, i, j) < geth(cell, i, j - 1))
                        direction = 'E';
                    cmd_argTer[count] = direction;
                    cmd_argNum[count++] = getp(cell, i, j);
                }
            for (int i = 0; i < count; i++) {
                if (cmd_argTer[i] == 'E')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 1, (i % cell_COL), cmd_argNum[i]);
                else if (cmd_argTer[i] == 'W')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 1, (i % cell_COL) + 2, cmd_argNum[i]);
                else if (cmd_argTer[i] == 'S')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 2, (i % cell_COL) + 1, cmd_argNum[i]);
                else if (cmd_argTer[i] == 'N')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL), (i % cell_COL) + 1, cmd_argNum[i]);
            }
        }
        else if (!strcmp(cmd_type, "scatter"))
        {
        }
        else if (!strcmp(cmd_type, "settle"))
        {
        }
        else if (!strcmp(cmd_type, "print"))
        {
            inputArgument1(cmd_arg, 2);
            printf("%c %d %d\n", gett(cell, cmd_arg[0], cmd_arg[1]), getp(cell, cmd_arg[0], cmd_arg[1]), geth(cell, cmd_arg[0], cmd_arg[1]));
        }
        else if (!strcmp(cmd_type, "count"))
        {
            int popP = 0, popM = 0, popC = 0;
            for (int i = 1; i <= cell_ROW; i++)
                for (int j = 1; j <= cell_COL; j++) {
                    if (gett(cell, i, j) == 'P')
                        popP += getp(cell, i, j);
                    else if (gett(cell, i, j) == 'M')
                        popM += getp(cell, i, j);
                    else if (gett(cell, i, j) == 'C')
                        popC += getp(cell, i, j);
                }
            printf("%d %d %d\n", popP, popM, popC);
        }
        else if (!strcmp(cmd_type, "exit"))
        {
            break;
        }
    }
    return 0;
}

void cellInit(cell_t cPtr[N][M], int ROW_, int COL_)
{
    for (int i = 0; i < ROW_; i++)
        for (int j = 0; j < COL_; j++) {
            cPtr[i][j].terrian = 'P';
            cPtr[i][j].height = 0;
            cPtr[i][j].population = 0;
        }
    cell_ROW = ROW_; //global
    cell_COL = COL_; //global
}
int isOut(int ROW_, int COL_) {
    if (0 < ROW_ && ROW_ <= cell_ROW && 0 < COL_ && COL_ <= cell_COL)
        return 0;
    else
        return 1;
}
char gett(cell_t cptr[N][M], int ROW_, int COL_) {
    if (isOut(ROW_, COL_))
        return 'X';
    else
        return cptr[ROW_ - 1][COL_ - 1].terrian;
}
unsigned int geth(cell_t cptr[N][M], int ROW_, int COL_) {
    if (isOut(ROW_, COL_))
        return 0;
    else
        return cptr[ROW_ - 1][COL_ - 1].height;
}
unsigned int getp(cell_t cptr[N][M], int ROW_, int COL_) {
    if (isOut(ROW_, COL_))
        return 0;
    else
        return cptr[ROW_ - 1][COL_ - 1].population;
}
void inputArgument1(int* argPtr, int length)
{
    char input[11];
    for (int i = 0; i < length; i++) {
        scanf("%s", input);
        argPtr[i] = atoi(input);
    }
}
void inputArgument2(char* argTerPtr)
{
    scanf("%s", argTerPtr);
}
int area(const int* argPtr)
{
    return (argPtr[3] - argPtr[1] + 1) * (argPtr[2] - argPtr[0] + 1);
}