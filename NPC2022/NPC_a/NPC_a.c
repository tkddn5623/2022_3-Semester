#include <stdio.h>

typedef struct student
{
    int room;
    int score[50];
};

void swap(int* xPtr, int* yPtr);
int isSwap(int left, int right);
void setGood(int room1, int room2, int B, int* GDptr, int* mGptr, int* tGptr);

int main()
{
    int people, A, B, week;
    int input;
    struct student Student[100];

    scanf("%d %d %d %d", &people, &A, &B, &week);
    
    for (int i = 0; i < people; i++)  
        for (int j = 0; j < week - 1; j++) 
            Student[i].score[j] = 0;
        
    for (int i = 0; i < week - 1; i++) { 
        for (int j = 0; j < people; j++) {
            scanf("%d", &input);
            Student[j].score[i] += input;
        }
        for (int j = 0; j < people; j++) { 
            scanf("%d", &input);
            Student[j].score[i] -= input;
        }
    }
    
    int GoodDay = 0, maxGood = 0, tempGood = 0;
    int roomHost[100];
    
    for (int i = 0; i < people; i++) {
        Student[i].room = i; 
        roomHost[i] = i; 
    }
    
    for (int j = 0; j < week; j++) {
        setGood(Student[0].room, Student[A - 1].room, B, &GoodDay, &maxGood, &tempGood);
        if (j == week - 1)
            break;
        for (int i = 0; i < people - 1; i++)
            if (isSwap(Student[roomHost[i]].score[j], Student[roomHost[i + 1]].score[j])) {
                Student[roomHost[i]].score[j] += 2;
                Student[roomHost[i + 1]].score[j] -= 2;

                swap(&Student[roomHost[i]].room, &Student[roomHost[i + 1]].room);
                swap(&roomHost[i], &roomHost[i + 1]);
            }
    }
    printf("%d %d", GoodDay, maxGood);
}

void swap(int* xPtr, int* yPtr)
{
    int temp;
    temp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = temp;
}
int isSwap(int left, int right)
{
    if (left >= 0 && right >= 0) {
        if (right - left >= 2)
            return 1;
        else return 0;
    }
    else if (left >= 0 && right < 0)
        return 0;
    else if (left < 0 && right >= 0)
        return 1;
    else {
        if (right - left >= 4)
            return 1;
        else return 0;
    }
}
void setGood(int room1, int room2, int B, int* GDptr, int* mGptr, int* tGptr)
{
    if (room2 - room1 <= B) {
        (*GDptr)++, (*tGptr)++;
        if (*tGptr > *mGptr)
            (*mGptr) = (*tGptr);
    }
    else
        *tGptr = 0;
}