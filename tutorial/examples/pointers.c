#include <stdio.h>

/**
 * Call by Reference
 *
 * if we need to change some value with a function,
 * it is common to use pointer to this value,
 * cause in case we pass raw value in the function,
 * this function will change value only locally
 *
 * usage:
 *
 * int a = 1;
 *
 * callByReference(&a);
 */
void callByReference(int *value)
{
    *value += 1;
}

/**
 * Pointers in Arrays
 *
 * When array passed to the function, it is passed as
 * pointer for the first element in the array, that is why
 *
 * sum(int array[]) and sum(int *array) is same, and have call by reference
 *
 * also that is why length should be caulculated outside and passed as value
 */
int sum(int *array, int length)
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum;
};

void doubleEach(int *array, int length)
{
    for (int i = 0; i < length; i++)
    {
        array[i] *= 2;
    }
}

/**
 * Pointers in Character Arrays
 * 
 * 1) The character arrays should have length sum(character) + 1, cause last be EOF;
 * 
 */


 
///////////////////////////////////////////////////

int main()
{
    int array[] = {1, 2, 3, 4, 5};

    printf("This is: %d\n", sum(array, 5));

    doubleEach(array, 5);

    printf("The last is %d", array[4]);

    return 0;
}