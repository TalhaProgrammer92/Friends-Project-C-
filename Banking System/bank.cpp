#include <iostream>

using namespace std;

//? Global variables
int accountNumber = 0;

////////////////////////
//? Account class
////////////////////////
class Account
{
    //* Attributes
    int id;
    double balance;
    string name;

public:
    //* Constructor
    Account(string name, double balance)
    {
        this->name = name;
        this->balance = balance;
        this->id = ++accountNumber;
    }

    //* Getters
    int getId() { return id; }
    double getBalance() { return balance; }
    string getName() { return name; }

    //* Methods
    void deposit(double amount);
    double withdraw(double amount);
    void display();
};


////////////////////////
//? Main Function
////////////////////////
int main()
{
    //* Creating objects of Account class
    Account account1("Talha Ahmad", 15000), account2("Areeb", 25000);

    //* Diposit (to account1) and withdraw (from account2) cash
    account1.deposit(account2.withdraw(5000));
    
    //* Displaying account's information
    account1.display();
    account2.display();
}