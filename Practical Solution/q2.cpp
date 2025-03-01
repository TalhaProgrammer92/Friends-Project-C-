#include <iostream>

using namespace std;

/*
? Queston:

Write a program in C++ that contain:
1. "Address" class having attributes city and country. It also have a parameterized constructor to initialize these attributes.
2. "Person" class having attributes name and address. It also have a parameterized constructor to initialize these attributes.
3. "Student" class which is derived from Person class and having attributes , program and fee. It also have a parameterized constructor to initialize these attributes.
4. "Staff" class which is derived from Person class and have attribute pay. It also have a parameterized constructor to initialize this attribute.
5. Main function that do:
    a. Create an object of Student class and Staff class.
    b. Get data of student and staff from user.
    c. Display data of student and staff.
*/

//* "Address" class having attributes city and country. It also have a parameterized constructor to initialize these attributes.
class Address
{
public:
    string city, country;
    Address(string city, string country)
    {
        this->city = city;
        this->country = country;
    }
};

//* "Person" class having attributes name and address. It also have a parameterized constructor to initialize these attributes.
class Person
{
public:
    string name;
    Address* address;
    Person(string name, Address &address)
    {
        this->name = name;
        this->address = &address;
    }
};

//* "Student" class which is derived from Person class and having attributes , program and fee. It also have a parameterized constructor to initialize these attributes.
class Student : public Person
{
public:
    string program;
    double fee;
    Student(string name, Address &address, string program, double fee) : Person(name, address)
    {
        this->program = program;
        this->fee = fee;
    }
};

//* "Staff" class which is derived from Person class and have attribute pay. It also have a parameterized constructor to initialize this attribute.
class Staff : public Person
{
public:
    double pay;
    Staff(string name, Address &address, double pay) : Person(name, address)
    {
        this->pay = pay;
    }
};

int main()
{
    //* Create an object of Student class and Staff class.
    Student* student;
    Staff* staff;
    string name, city, country, program;
    double fee, pay;

    //* Get data of student from user.
    cout << "Enter Student Information\n";
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter country: ";
    cin >> country;
    cout << "Enter program: ";
    cin >> program;
    cout << "Enter fee: ";
    cin >> fee;

    Address student_address(city, country);
    student = new Student(name, student_address, program, fee);

    //* Get data of staff from user.
    cout << "\nEnter Staff Information\n";
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter city: ";
    cin >> city;
    cout << "Enter country: ";
    cin >> country;
    cout << "Enter pay: ";
    cin >> pay;

    Address staff_address(city, country);
    staff = new Staff(name, staff_address, pay);

    //* Display data of student and staff.
    cout << "\nStudent Information\n";
    cout << "Name: " << student->name << endl;
    cout << "Address: " << student->address->city << ", " << student->address->country << endl;
    cout << "Program: " << student->program << endl;
    cout << "Fee: " << student->fee << endl;

    cout << "\nStaff Information\n";
    cout << "Name: " << staff->name << endl;
    cout << "Address: " << staff->address->city << ", " << staff->address->country << endl;
    cout << "Pay: " << staff->pay << endl;
}
