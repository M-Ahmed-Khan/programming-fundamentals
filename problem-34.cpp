#include <iostream>
#include <string>
/* Creates a "Person" class with attributes "name" and "age",
implements a derived class "Employee" that inherits from "Person"
and has an additional attribute "salary" and displays the employee’s
information using a method */

using namespace std;

class Person
{
public:
    string name;
    int age;
};

class Employee : public Person
{
public:
    int salary;

    Employee(string name, int age, int salary)
    {
        this->name = name;
        this->age = age;
        this->salary = salary;
    }

    void displayEmployee()
    {
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nSalary: " << salary << endl;
    }
};

int main()
{
    Employee employee_1("Alex", 34, 24000);
    Employee employee_2("James", 40, 30000);
    Employee employee_3("David", 59, 47000);

    cout << "\nEmployee 1: ";
    employee_1.displayEmployee();

    cout << "\nEmployee 2: ";
    employee_2.displayEmployee();

    cout << "\nEmployee 3: ";
    employee_3.displayEmployee();

    return 0;
}