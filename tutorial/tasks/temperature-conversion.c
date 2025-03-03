#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct
{
    char unitFrom;
    char unitTo;
} TempConversionUnits;

typedef struct
{
    double originalTemp;
    double convertedTemp;
} Temps;

bool validateUnit(char unit)
{
    _Bool isValid = false;
    switch (unit)
    {
    case 'F':
        isValid = true;
        break;
    case 'C':
        isValid = true;
        break;
    case 'K':
        isValid = true;
        break;
    default:
        isValid = false;
    }
    return isValid;
}

TempConversionUnits getTempUnits()
{
    char unitFrom, unitTo;
    bool isValid = false;
    TempConversionUnits units;

    do
    {
        printf("\nEnter temperature unit [unitFrom, unitTo]. e.g. (F C): ");
        scanf(" %c %c", &units.unitFrom, &units.unitTo);

        units.unitTo = toupper(units.unitTo);
        units.unitFrom = toupper(units.unitFrom);

        bool isUnitToValid = validateUnit(units.unitTo);
        bool isUnitFromValid = validateUnit(units.unitFrom);

        if (!isUnitToValid)
        {
            printf("\nThe unitTo is invalid");
        };

        if (!isUnitFromValid)
        {
            printf("\nThe unitFrom is invalid");
        };

        isValid = isUnitToValid && isUnitFromValid;

    } while (!isValid);

    return units;
}

int main()
{
    Temps temps;
    TempConversionUnits units = getTempUnits();

    printf("\nEnter the temperature value: ");
    scanf("%lf", &temps.originalTemp);

    printf("%c %c", units.unitFrom, units.unitTo);

    if (units.unitFrom == 'C')
    {
        switch (units.unitTo)
        {
        case 'F':
            temps.convertedTemp = temps.originalTemp * (9.0 / 5.0) + 32;
            break;
        case 'K':
            temps.convertedTemp = temps.originalTemp + 273.15;
            break;
        default:
            break;
        }
    }
    else if (units.unitFrom == 'F')
    {
        switch (units.unitTo)
        {
        case 'C':
            temps.convertedTemp = (temps.originalTemp - 32) * (5.0 / 9.0);
            break;
        case 'K':
            temps.convertedTemp = (temps.originalTemp - 32) * (5.0 / 9.0) + 273.15;
            break;
        default:
            break;
        }
    }
    else if (units.unitFrom == 'K')
    {
        switch (units.unitTo)
        {
        case 'C':
            temps.convertedTemp = temps.originalTemp - 273.15;
            break;
        case 'F':
            temps.convertedTemp = (temps.originalTemp - 273.15) * (9.0 / 5.0) + 32;
            break;
        default:
            break;
        }
    }

    printf("\nThe %.1lf(%c) is %.1lf(%c)\n", temps.originalTemp, units.unitFrom, temps.convertedTemp, units.unitTo);

    return 0;
};