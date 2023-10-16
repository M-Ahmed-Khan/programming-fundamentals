#include <iostream>
#include <string>
// Creates a Student class with attributes "name", "age", and "grade" and a method for displaying student information.

using namespace std;

class Student
{
public:
    string name;
    int age;
    char grade;

    Student(string name, int age, char grade)
    {
        this->name = name;
        this->age = age;
        this->grade = grade;
    }

    void displayStdudent()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Grade: " << grade << endl;
    }
};

int main()
{
    string names[3];
    int ages[3];
    char grades[3];

    cout << "Enter student information: \n";

    for (int i = 0; i < 3; i++)
    {
        cout << "\nStudent " << i + 1 << ": \n";
        cout << "Name: ";
        cin >> names[i];
        cout << "Age: ";
        cin >> ages[i];
        cout << "Grade: ";
        cin >> grades[i];
    }

    Student student_1(names[0], ages[0], grades[0]);
    Student student_2(names[1], ages[1], grades[1]);
    Student student_3(names[2], ages[2], grades[2]);

    cout << "Student 1:\n";
    student_1.displayStdudent();
    cout << endl;

    cout << "Student 2:\n";
    student_2.displayStdudent();
    cout << endl;

    cout << "Student 3:\n";
    student_3.displayStdudent();
    cout << endl;

    return 0;
}