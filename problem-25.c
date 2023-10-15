#include <stdio.h>
// Takes 10 numbers from user in array and sorts them(using bubble sort)

int main()
{
    const int arrayLength = 10;
    int numbers[arrayLength];
    int temp;

    // Taking input in the numbers array
    for (int i = 0; i < arrayLength; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    // Looping through each element of the numbers array
    for (int i = 0; i < arrayLength - 1; i++)
    {
        // Looping through each element for every element in the array,
        // decreasing by 1 each time because in bubble sort the array
        // gets sorted towards the end first so we know that the end
        // part is already sorted
        for (int j = 0; j < arrayLength - 1 - i; j++)
        {
            if (numbers[j] > numbers[j + 1])
            {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // Printing the numbers array after it has been sorted
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d\t", numbers[i]);
    }

    return 0;
}