#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)

typedef struct cell_t_ {
    char terrian;
    unsigned int height;
    unsigned int population;

} cell_t;

int main()
{
    char cmd_type[11];

    while (1)
    {
        scanf("%s", cmd_type);

        if (!strcmp(cmd_type, "new"))
        {
        }
        else if (!strcmp(cmd_type, "sett"))
        {
        }
        else if (!strcmp(cmd_type, "seth"))
        {
        }
        else if (!strcmp(cmd_type, "setp"))
        {
        }
        else if (!strcmp(cmd_type, "climb"))
        {
        }
        else if (!strcmp(cmd_type, "scatter"))
        {
        }
        else if (!strcmp(cmd_type, "settle"))
        {
        }
        else if (!strcmp(cmd_type, "print"))
        {
        }
        else if (!strcmp(cmd_type, "count"))
        {
        }
        else if (!strcmp(cmd_type, "exit"))
        {
            break;
        }
    }

    return 0;
}