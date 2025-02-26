#include <iostream>
#include <vector>

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
//? Bank class
////////////////////////
class Bank
{
    //* Attributes
    vector<Account> accounts;

public:
    //* Methods
    void createAccount();
    void displayAllAccounts();
    void transfer(Account from, Account to, double amount);
    Account getAccount(int id);
};

////////////////////////
//? Main Function
////////////////////////
int main()
{
    //* Creating objects of Account class
    Bank bank;

    //* Local variables
    int choice;

    while (true)
    {
        cout << "1- Create account, 2- Display all accounts, 3- Open Existing Account" << endl;
        cin >> choice;

        //* Local variable for account id
        int id;

        //* Declare account variable
        Account account("", 0);

        //* Switch case for user choice
        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.displayAllAccounts();
            break;
        case 3:
            cout << "Enter account id: ";
            cin >> id;
            account = bank.getAccount(id);
            account.display();
            break;
        default:
            break;
        }
    }
}

////////////////////////
//? Account class
////////////////////////
//* Method - Deposit cash to account
void Account::deposit(double amount)
{
    balance += amount;
}

//* Method - Withdraw cash from account
double Account::withdraw(double amount)
{
    if (balance - amount < 0)
    {
        cout << "Insufficient balance" << endl;
        return 0;
    }
    balance -= amount;
    return amount;
}

//* Method - Display account's information
void Account::display()
{
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Balance: " << balance << endl;
    cout << endl;
}

////////////////////////
//? Bank class
////////////////////////

//* Method - Create account
void Bank::createAccount()
{
    //? Local variables
    string name;
    double balance;

    //? Taking input from user
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter balance: ";
    cin >> balance;

    //? Creating account object and pushing it to accounts vector
    Account account(name, balance);
    accounts.push_back(account);
}

//* Method - Display all accounts
void Bank::displayAllAccounts()
{
    //? Looping through all accounts and displaying them
    for (Account account : accounts)
        account.display();
}

//* Method - Transfer cash from one account to another
void Bank::transfer(Account from, Account to, double amount)
{
    //? Withdrawing cash from one account and depositing it to another account
    to.deposit(from.withdraw(amount));
}

//* Method - Get account by id
Account Bank::getAccount(int id)
{
    //? Looping through all accounts and returning the account with given id
    for (Account account : accounts)
        if (account.getId() == id)
            return account;
}
