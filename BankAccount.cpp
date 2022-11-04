//Implementation of BankAccount Class
#include "BankSystem_Classes.h"

int BankAccount::fcinum = 0;

BankAccount::BankAccount() {
    string fcai = "FCAI-";
    accountID = fcai + to_string(fcinum);
    fcinum++;
    balance = 0;
    accounttype = "Bank Account";
}
BankAccount::BankAccount(double amount)
{
        string fcai = "FCAI-";
        accountID = fcai + to_string(fcinum);
        fcinum++;
        balance = amount;
        accounttype="Bank Account";
}
void BankAccount::setfci(int fcinum)
{
    this->fcinum =fcinum;
}
double BankAccount::getfci()
{
    return this->fcinum;
};
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
    return true;
}
double BankAccount::withdraw(double amount)
{
    if ( amount > balance){
        return false;
    }else {
        balance = balance - amount;
        return true;
    }
}