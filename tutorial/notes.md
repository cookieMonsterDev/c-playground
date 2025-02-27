## Quick setup

All extensions already installed in profile , un all code via configured `tasks.json` that can be created `Terminal` -> `Configure tasks`.

## Data Types Table

| Data Type        | Size (bytes)        | Description                                              | Format Specifier  |
|------------------|---------------------|----------------------------------------------------------|-------------------|
| `char`           | 1                   | Stores a single character                                | `%c`              |
| `int`            | 4                   | Stores integers                                          | `%d` or `%i`      |
| `short`          | 2                   | Stores smaller integers                                  | `%hd`             |
| `long`           | 4 or 8              | Stores larger integers                                   | `%ld`             |
| `long long`      | 8                   | Stores very large integers                               | `%lld`            |
| `unsigned int`   | 4                   | Stores positive integers only                            | `%u`              |
| `float`          | 4                   | Stores floating-point numbers                            | `%f`              |
| `double`         | 8                   | Stores double-precision floating-point numbers           | `%lf`             |
| `long double`    | 10, 12, or 16       | Extended precision floating-point                        | `%Lf`             |
| `_Bool`          | 1                   | Stores `true` (1) or `false` (0) (Requires `<stdbool.h>`) | `%d`              |
| `void`           | 0                   | Represents absence of type (used for functions)         | N/A               |
| `enum`           | Varies              | Stores a set of named integer constants                  | `%d`              |
| `struct`         | Varies              | User-defined data type grouping variables                | N/A               |
| `union`          | Varies              | Stores different types in the same memory location       | N/A               |
| `int*` (Pointer) | 8 (on 64-bit)       | Stores memory addresses                                  | `%p`              |


## Variables initialization, declaration and output with format specifiers

```c
    // Variables initialization & declaration

    int x;      // variable declaration
    x = 10;     // variable initialization
    int y = 10; // variable declaration + initialization

    // Data types

    int age = 25;               // integer number
    float length = 184.5123456789;       // float number
    char symbol = 'C';          // single character (works only with single quotes)
    char str[] = "some string"; // string, all string are represented by array to string is basically an object
    _Bool is_cool = false;       // boolean (require <stdbool.h>)

    // Format specifiers

    printf("Your age %d, (integer number)\n", age);
    printf("Your length %f, (float number)\n", length);
    printf("Your length %.4f, (float number with precision)\n", length);
    printf("Your lang %c, (single character)\n", symbol);
    printf("Your string %s, (string)\n", str);
    printf("Your are %d, (boolean)\n", is_cool);
```

## User input

```c
    // Create an int and a char variable
    int myNum;
    char myChar;

    // Ask the user to type a number AND a character
    printf("Type a number AND a character and press enter: \n");

    // Get and save the number AND character the user types
    scanf("%d %c", &myNum, &myChar);

    // Print the number
    printf("Your number is: %d\n", myNum);

    // Print the character
    printf("Your character is: %c\n", myChar);
```

## Strings

## Arrays

```c

    // Default array usage
    int myNumbers[] = {25, 50, 75, 100};
    myNumbers[0] = 33;

    printf("%d", myNumbers[0]);

    // Array of strings
    char *arr[] = {"test-1", "test-2", "test-3"};

    // Matrix
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };

    // 2-D Array (important to predefined length of subarrays)
    int array[][3] = { {1, 4, 2}, {3, 6, 8} };
```