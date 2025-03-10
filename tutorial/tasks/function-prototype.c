#include <stdio.h>

void printaTimes(char[], int); // Function prototype

int main()
{

    printaTimes("test", 10);

    return 0;
}

void printaTimes(char str[], int times)
{
    for (int i = 0; i < times; i++)
    {
        printf("%s\n", str);
    }
}