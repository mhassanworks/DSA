// Program to assign data to members of a structure variable

#include <iostream>
using namespace std;

struct Person
{
    string name;
    int age;
    float salary;
};

int main()
{
    Person p1;
    
    cout << "Enter full name: ";
    getline(cin, p1.name);
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "Enter salary: ";
    cin >> p1.salary;

    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout << "Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary;

    return 0;
}
