#include <stdio.h>
#include <stdbool.h>

int main()
{
    // Variables initialization & declaration

    int x;      // variable declaration
    x = 10;     // variable initialization
    int y = 10; // variable declaration + initialization

    // Data types

    int age = 25;               // integer number
    float length = 184.5;       // float number
    char symbol = 'C';          // single character (works only with single quotes)
    char str[] = "some string"; // string, all string are represented by array to string is basically an object
    _Bool is_cool = false;       // boolean (require <stdbool.h>)

    // Format specifiers

    printf("Your age %d, (integer number)\n", age);
    printf("Your length %f, (float number)\n", length);
    printf("Your lang %c, (single character)\n", symbol);
    printf("Your string %s, (string)\n", str);
    printf("Your are %d, (boolean)\n", is_cool);

    return 0;
}