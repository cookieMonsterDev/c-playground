#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fillArray()
{
    int arrayLen;
    double *array;

    printf("Enter size of array: \n");
    scanf("%i", &arrayLen);

    array = malloc(arrayLen * sizeof(double));

    if (array == NULL)
    {
        printf("Allocation went wrong\n");
        return 0;
    };

    // Fill the array
    for (int i = 0; i < arrayLen; i++)
    {
        printf("Enter (%d)n item: \n", i);
        scanf("%lf", &array[i]);
    };

    // Print the array
    for (int i = 0; i < arrayLen; i++)
    {
        printf("%lf ", array[i]);
    };

    printf("\nDone\n");
    free(array);

    return 0;
}

int concatArray()
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

int main()
{

    fillArray();
    concatArray();

    return 0;
}