#include <stdio.h>
// Uses structures to show names, roll numbers and percentages of 5 students but stores and reads content from binary file

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

    printf("Enter  of 5 students:\n\n");

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

    file = fopen("binary-files/student-.bin", "wb");

    fwrite(student_data, sizeof(Student), numberOfStudents, file);

    fclose(file);

    file = fopen("binary-files/student-data.bin", "rb");
    if (file == NULL)
    {
        printf("Failed to open the file for reading.\n");
        return 1;
    }

    Student students[numberOfStudents];

    fread(students, sizeof(Student), numberOfStudents, file);

    printf("Name\tRoll no\t%%\n");

    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("%s\t%d\t%.1f\n", students[i].name, students[i].roll_number, students[i].percentage);
    }

    fclose(file);

    return 0;
}