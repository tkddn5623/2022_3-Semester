#include <stdio.h>  // 2021313504 정상우
#include <stdlib.h> // Lab Assignment #6
#include <time.h>

int compare_large(int largest, int x)
{
    if (largest > x)
        return largest;
    else
        return x;
}

int compare_small(int smallest, int x)
{
    if (smallest < x)
        return smallest;
    else
        return x;
}

int main(void)
{
    srand(time(NULL));
    int integers[10][8];
    int largest = 10;
    int smallest = 100;
    int sum = 0;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 8; ++j) {
            integers[i][j] = (rand() % 91) + 10;
            largest = compare_large(largest, integers[i][j]);
            smallest = compare_small(smallest, integers[i][j]);
            printf("%d ", integers[i][j]);
            sum += integers[i][j];
        }
        printf("\n");
    }

    printf("\n\n");
    printf("The smallest number: %d\n", smallest);
    printf("The largest number:  %d\n", largest);
    printf("And average:         %f\n", (float)sum / 80); //implicit cast

    return 0;
}