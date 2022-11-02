//Implementation of BankAccount Class
#include "BankSystem_Classes.h"

BankAccount::BankAccount()
{
    string fcai = "FCAI-";
    accountID = fcai + to_string(fcinum);
    fcinum++;
    balance = 0;
}
BankAccount::BankAccount(double amount)
{
    string fcai = "FCAI-";
    accountID = fcai + to_string(fcinum);
    fcinum++;
    balance = amount;
}
string BankAccount::getAccountID()
{
    return accountID;
}
string BankAccount::getAccounttype()
{
    return accounttype;
}
double BankAccount::getBalance()
{
    return balance;
}
void BankAccount::setAccountID(string accountID)
{
    this -> accountID = accountID;
}
void BankAccount::setAccounttype(string accounttype)
{
    this -> accounttype = accounttype;
}
void BankAccount::setBalance(double balance)
{
    this -> balance = balance;
}

double BankAccount::deposit(double amount)
{
    balance = amount + balance;
}
double BankAccount::withdraw(double amount)
{
    if ( amount > balance)
        cout << "Sorry,  can't do this - you balance is " << balance;
    else
        balance = balance - amount;
}