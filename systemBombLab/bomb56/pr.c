#include <stdio.h>

int f1(int x){
    printf("f is called");
    return x + 9;
}
int f2(int x){
    printf("[%d]\n", x);
}
int main()
{
    int a;
    int b;
    int c;
    a = 5;
    b = a * 4;
    c = f1(a);
    printf("[%d]\n", a);
    f2(b);
    printf("[%d]\n", c);
}