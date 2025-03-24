#include <stdio.h>
#include <string.h>

int main()
{

    char a[] = "AAAAA";
    char b[] = "BBBBB";

    char temp[10];

    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);

    printf("%s\n", a);
    printf("%s\n", b);

    return 0;
}
