#include <iostream>

using namespace std;

// ? Global variables
int accountNumber = 0;

////////////////////////
//? Account class
////////////////////////
class Account {
    //* Attributes
    int id;
    double balance;
    string name;

    public:
    //* Constructor
    Account(string name, double balance) {
        this->name = name;
        this->balance = balance;
        this->id = accountNumber++;
    }
};

int main()
{
    
}
