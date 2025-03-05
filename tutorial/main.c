#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int array1[] = {1, 2, 3};
    int array2[] = {4, 5, 6};

    int *ptr;

    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);

    ptr = malloc((n1 * sizeof(int) + (n2 * sizeof(int))));

    memcpy(ptr, array1, n1 * sizeof(int));

    memcpy(ptr + n1, array2, n2 * sizeof(int));

    for (int i = 0; i < (n1 + n2); i++)
    {
        printf("%d ", ptr[i]);
    };

    free(ptr);

    return 0;
}