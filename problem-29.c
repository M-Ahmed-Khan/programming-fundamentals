#include <stdio.h>
#include <stdlib.h>
// Uses structures to show names, roll numbers and percentages of 5 students but stores and reads content from text file

typedef struct
{
    char *name;
    int roll_number;
    float percentage;
} Student;

int main()
{
    FILE *file;
    const int numberOfStudents = 5;
    Student student_data[numberOfStudents];

    printf("Enter data of 5 students:\n\n");

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("\nStudent %d\n", i + 1);

        printf("Name: ");
        scanf("%s", &student_data[i].name);

        printf("Roll Number: ");
        scanf("%d", &student_data[i].roll_number);

        printf("Percentage: ");
        scanf("%f", &student_data[i].percentage);
    }

    file = fopen("text-files/student-data.txt", "w");

    for (int i = 0; i < numberOfStudents; i++)
    {
        fprintf(file, "%s\n%d\n%.1f\n", student_data[i].name, student_data[i].roll_number, student_data[i].percentage);
    }

    fclose(file);

    file = fopen("text-files/student-data.txt", "r");

    if (file == NULL)
    {
        printf("Failed to open file");
        return 1;
    }

    Student students[numberOfStudents];

    const int maxNameLength = 50;
    for (int i = 0; i < numberOfStudents; i++)
    {
        students[i].name = malloc(maxNameLength * sizeof(char));
        fscanf(file, "%s\n%d\n%f", students[i].name, &(students[i].roll_number), &(students[i].percentage));
    }

    printf("Name\tRoll no\t%%\n");

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].roll_number, students[i].percentage);
    }

    fclose(file);

    return 0;
}