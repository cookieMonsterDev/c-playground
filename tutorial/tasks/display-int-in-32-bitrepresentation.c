#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print32(unsigned int num)
{
    printf("The %u in 32-bit representation is: ", num);
    for (int i = 31; i >= 0; i--)
    {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int count1(unsigned int num)
{
    int sum = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (((num >> i) & 1) == 1)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    char choice;
    unsigned int inputInt;
    unsigned int bitPosition;

    do
    {
        printf("Enter a number from 0 to 256: ");
        scanf("%u", &inputInt);

        print32(inputInt);

        int sum = count1(inputInt);
        printf("The number has %d set bit(s)\n", sum);

        printf("Enter bit position to toggle (0 to 31): ");
        scanf("%u", &bitPosition);

        // Toggle the specified bit
        inputInt = inputInt ^ (1 << bitPosition);

        print32(inputInt);
        sum = count1(inputInt);
        printf("After toggling, the number has %d set bit(s)\n", sum);

        printf("Do you want to toggle another bit? (y/n): ");
        scanf("%c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}