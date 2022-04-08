#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 5000
#define M 5000
#pragma warning(disable : 4996)

typedef struct cell_t_ {
    char terrian;
    unsigned int height;
    unsigned int population;

} cell_t;

void cellInit(cell_t cPtr[N + 2][M + 2], int ROW_, int COL_);
int isOut(int ROW_, int COL_);
char gett(cell_t cptr[N + 2][M + 2], int ROW_, int COL_);
unsigned int geth(cell_t cptr[N + 2][M + 2], int ROW_, int COL_);
unsigned int getp(cell_t cptr[N + 2][M + 2], int ROW_, int COL_);
void inputArgument1(int* argPtr, int length);
void inputArgument2(char* argTerPtr);
int area(const int* argPtr);
int addsubArr(int* subarr, int start, int end);
int getDenominator(int ROW_, int COL_);


cell_t cell[N + 2][M + 2];;
int moveAmountQueue[N + 2][M + 2];
int extendedCellPop[3 * N + 2][3 * M + 2];
int rowVector[N];
char cmd_argTer[N * M + 10];
int cmd_argNum[N * M + 10];
int cell_rowSubpop[N];

int cell_ROW, cell_COL;

int main()
{
    char cmd_type[11];
    int cmd_arg[4];
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
            for (int i = 1; i <= cell_ROW; i++) {
                for (int j = 1; j <= cell_COL; j++) {
                    int temprand = rand();
                    cell[i][j].height = temprand % 10;
                    cell[i][j].population = rand() % 51;
                    switch (temprand % 3) {
                    case 0:
                        cell[i][j].terrian = 'P';
                        break;
                    case 1:
                        cell[i][j].terrian = 'M';
                        break;
                    }
                }
            }
        }
        else if (!strcmp(cmd_type, "sett"))
        {
            inputArgument1(cmd_arg, 4);
            inputArgument2(cmd_argTer);
            count = 0;
            for (int i = cmd_arg[0]; i <= cmd_arg[2]; i++) 
                for (int j = cmd_arg[1]; j <= cmd_arg[3]; j++) 
                    cell[i][j].terrian = cmd_argTer[count++];
        }
        else if (!strcmp(cmd_type, "seth"))
        {
            inputArgument1(cmd_arg, 4);
            inputArgument1(cmd_argNum, area(cmd_arg));
            count = 0;
            for (int i = cmd_arg[0]; i <= cmd_arg[2]; i++)
                for (int j = cmd_arg[1]; j <= cmd_arg[3]; j++)
                    cell[i][j].height = cmd_argNum[count++];
        }
        else if (!strcmp(cmd_type, "setp"))
        {
            inputArgument1(cmd_arg, 4);
            inputArgument1(cmd_argNum, area(cmd_arg));
            count = 0;
            for (int i = cmd_arg[0]; i <= cmd_arg[2]; i++)
                for (int j = cmd_arg[1]; j <= cmd_arg[3]; j++)
                    cell[i][j].population = cmd_argNum[count++];
        }
        else if (!strcmp(cmd_type, "climb"))
        {
            count = 0;
            memset(moveAmountQueue, 0, sizeof(moveAmountQueue));
            for (int i = 1; i <= cell_ROW; i++) {
                for (int j = 1; j <= cell_COL; j++) {
                    int dest_ROW = i, dest_COL = j;
                    int heightNow = cell[i][j].height;

                    if (heightNow < cell[i - 1][j].height)//N
                        dest_ROW = i - 1, dest_COL = j;
                    if (heightNow < cell[i + 1][j].height)//S
                        dest_ROW = i + 1, dest_COL = j;
                    if (heightNow < cell[i][j + 1].height)//W
                        dest_ROW = i, dest_COL = j + 1;
                    if (heightNow < cell[i][j - 1].height)//E
                        dest_ROW = i, dest_COL = j - 1;

                    moveAmountQueue[dest_ROW][dest_COL] += cell[i][j].population;
                    moveAmountQueue[i][j] -= cell[i][j].population;
                }
            }
            for (int i = 1; i <= cell_ROW; i++) 
                for (int j = 1; j <= cell_COL; j++) 
                    cell[i][j].population += moveAmountQueue[i][j];
        }
        else if (!strcmp(cmd_type, "scatter"))
        {
            count = 0;
            int denominator;
            memset(moveAmountQueue, 0, sizeof(moveAmountQueue));
            if (cell_ROW == 1 && cell_COL == 1) continue;
            for (int i = 1; i <= cell_ROW; i++) {
                for (int j = 1; j <= cell_COL; j++) {
                    denominator = 4;
                    if (i == 1 || i == cell_ROW)
                        denominator--;
                    if (j == 1 || j == cell_COL)
                        denominator--;
                    if (cell_ROW == 1 || cell_COL == 1)
                        denominator--;
                    moveAmountQueue[i + 1][j] += cell[i][j].population / denominator;
                    moveAmountQueue[i - 1][j] += cell[i][j].population / denominator;
                    moveAmountQueue[i][j + 1] += cell[i][j].population / denominator;
                    moveAmountQueue[i][j - 1] += cell[i][j].population / denominator;
                    moveAmountQueue[i][j] -= (cell[i][j].population - cell[i][j].population % denominator);
                }
            }
            for (int i = 1; i <= cell_ROW; i++)
                for (int j = 1; j <= cell_COL; j++)
                    cell[i][j].population += moveAmountQueue[i][j];
        }
        else if (!strcmp(cmd_type, "settle"))
        {
        inputArgument1(cmd_arg, 1);
        int cell_rowSubpop[N];
        int maxPop = -1;
        int currentPop;
        int tempPop;
        int cityROW, cityCOL;

        memset(cell_rowSubpop, 0, sizeof(cell_rowSubpop));
        for (int i = 1; i <= cell_ROW; i++) {
            for (int j = 1; j <= 2 * cmd_arg[0] + 1; j++) {
                cell_rowSubpop[i - 1] += cell[i][j].population;
            }
        }

        tempPop = addsubArr(cell_rowSubpop, 1, 2 * cmd_arg[0] + 1);
        for (int j = 1; j <= (cell_COL - 2 * cmd_arg[0]); j++) {
            currentPop = tempPop;
            for (int i = 1; i <= (cell_ROW - 2 * cmd_arg[0]); i++) {
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
                for (int i = 1; i <= cell_ROW; i++) {
                    cell_rowSubpop[i - 1] -= cell[i][j].population;
                    cell_rowSubpop[i - 1] += cell[i][j + 2 * cmd_arg[0] + 1].population;
                    if (i <= 2 * cmd_arg[0] + 1)
                        tempPop = tempPop - cell[i][j].population + cell[i][j + 2 * cmd_arg[0] + 1].population;
                }
            }
        }
        for (int i = cityROW - cmd_arg[0]; i <= cityROW + cmd_arg[0]; i++)
            for (int j = cityCOL - cmd_arg[0]; j <= cityCOL + cmd_arg[0]; j++)
                cell[i][j].population = 0;
        cell[cityROW][cityCOL].population = maxPop;
        cell[cityROW][cityCOL].terrian = 'C';
        }
        else if (!strcmp(cmd_type, "print"))
        {
            inputArgument1(cmd_arg, 2);
            printf("%c %d %d\n",
                cell[cmd_arg[0]][cmd_arg[1]].terrian,
                cell[cmd_arg[0]][cmd_arg[1]].population,
                cell[cmd_arg[0]][cmd_arg[1]].height);
        }
        else if (!strcmp(cmd_type, "count"))
        {
            int popP = 0, popM = 0, popC = 0;
            for (int i = 1; i <= cell_ROW; i++)
                for (int j = 1; j <= cell_COL; j++) {
                    if (cell[i][j].terrian == 'P')
                        popP += cell[i][j].population;
                    else if (cell[i][j].terrian == 'M')
                        popM += cell[i][j].population;
                    else if (cell[i][j].terrian == 'C')
                        popC += cell[i][j].population;
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

void cellInit(cell_t cPtr[N + 2][M + 2], int ROW_, int COL_)
{
    for (int i = 0; i < N + 2; i++)
        for (int j = 0; j < M + 2; j++) {
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
char gett(cell_t cptr[N + 2][M + 2], int ROW_, int COL_) {
    if (isOut(ROW_, COL_))
        return 'X';
    else
        return cptr[ROW_][COL_].terrian;
}
unsigned int geth(cell_t cptr[N + 2][M + 2 ], int ROW_, int COL_) {
    if (isOut(ROW_, COL_))
        return 0;
    else
        return cptr[ROW_][COL_].height;
}
unsigned int getp(cell_t cptr[N + 2][M + 2], int ROW_, int COL_) {
    if (isOut(ROW_, COL_))
        return 0;
    else
        return cptr[ROW_][COL_].population;
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
int addsubArr(int* subarr, int start, int end)
{
    int temp = 0;
    for (int i = start - 1; i < end; i++)
        temp += subarr[i];
    return temp;
}
int getDenominator(int ROW_, int COL_)
{
    int denominator_ = 4;
    if (ROW_ == 1 || ROW_ == cell_ROW)
        denominator_--;
    if (COL_ == 1 || COL_ == cell_COL)
        denominator_--;
    if (cell_ROW == 1 || cell_COL == 1)
        denominator_--;
    return denominator_;
}