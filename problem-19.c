#include <stdio.h>

// Takes 10 inputs from user and computes highest, lowest and average

int main()
{
    const int arrayLength = 10;
    int numbers[arrayLength];

    for (int i = 0; i < 10; i++)
    {
        printf("Enter a number(Element #%d): ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // ------------Highest------------

    int greatest = numbers[0];

    for (int i = 0; i < arrayLength; i++)
    {
        if (greatest < numbers[i])
        {
            greatest = numbers[i];
        }
    }

    printf("The greatest number is %d\n", greatest);

    // ------------Lowest------------

    int lowest = numbers[0];

    for (int i = 0; i < arrayLength; i++)
    {
        if (lowest > numbers[i])
        {
            lowest = numbers[i];
        }
    }

    printf("The lowest number is %d\n", lowest);

    // ------------Average------------
    
    int sum = 0;
    for (int i = 0; i < arrayLength; i++)
    {
        sum += numbers[i];
    }

    printf("The average is %d", sum / 10);

    return 0;
}