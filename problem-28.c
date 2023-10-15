#include <stdio.h>
// Uses structures to show names, roll numbers and percentages of 5 students

typedef struct
{
    char *name;
    int roll_number;
    float percentage;
} Student;

int main()
{
    const int numberOfStudents = 5;
    Student students[numberOfStudents];

    printf("Enter data of 5 students:\n\n");

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf("%s", &students[i].name);

        printf("Roll Number: ");
        scanf("%d", &students[i].roll_number);

        printf("Percentage: ");
        scanf("%f", &students[i].percentage);
    }

    printf("Name\tRoll no\t%%\n");

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("%s\t %d\t%.1f\n", students[i].name, students[i].roll_number, students[i].percentage);
    }

    return 0;
}
