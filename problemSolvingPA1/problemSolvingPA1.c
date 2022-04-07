#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> //<<DELETE.
#define N 5000
#define M 5000
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
void move(cell_t cptr[N][M], int ROW_, int COL_, int toROW, int toCOL, int amount);
int addsubArr(int* subarr, int start, int end);


//cell_t cell[N][M];
cell_t cell[N][M];
char cmd_argTer[N * M + 10];
int cmd_argNum[N * M + 10];
int movingEntry[N + 1][M + 1];
int movingVisited[N + 1][M + 1];
char movingDirec[N + 1][M + 1];
int cell_ROW, cell_COL;

int main()
{
    char cmd_type[11];
    int cmd_arg[4];
    double RUNTIME = (double)clock() / CLOCKS_PER_SEC;
    double ENDTIME = (double)clock() / CLOCKS_PER_SEC;
    while (1)
    {
        int count;
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {
            inputArgument1(cmd_arg, 2);
            cellInit(cell, cmd_arg[0], cmd_arg[1]);         
        }
        else if (!strcmp(cmd_type, "FUCK"))
        {
            RUNTIME = (double)clock() / CLOCKS_PER_SEC;
            srand(time(NULL));
           // printf("R AND C %d %d\n", cell_ROW, cell_COL);
            for (int i = 1; i <= cell_ROW; i++) {
                for (int j = 1; j <= cell_COL; j++) {
                    //printf("INDEX: %d, %d: COL:%d\n", i - 1, j - 1, cell_COL);
                    cell[i - 1][j - 1].population = rand() % 99;
                    cmd_argTer[i * cell_COL + j] = rand() % 5 + 70;
                }
            }
            ENDTIME = (double)clock() / CLOCKS_PER_SEC;
            printf("TIME : %f\n", ENDTIME - RUNTIME);
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
            RUNTIME = (double)clock() / CLOCKS_PER_SEC;
            
            /*int movingEntry[N + 1][M + 1];
            int movingVisited[N + 1][M + 1];
            char movingDirec[N + 1][M + 1];*/
            memset(movingEntry, 0, sizeof(movingEntry));
            memset(movingVisited, 0, sizeof(movingVisited));
            memset(movingDirec, 0, sizeof(movingDirec));
            for (int i = 1; i <= cell_ROW; i++) {
                for (int j = 1; j <= cell_COL; j++) {
                    if(movingVisited[i][j] == 0)
                    { 
                        movingVisited[i][j] = 1;
                        int hTemp = geth(cell, i, j);
                        int numCondition = 0;
                        numCondition += (hTemp < geth(cell, i - 1, j)) * 1; //N
                        numCondition += (hTemp < geth(cell, i + 1, j)) * 10; //S
                        numCondition += (hTemp < geth(cell, i, j + 1)) * 100; //W
                        numCondition += (hTemp < geth(cell, i, j - 1)) * 1000; //E
                        switch (transNumCondition(numCondition)) {
                        case 1:
                            movingDirec[i][j] = 'E';
                            movingEntry[i][j] = getp(cell, i, j);
                            break;
                        case 2:
                            movingDirec[i][j] = 'W';
                            movingEntry[i][j] = getp(cell, i, j);
                            break;
                        case 3:
                            movingDirec[i][j] = 'S';
                            movingEntry[i][j] = getp(cell, i, j);
                            break;
                        case 4:
                            movingDirec[i][j] = 'N';
                            movingEntry[i][j] = getp(cell, i, j);
                            break;
                        case 0:
                            movingDirec[i][j] = 'X';
                            movingDirec[i - 1][j + 1] = 'S';
                            movingDirec[i + 1][j] = 'N';
                            movingDirec[i][j + 1] = 'E';
                            movingDirec[i][j - 1] = 'W';
                            movingVisited[i - 1][j + 1] = 1;
                            movingVisited[i + 1][j] = 1;
                            movingVisited[i][j + 1] = 1;
                            movingVisited[i][j - 1] = 1;
                            break;
                        }

                    }
                    

                };
            }
            
           for (int i = 0; i < cell_ROW * cell_COL; i++) {
               /*if (cmd_argTer[i] == 'E')
                   move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 1, (i % cell_COL), movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                else if (cmd_argTer[i] == 'W')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 1, (i % cell_COL) + 2, movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                else if (cmd_argTer[i] == 'S')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 2, (i % cell_COL) + 1, movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                else if (cmd_argTer[i] == 'N')
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL), (i % cell_COL) + 1, movingEntry[i / cell_COL + 1][i % cell_COL + 1]);*/
               //int ROWW = (i / cell_COL) + 1, COLL = (i % cell_COL) + 1;
                switch (movingDirec[countToROW(i)][countToCOL(i)]) {
                case 'E':
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 1, (i % cell_COL), movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                    break;
                case 'W':
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 1, (i % cell_COL) + 2, movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                    break;
                case 'S':
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL) + 2, (i % cell_COL) + 1, movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                    break;
                case 'N':
                    move(cell, (i / cell_COL) + 1, (i % cell_COL) + 1, (i / cell_COL), (i % cell_COL) + 1, movingEntry[i / cell_COL + 1][i % cell_COL + 1]);
                    break;
                        
                }
              /* if (movingDirec[ROWW][COLL] == 'E')
                   move(cell, ROWW, COLL, ROWW, COLL - 1, movingEntry[ROWW][COLL]);
               else if (movingDirec[ROWW][COLL] == 'W')
                   move(cell, ROWW, COLL, ROWW, COLL + 1, movingEntry[ROWW][COLL]);
               else if (movingDirec[ROWW][COLL] == 'S')
                   move(cell, ROWW, COLL, ROWW + 1, COLL, movingEntry[ROWW][COLL]);
               else if (movingDirec[ROWW][COLL] == 'N')
                   move(cell, ROWW, COLL, ROWW - 1, COLL, movingEntry[ROWW][COLL]);
                   */

            }
            ENDTIME = (double)clock() / CLOCKS_PER_SEC;
            printf("TIME : %f\n", ENDTIME - RUNTIME);
        }
        else if (!strcmp(cmd_type, "scatter"))
        {
        }
        else if (!strcmp(cmd_type, "settle"))
        {            
            inputArgument1(cmd_arg, 1);
            RUNTIME = (double)clock() / CLOCKS_PER_SEC;
            int cell_rowSubpop[N];
            int maxPop = -1;
            int currentPop;
            int tempPop;
            int cityROW, cityCOL;
           /* for (int i = 1; i <= cell_ROW; i++) {
                cell_rowSubpop[i - 1] = 0;
            }*/
            memset(cell_rowSubpop, 0, sizeof(cell_rowSubpop));
            for (int i = 1; i <= cell_ROW; i++) {
                for (int j = 1; j <= 2 * cmd_arg[0] + 1; j++) {
                    cell_rowSubpop[i - 1] += getp(cell, i, j);
                }
            }
            
            tempPop = addsubArr(cell_rowSubpop, 1, 2 * cmd_arg[0] + 1);
            for (int j = 1; j <= (cell_COL - 2 * cmd_arg[0]); j++) {
                currentPop = tempPop;
                for (int i = 1; i <= (cell_ROW - 2 * cmd_arg[0]); i++) {
                    //printf("NOW i, j %d %d\n", i, j);
                    //printf("cpop and maxpop %d %d\n", currentPop, maxPop);
                    if (currentPop == maxPop) {
                        if (cityCOL > j + cmd_arg[0]) {
                            cityROW = i + cmd_arg[0];
                            cityCOL = j + cmd_arg[0];
                        }
                        else if (cityCOL == j + cmd_arg[0]) {
                            cityROW = cityROW < i + cmd_arg[0] ? cityROW : i + cmd_arg[0];
                            
                        }
                    }
                    else if (currentPop > maxPop) {
                        cityROW = i + cmd_arg[0];
                        cityCOL = j + cmd_arg[0];
                        maxPop = currentPop;
                    }
                        //printf("BEFORE else3run, argu is %d %d\n", i + 2 * cmd_arg[0] + 1, j);
                        if (!isOut(i + 2 * cmd_arg[0] + 1, j)) {
                           // printf("NOW 3rd else run\n");
                            currentPop -= cell_rowSubpop[i - 1];
                            currentPop += cell_rowSubpop[i + 2 * cmd_arg[0]];
                        
                            
                    }
                }
                if (!isOut(1, j + 2 * cmd_arg[0]) + 1) {
                    for (int i = 1; i <= cell_ROW; i++){
                        cell_rowSubpop[i - 1] -= getp(cell, i, j);
                        cell_rowSubpop[i - 1] += getp(cell, i, j + 2 * cmd_arg[0] + 1);
                        if (i <= 2 * cmd_arg[0] + 1)
                            tempPop = tempPop - getp(cell, i, j) + getp(cell, i, j + 2 * cmd_arg[0] + 1);
                    }
                }
            }
            printf("~!plzdelete~!%d %d and %d\n", cityROW, cityCOL, maxPop);
            ENDTIME = (double)clock() / CLOCKS_PER_SEC;
            printf("TIME : %f", ENDTIME - RUNTIME);
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
void move(cell_t cptr[N][M], int ROW_, int COL_, int toROW, int toCOL, int amount)
{
    if (isOut(toROW, toCOL) || isOut(ROW_, COL_)) return;
    else {
        cptr[ROW_ - 1][COL_ - 1].population -= amount;
        cptr[toROW - 1][toCOL - 1].population += amount;
    }
}
int addsubArr(int* subarr, int start, int end)
{
    int temp = 0;
    for (int i = start - 1; i < end; i++)
        temp += subarr[i];
    return temp;
}
int countToROW(int count)
{
    return (count / cell_COL) + 1;
}
int countToCOL(int count)
{
    return (count % cell_COL) + 1;
}
int ROWCOLtoCount(int ROW, int COL)
{
    return (ROW - 1) * cell_COL + (COL - 1);
}
int transNumCondition(int power10)
{
    if (power10 == 0) return 0;
    else if (power10 / 1000 != 0) return 1;
    else if (power10 / 100 != 0) return 2;
    else if (power10 / 10 != 0) return 3;
    else if (power10 / 1 != 0) return 4;
    else return 5;

        
}