#include <stdio.h>

typedef struct student_t_
{
	char name[10];
} student_t;
int main()
{
	student_t a = { "sangwoo" };
	student_t b = { "wusang" };
	a = b;
	//a.name = b.name;
	printf("%s", a.name);
}