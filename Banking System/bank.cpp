#include <iostream>

using namespace std;

// ? Global variables
int accountNumber = 0;
class Account {
    int id, balence;
}

////////////////
// Account
////////////////
class Account{
    //* Variables
    private:
        int id;
        string name;
        double balance;
    public:
        //* Constructor
        Account(string name, double balance){
            this->id = ++accountNumber;
            this->name = name;
            this->balance = balance;
        }
        //* Getters
        int getId(){
            return this->id;
        }
        string getName(){
            return this->name;
        }
        double getBalance(){
            return this->balance;
        }
        //* Setters
        void setName(string name){
            this->name = name;
        }
        void setBalance(double balance){
            this->balance = balance;
        }
        //* Methods
        void deposit(double amount){
            this->balance += amount;
        }
        void withdraw(double amount){
            if(this->balance - amount < 0){
                cout << "Insufficient funds" << endl;
            }else{
                this->balance -= amount;
            }
        }
        void display(){
            cout << "Account ID: " << this->id << endl;
            cout << "Name: " << this->name << endl;
            cout << "Balance: " << this->balance << endl;
        }
};

int main()
{
    Account talha_account("Talha", 5000);
    talha_account.deposit(500);
    talha_account.display();
}
