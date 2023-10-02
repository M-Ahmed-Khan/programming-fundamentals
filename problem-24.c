#include <stdio.h>
#include <stdlib.h>
/* Creates two dynamic 2D integer arrays, takes input from
user in both 2D arrays and applies matrix multiplication
then displays the result */

int main()
{
    int **matrix_1;
    int numberOfRows_1, numberOfColumns_1;

    printf("Enter the number of rows of first matrix: ");
    scanf("%d", &numberOfRows_1);
    printf("Enter the number of columns of first matrix: ");
    scanf("%d", &numberOfColumns_1);

    matrix_1 = (int **)malloc(numberOfRows_1 * sizeof(int *));

    for (int i = 0; i < numberOfRows_1; i++)
    {
        matrix_1[i] = malloc(numberOfColumns_1 * sizeof(int));
    }

    for (int i = 0; i < numberOfRows_1; i++)
    {
        for (int j = 0; j < numberOfColumns_1; j++)
        {
            printf("Enter element %d of row %d: ", j + 1, i + 1);
            scanf("%d", &matrix_1[i][j]);
        }
    }

    printf("\n");

    int **matrix_2;
    int numberOfRows_2, numberOfColumns_2;

    printf("Enter the number of rows of second matrix: ");
    scanf("%d", &numberOfRows_2);
    printf("Enter the number of columns of second matrix: ");
    scanf("%d", &numberOfColumns_2);

    matrix_2 = (int **)malloc(numberOfRows_2 * sizeof(int *));

    for (int i = 0; i < numberOfRows_2; i++)
    {
        matrix_2[i] = malloc(numberOfColumns_2 * sizeof(int));
    }

    for (int i = 0; i < numberOfRows_2; i++)
    {
        for (int j = 0; j < numberOfColumns_2; j++)
        {
            printf("Enter element %d of row %d: ", j + 1, i + 1);
            scanf("%d", &matrix_2[i][j]);
        }
    }

    int **result;

    result = (int **)malloc(numberOfRows_1 * sizeof(int *));

    for (int i = 0; i < numberOfRows_1; i++)
    {
        result[i] = malloc(numberOfColumns_2 * sizeof(int));
    }

    if (numberOfColumns_1 != numberOfRows_2)
    {
        printf("Multiplication is not possible");
    }
    else
    {
        for (int i = 0; i < numberOfRows_1; i++)
        {
            for (int j = 0; j < numberOfColumns_2; j++)
            {
                result[i][j] = 0;
                for (int k = 0; k < numberOfColumns_1; k++)
                {
                    result[i][j] += matrix_1[i][k] * matrix_2[k][j];
                }
            }
        }
    }

    printf("Their product is: \n");

    for (int i = 0; i < numberOfRows_1; i++)
    {
        for (int j = 0; j < numberOfColumns_2; j++)
        {
            if (result[i][j] >= 10 || result[i][j] < 0)
            {
                printf("%d  ", result[i][j]);
            }

            else if (result[i][j] <= -10)
            {
                printf("%d ", result[i][j]);
            }

            else
            {
                printf(" %d  ", result[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < numberOfRows_1; i++)
    {
        free(matrix_1[i]);
    }
    free(matrix_1);

    for (int i = 0; i < numberOfRows_2; i++)
    {
        free(matrix_2[i]);
    }
    free(matrix_2);

    for (int i = 0; i < numberOfRows_1; i++)
    {
        free(result[i]);
    }
    free(result);

    return 0;
}