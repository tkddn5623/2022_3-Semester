#include <stdio.h>
#include <inttypes.h>

typedef __int128 int128_t;
int main()
{
    int128_t val;
    int128_t* dest = &val;
    *dest = 0x1234567890abcdef;
    printf("0x%llx\n", (long long)* (dest+1));

}
