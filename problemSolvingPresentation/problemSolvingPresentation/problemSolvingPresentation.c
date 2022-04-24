#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int factorial(int n);
char transferNum(int n);
char* getAction(int n, int k, char* front);
char* getPermutation(int n, int k);

int visited[10] = { 0 };

int factorial(int n)
{
    if (n == 0 || n == 1) return 1;
    else return n * factorial(n - 1);
}
char transferNum(int n) 
{
    int result = n;
    for (int i = 1; i <= 9; i++) {
        if (visited[i] == 1 && result >= i) {
            result++;
        }
    }
    visited[result] = 1;
    return result + '0';

}
char* getAction(int n, int k, char* front)
{
    if (n == 0) {
        return front;
    }
    if (n > 0) {
        int frontNumber_temp;
        frontNumber_temp = ((k - 1) / factorial(n - 1)) + 1;
        char frontNumber = transferNum(frontNumber_temp);
        strncat(front, &frontNumber, 1);
        return getAction(n - 1, (k - 1) % factorial(n - 1) + 1, front);
    }
    return NULL;
}

char* getPermutation(int n, int k) {
    char* front = (char*)(malloc(sizeof(char) * 10));
    memset(visited, 0, sizeof(visited));
    front[0] = '\0';
    getAction(n, k, front);
    return front;
}


int main()
{
    printf("%s\n", getPermutation(5, 47));
}